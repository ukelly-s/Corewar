/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 05:58:20 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/10 05:58:22 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_STRUCT_H
# define OP_STRUCT_H
# include "op.h"
# include "mem.h"

typedef struct		s_op
{
	char			*name;
	t_byte			code;
	t_byte			args_num;
	int				args_types_code;
	t_byte			args_types[3];
	t_byte			dir_size;
	int				cycles;
	int				exec;
}					t_op;

static const t_op	g_op[17] = {
	{
		.name = "not_op",
		.code = 0x0,
		.args_num = 0,
		.args_types_code = 0,
		.args_types = {0, 0, 0},
		.dir_size = 0,
		.cycles = 0,
		.exec = 0
	},
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 4,
		.cycles = 10,
		.exec = 1
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.cycles = 5,
		.exec = 2
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.dir_size = 4,
		.cycles = 5,
		.exec = 3
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.cycles = 10,
		.exec = 4
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.cycles = 10,
		.exec = 5
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.cycles = 6,
		.exec = 6
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.cycles = 6,
		.exec = 7
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.cycles = 6,
		.exec = 8
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.cycles = 20,
		.exec = 9
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
		.cycles = 25,
		.exec = 10
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.dir_size = 2,
		.cycles = 25,
		.exec = 11
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.cycles = 800,
		.exec = 12
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.cycles = 10,
		.exec = 13
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
		.cycles = 50,
		.exec = 14
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.cycles = 1000,
		.exec = 15
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = 1,
		.args_types = {T_REG, 0, 0},
		.dir_size = 4,
		.cycles = 2,
		.exec = 16
	}
};

#endif
