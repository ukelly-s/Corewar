/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:54:49 by slynell           #+#    #+#             */
/*   Updated: 2020/02/17 11:55:48 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "mem.h"
#include "ft_printf_.h"

static inline int	entry(register t_ptf_info *info)
{
	char	*plain_chars;

	while (*info->fmt)
	{
		plain_chars = (char*)info->fmt;
		while (*info->fmt && *info->fmt != '%')
			info->fmt++;
		do_print(info, plain_chars, info->fmt - plain_chars);
		if (!*info->fmt || !*(++info->fmt))
			break ;
		get_formatted_arg(info);
		if (*info->fmt == 0)
			break ;
		info->fmt++;
	}
	info->flush(info);
	return ((int)(info->printed > info->required_size
			? info->printed
			: info->required_size));
}

int					ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_ptf_info	info;
	int			ret;

	if (fd < 0 || fd > FD_SETSIZE)
		return (-1);
	ft_bzero(&info, sizeof(t_ptf_info));
	info.fd = fd;
	info.fmt = format;
	info.flush = &flush_in_file_stream;
	va_copy(info.ap, ap);
	ret = entry(&info);
	va_end(info.ap);
	return (ret);
}

int					ft_vsprintf(char *str, const char *format, va_list ap)
{
	t_ptf_info	info;
	int			ret;

	if (str == NULL)
		return (-1);
	ft_bzero(&info, sizeof(t_ptf_info));
	info.fmt = format;
	info.out = str;
	info.out_size = SIZE_MAX;
	info.flush = &flush_in_string;
	va_copy(info.ap, ap);
	ret = entry(&info);
	va_end(info.ap);
	return (ret);
}

int					ft_vsnprintf(char *str, size_t maxlen, const char *format,
					va_list ap)
{
	t_ptf_info	info;
	int			ret;

	if (str == NULL)
		return (-1);
	ft_bzero(&info, sizeof(t_ptf_info));
	info.fmt = format;
	info.out = str;
	info.out_size = maxlen;
	info.flush = &flush_in_string;
	va_copy(info.ap, ap);
	ret = entry(&info);
	va_end(info.ap);
	return (ret);
}
