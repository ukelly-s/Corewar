/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:27:08 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 20:27:09 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"
#include "vm.h"
#include "vm_exec.h"

static int	validate_args(t_cursor *cursor)
{
	int	i;

	i = -1;
	log_trace(__func__, "Cursor %d: validate args of operation '%s'",
		cursor->id, cursor->op->name);
	while (++i < cursor->op->args_num)
	{
		if (!(cursor->args_types[i] & cursor->op->args_types[i]))
		{
			log_trace(__func__, "Cursor %d: %dth arg: type %d is"
				" incorrect for operation '%s'",
				cursor->id, i + 1, cursor->args_types[i], cursor->op->name);
			return (0);
		}
		if (cursor->args_types[i] == T_REG
			&& (cursor->args[i] < 1 || cursor->args[i] > REG_NUMBER))
		{
			log_debug(__func__, "Cursor %d: %dth arg: register number %d"
				" is out of bounds [1 - %d]",
				cursor->id, i + 1, cursor->args[i], REG_NUMBER);
			return (0);
		}
	}
	return (1);
}

static void	fetch_opcode(t_cursor *cursor)
{
	t_byte	op_code;

	log_trace(__func__, "Cursor %d: fetch operation code", cursor->id);
	op_code = (t_byte)vm_load_mem(cursor->pc, OP_CODE_LEN);
	if (op_code > 0x10)
		cursor->op = (t_op *)&g_op[0];
	else
		cursor->op = (t_op *)&g_op[op_code];
	cursor->cycles_to_exec = cursor->op->cycles;
	log_debug(__func__, "Cursor %d: fetched operation '%s' (%#x)",
		cursor->id, cursor->op->name, cursor->op->code);
	cursor->step += OP_CODE_LEN;
}

static void	fetch_args_types(t_cursor *cursor)
{
	static const t_byte	types[4] = {0, T_REG, T_DIR, T_IND};
	static const char	*names[4] = {"NOT_ARG", "REG", "DIR", "IND"};
	int					args_types;
	int					arg_type;
	int					i;

	log_trace(__func__, "Cursor %d: fetch args types of operation '%s'",
		cursor->id, cursor->op->name);
	if (cursor->op->args_types_code == 0)
	{
		cursor->args_types[0] = cursor->op->args_types[0];
		log_trace(__func__, "Cursor %d: fetched arg type: %s",
			cursor->id, names[cursor->args_types[0]]);
		return ;
	}
	args_types = vm_load_mem(cursor->pc + cursor->step, ARGS_CODE_LEN);
	i = -1;
	while (++i < cursor->op->args_num)
	{
		arg_type = (args_types & (0xC0 >> (i * 2))) >> ((3 - i) * 2);
		cursor->args_types[i] = types[arg_type];
		log_trace(__func__, "Cursor %d: fetched %dth arg type: %s",
			cursor->id, i + 1, names[arg_type]);
	}
	cursor->step += ARGS_CODE_LEN;
}

static void	fetch_args(t_cursor *cursor)
{
	int		i;
	size_t	arg_len;

	log_trace(__func__, "Cursor %d: fetch args of operation '%s'",
		cursor->id, cursor->op->name);
	i = -1;
	while (++i < (int)cursor->op->args_num)
	{
		if (cursor->args_types[i] == T_REG)
			arg_len = REG_SELF_SIZE;
		else if (cursor->args_types[i] == T_IND)
			arg_len = IND_SELF_SIZE;
		else if (cursor->args_types[i] == T_DIR)
			arg_len = cursor->op->dir_size;
		else
			continue ;
		cursor->args[i] = vm_load_mem(cursor->pc + cursor->step, arg_len);
		cursor->args_pc[i] = cursor->pc;
		log_trace(__func__, "Cursor %d: fetched %dth arg: %d",
			cursor->id, i + 1, cursor->args[i]);
		cursor->step += arg_len;
	}
}

void		vm_exec(t_cursor *cursor)
{
	if (cursor->cycles_to_exec == 0)
		fetch_opcode(cursor);
	if (cursor->cycles_to_exec > 0)
	{
		cursor->cycles_to_exec--;
		log_trace(__func__, "Cursor %d: cycles to exec: %d",
			cursor->id, cursor->cycles_to_exec);
	}
	if (cursor->cycles_to_exec == 0)
	{
		if (cursor->op->code)
		{
			fetch_args_types(cursor);
			fetch_args(cursor);
			if (validate_args(cursor))
				g_exec[cursor->op->exec](cursor);
			else
				log_trace(__func__, "Cursor %d: skip operation with wrong args",
					cursor->id);
		}
		vm_cursor_move(cursor);
	}
}
