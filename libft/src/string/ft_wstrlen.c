/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:38:24 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:38:26 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wctype.h>

size_t	ft_wstrlen(const wint_t *s)
{
	register size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len++;
#if WCHAR_MAX > 0xffff
		len += *s > 0xFFFF;

#endif

		len += *s > 0x7FF;
		len += *s > 0x7F;
		++s;
	}
	return (len);
}
