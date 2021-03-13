/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:56:10 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 18:56:12 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

#define ONES	((size_t)-1 / UCHAR_MAX)

/*
** @brief Determine if a @a word has a zero byte.
** @param [in] word Tested value.
** @ingroup bitwise
*/

size_t	get_mask(unsigned char masked)
{
	return (masked * ONES);
}
