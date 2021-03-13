/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divmod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:33:21 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:33:22 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Calculates division result and remainder.
** @param [in] dividend Dividend.
** @param [in] divisor Divisor.
** @param [out] remainder Pointer to write the remainder.
** @return Division result.
** @ingroup math
*/

int			math_divmod(const int dividend, const int divisor, int *remainder)
{
	if (remainder)
		*remainder = dividend % divisor;
	return (dividend / divisor);
}

/*
** @copydoc math_divmod
*/

long		math_ldivmod(const long dividend, const long divisor,
			long *remainder)
{
	if (remainder)
		*remainder = dividend % divisor;
	return (dividend / divisor);
}

/*
** @copydoc math_divmod
*/

long long	math_lldivmod(const long long dividend, const long long divisor,
			long long *remainder)
{
	if (remainder)
		*remainder = dividend % divisor;
	return (dividend / divisor);
}
