/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_endian_realisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:25:15 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 19:25:16 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

uint32_t		rev_bytes(uint32_t define)
{
	uint32_t	rev_dig;
	uint8_t		*col;
	uint8_t		*rev_col;

	col = (uint8_t *)&define;
	rev_col = (uint8_t *)&rev_dig;
	rev_col[0] = col[3];
	rev_col[1] = col[2];
	rev_col[2] = col[1];
	rev_col[3] = col[0];
	return (rev_dig);
}

void			get_to_4byte(t_byte *str, int32_t args_value)
{
	t_code4b	unite;

	unite.digit = args_value;
	str[0] = unite.letter[3];
	str[1] = unite.letter[2];
	str[2] = unite.letter[1];
	str[3] = unite.letter[0];
}

void			get_to_2byte(t_byte *str, int32_t args_value)
{
	t_code2b	unite;

	unite.digit = args_value;
	str[0] = unite.letter[1];
	str[1] = unite.letter[0];
}
