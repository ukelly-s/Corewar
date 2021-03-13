/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:56:20 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 18:56:21 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** @brief AND operation.
** @param [in] x Operand.
** @param [in] y Operand.
** @ingroup bitwise
*/

size_t	and(size_t x, size_t y)
{
	return (x & y);
}

/*
** @brief OR operation.
** @param [in] x Operand.
** @param [in] y Operand.
** @ingroup bitwise
*/

size_t	or(size_t x, size_t y)
{
	return (x | y);
}

/*
** @brief XOR operation.
** @param [in] x Operand.
** @param [in] y Operand.
** @ingroup bitwise
*/

size_t	xor(size_t x, size_t y)
{
	return (x ^ y);
}

/*
** @brief NOT operation.
** @param [in] x Operand.
** @ingroup bitwise
*/

size_t	not(size_t x)
{
	return (~x);
}
