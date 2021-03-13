/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:44:27 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 16:44:29 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_errors.h"
#include "util.h"
#include <fcntl.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <unistd.h>

static t_parse	*new_parse(void)
{
	t_parse	*g;

	g = ft_memalloc(sizeof(t_parse));
	ft_assert(g != NULL, __func__, "malloc error");
	ft_at_exit_ptr(free_global_struct, g, "Freeing header struct");
	g->name = FLAG_DEFAULT;
	g->comment = FLAG_DEFAULT;
	g->header = malloc(sizeof(t_header_asm));
	ft_assert(g->header != NULL, __func__, "malloc error");
	g->header->magic = rev_bytes(COREWAR_EXEC_MAGIC);
	return (g);
}

void			assembler(char *filename)
{
	int			fd;
	t_parse		*g;
	t_list		*info_operations;
	t_hashmap	*info_mark;

	g = new_parse();
	info_mark = hashmap_new();
	info_operations = list_new();
	ft_assert(info_mark != NULL && info_operations != NULL,
			__func__, "malloc error");
	ft_at_exit_ptr(wrap_list_free, info_operations, "Freeing ops list");
	ft_at_exit_ptr(wrap_hashmap_free, info_mark, "Freeing marks hashmap");
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_exit(1, ERR_OPEN_FILE);
	parse(fd, g, info_operations, info_mark);
	translation_bytecode(info_operations, info_mark, g);
	filename = replace_extension(filename, ".s", ".cor");
	if ((fd = open(filename, O_CREAT | O_TRUNC
										| O_WRONLY | O_APPEND, 0644)) == -1)
		ft_exit(1, ERR_CREATE_FILE);
	write(fd, g->header, sizeof(t_header_asm));
	g->header->prog_size = rev_bytes(g->header->prog_size);
	write(fd, g->byte_str, g->header->prog_size);
	ft_printf("Writing output program to %s\n", filename);
	ft_exit(EXIT_SUCCESS, "Program has finished successfully");
}
