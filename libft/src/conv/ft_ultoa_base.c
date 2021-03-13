/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:02:04 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 19:02:06 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "str.h"

size_t	ft_ultoa_base(unsigned long long value, char *buff, const int base,
		const int is_upper)
{
	static const char	digits[] = "0123456789abcdef0123456789ABCDEF";
	register char		*ptr;
	size_t				ret;

	ptr = buff;
	*ptr++ = digits[(value % base) + (is_upper != 0) * 16];
	value /= base;
	while (value != 0)
	{
		*ptr++ = digits[(value % base) + (is_upper != 0) * 16];
		value /= base;
	}
	ft_strrev(buff, ptr - 1);
	ret = ptr - buff;
	buff[ret] = 0;
	return (ret);
}
