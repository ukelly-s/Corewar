/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:55:56 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/31 04:55:58 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		free_cmd(void *data)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)data;
	free(cmd->mark[0]);
	free(cmd->mark[1]);
	free(cmd->mark[2]);
	free(cmd);
}

void			free_global_struct(void *data)
{
	t_parse	*g;

	g = (t_parse*)data;
	free(g->byte_str);
	free(g->header);
	free(g);
}

void			wrap_hashmap_free(void *data)
{
	t_hashmap	*info_mark;

	info_mark = (t_hashmap*)data;
	hashmap_destroy(&info_mark, free);
}

void			wrap_list_free(void *data)
{
	t_list	*info_operations;

	info_operations = (t_list*)data;
	list_clear(&info_operations, free_cmd);
}
