/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mark.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:30:12 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 19:30:15 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <util.h>
#include <error.h>
#include "asm_errors.h"
#include "asm.h"
#include "hash_map.h"
#include "list.h"
#include "str.h"

void	parse_mark(char *str, t_hashmap *info_mark, t_parse *g)
{
	int	*mark_pos;

	if (*str == ':')
		ft_exit(1, ERR_INV_VAL);
	if (hashmap_get(info_mark, str, ft_strlen(str) - 1) != NULL)
		return ;
	mark_pos = malloc(sizeof(int));
	ft_assert(mark_pos != NULL, __func__, E_ALLOC);
	*mark_pos = (int)g->header->prog_size;
	hashmap_put(info_mark, str, ft_strlen(str) - 1, mark_pos);
}
