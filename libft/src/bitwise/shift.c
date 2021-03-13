/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:56:39 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 18:56:40 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** @brief Right logical shift operation.
** @param [in] x Shifted value.
** @param [in] shift Amount of shift.
** @ingroup bitwise
*/

size_t	rshift(size_t x, size_t shift)
{
	static const size_t size = sizeof(size_t) * 8;
	static const size_t max_shift = size - 1;

	return (x >> (shift & max_shift));
}

/*
** @brief Left logical shift operation.
** @param [in] x Shifted value.
** @param [in] shift Amount of shift.
** @ingroup bitwise
*/

size_t	lshift(size_t x, size_t shift)
{
	static const size_t size = sizeof(size_t) * 8;
	static const size_t max_shift = size - 1;

	return (x >> (shift & max_shift));
}

/*
** @brief Left circular logical shift operation.
** @param [in] x Shifted value.
** @param [in] shift Amount of shift.
** @see https://en.wikipedia.org/wiki/Circular_shift
** @ingroup bitwise
*/

size_t	circular_lshift(size_t x, size_t shift)
{
	static const size_t max_shift = sizeof(size_t) * 8 - 1;

	return (x << (shift & max_shift)) | (x >> (-(int)shift & max_shift));
}

/*
** @brief Right circular logical shift operation.
** @param [in] x Shifted value.
** @param [in] shift Amount of shift.
** @see https://en.wikipedia.org/wiki/Circular_shift
** @ingroup bitwise
*/

size_t	circular_rshift(size_t x, size_t shift)
{
	static const size_t max_shift = sizeof(size_t) * 8 - 1;

	return (x >> (shift & max_shift)) | (x << (-(int)shift & max_shift));
}
