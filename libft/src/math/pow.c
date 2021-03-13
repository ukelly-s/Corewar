/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:34:08 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:34:09 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Raises the number @a base to the power of @a n
** @param [in] base Base.
** @param [in] n Power.
** @return The @a n-th power of @a base
** @ingroup math
*/

double		math_pow(const double base, const int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (math_pow(1 / base, -n));
	if (n & 1)
		return (base * math_pow(base, n - 1));
	return (math_pow(base * base, n / 2));
}

/*
** @copydoc math_pow
*/

float		math_fpow(const float base, const int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (math_fpow(1 / base, -n));
	if (n & 1)
		return (base * math_fpow(base, n - 1));
	return (math_fpow(base * base, n / 2));
}

/*
** @copydoc math_pow
*/

long double	math_lpow(const long double base, const int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (math_lpow(1 / base, -n));
	if (n & 1)
		return (base * math_lpow(base, n - 1));
	return (math_lpow(base * base, n / 2));
}
