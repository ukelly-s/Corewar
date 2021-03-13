/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:39:00 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 19:39:02 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "conv.h"
#include "str.h"
#include "util.h"
#include "op_struct.h"
#include "asm_errors.h"
#include "predicates.h"

static int		get_type_args(char c)
{
	if (c == DIRECT_CHAR)
		return (T_DIR);
	else if (c == REGISTER_CHAR)
		return (T_REG);
	else if (ft_isdigit(c) != 0 || c == '-' || c == LABEL_CHAR)
		return (T_IND);
	else
		ft_exit(1, ERR_INV_ARG_TYPE);
	return (0);
}

static void		check_valid_arg_value(char *str, t_cmd *cmd, int i)
{
	char	*tmp;

	tmp = str;
	if (*str == LABEL_CHAR)
		cmd->mark[i] = ft_strdup(++str);
	else
	{
		while (*str != '\0')
		{
			if (*str != '-' && ft_isdigit(*str) == 0)
				ft_exit(1, ERR_INV_CHAR);
			str++;
		}
		cmd->args_value[i] = ft_atol(tmp);
		if (cmd->args_types[i] == T_REG && (cmd->args_value[i] <= 0
			|| cmd->args_value[i] > REG_MAX))
			ft_exit(1, ERR_SYNTAX);
	}
}

static size_t	quantity_sep_char(char const *s, char c)
{
	size_t	separator_char;

	separator_char = 0;
	while (*s)
	{
		if (*s == c)
			separator_char++;
		s++;
	}
	return (separator_char);
}

static void		parse_args(char *str, t_cmd *cmd)
{
	char	**args;
	int		i;

	i = -1;
	if ((g_op[cmd->code].args_num != ft_words_count(str, SEPARATOR_CHAR))
		|| (ft_words_count(str, SEPARATOR_CHAR)
			- quantity_sep_char(str, SEPARATOR_CHAR)) != 1)
		ft_exit(1, ERR_LOTS_ARG);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	while (args[++i] != NULL)
	{
		cmd->args_types[i] = get_type_args(*args[i]);
		if (!(cmd->args_types[i] & g_op[cmd->code].args_types[i]))
			ft_exit(1, ERR_INV_ARG);
		if ((cmd->args_types[i] == T_REG && ft_isdigit(args[i][1]) != 0) ||
			(cmd->args_types[i] == T_DIR && (ft_isdigit(args[i][1]) != 0
						|| args[i][1] == '-' || args[i][1] == LABEL_CHAR)))
			check_valid_arg_value(&args[i][1], cmd, i);
		else if (cmd->args_types[i] == T_IND && (ft_isdigit(*args[i]) != 0
						|| *args[i] == '-' || *args[i] == LABEL_CHAR))
			check_valid_arg_value(&args[i][0], cmd, i);
		else
			ft_exit(1, ERR_INV_CHAR);
	}
	ft_free_split(args);
}

void			parse_operation(char *str, t_list *all_op, t_parse *g)
{
	register int		i;
	t_cmd				*list_cmd;
	static uint32_t		save_size_op;

	list_cmd = ft_memalloc(sizeof(t_cmd));
	i = get_number_operation(str);
	list_cmd->code = g_op[i].code;
	parse_args(str + ft_strlen(g_op[i].name) + 1, list_cmd);
	get_prog_size(list_cmd);
	save_size_op = list_cmd->size_op;
	list_cmd->size_op = g->header->prog_size;
	g->header->prog_size = list_cmd->size_op + save_size_op;
	list_push_back(all_op, list_cmd);
}
