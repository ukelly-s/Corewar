/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moddiv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:33:42 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:33:44 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Calculates division result and remainder.
** @param [in] dividend Dividend.
** @param [in] divisor Divisor.
** @param [out] quotient Pointer to write the division result.
** @return Remainder of the division.
** @ingroup math
*/

int			math_moddiv(const int dividend, const int divisor, int *quotient)
{
	*quotient = dividend / divisor;
	return (dividend % divisor);
}

/*
** @copydoc math_moddiv
*/

long		math_lmoddiv(const long dividend, const long divisor,
			long *quotient)
{
	*quotient = dividend / divisor;
	return (dividend % divisor);
}

/*
** @copydoc math_moddiv
*/

long long	math_llmoddiv(const long long dividend, const long long divisor,
			long long *quotient)
{
	*quotient = dividend / divisor;
	return (dividend % divisor);
}
