/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:53:50 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 17:53:51 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_EXEC_H
# define VM_EXEC_H

# include "op.h"
# include "mem.h"

struct s_cursor;
typedef void	(*t_exec)(struct s_cursor *);

void				op_live(struct s_cursor *cursor);
void				op_ld(struct s_cursor *cursor);
void				op_st(struct s_cursor *cursor);
void				op_add(struct s_cursor *cursor);
void				op_sub(struct s_cursor *cursor);
void				op_and(struct s_cursor *cursor);
void				op_or(struct s_cursor *cursor);
void				op_xor(struct s_cursor *cursor);
void				op_zjmp(struct s_cursor *cursor);
void				op_ldi(struct s_cursor *cursor);
void				op_sti(struct s_cursor *cursor);
void				op_fork(struct s_cursor *cursor);
void				op_lld(struct s_cursor *cursor);
void				op_lldi(struct s_cursor *cursor);
void				op_lfork(struct s_cursor *cursor);
void				op_aff(struct s_cursor *cursor);

static const t_exec	g_exec[17] = {
	NULL,
	op_live,
	op_ld,
	op_st,
	op_add,
	op_sub,
	op_and,
	op_or,
	op_xor,
	op_zjmp,
	op_ldi,
	op_sti,
	op_fork,
	op_lld,
	op_lldi,
	op_lfork,
	op_aff
};

#endif
