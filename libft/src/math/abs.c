/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:34:25 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:34:29 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Calculates absolute value of a number.
** @param [in] num Number to calculate.
** @return Absolute value of a number @a num.
** @ingroup math
*/

unsigned			math_abs(const int num)
{
	if (num > 0)
		return (num);
	return ((unsigned)~num + 1);
}

/*
** @copydoc math_abs
*/

unsigned long		math_labs(const long num)
{
	if (num > 0)
		return (num);
	return ((unsigned long)~num + 1);
}

/*
** @copydoc math_abs
*/

unsigned long long	math_llabs(const long long num)
{
	if (num > 0)
		return (num);
	return ((unsigned long long)~num + 1);
}
