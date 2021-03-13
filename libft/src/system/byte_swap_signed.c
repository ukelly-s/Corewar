/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_swap_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:42:52 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:42:54 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int16_t	byte_swap_s16(int16_t val)
{
	return ((val << 8) | ((val >> 8) & 0xFF));
}

int32_t	byte_swap_s32(int32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | ((val >> 16) & 0xFFFF));
}

int64_t	byte_swap_s64(int64_t val)
{
	val = ((val << 8) & 0xFF00FF00FF00FF00ULL)
		| ((val >> 8) & 0x00FF00FF00FF00FFULL);
	val = ((val << 16) & 0xFFFF0000FFFF0000ULL)
		| ((val >> 16) & 0x0000FFFF0000FFFFULL);
	return ((val << 32) | ((val >> 32) & 0xFFFFFFFFULL));
}
