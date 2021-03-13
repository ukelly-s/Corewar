/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:34:59 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 19:35:00 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_errors.h"
#include "str.h"
#include "util.h"

static void		check_excess_information(char *str)
{
	char	*buff;

	buff = ft_strchr(ft_strchr(str, '"') + 1, '"') + 1;
	while (*buff != '\0')
	{
		if (*buff == COMMENT_CHAR || *buff == ALT_COMMENT_CHAR)
		{
			ft_bzero(buff, ft_strlen(buff));
			break ;
		}
		if (*buff != SEPARATOR && *buff != ALT_SEPARATOR)
			ft_exit(1, ERR_NAME_COMMENT);
		buff++;
	}
}

void			parse_comment(char *str, t_parse *g)
{
	int		len;
	int		i;
	char	*buff;

	i = 0;
	check_excess_information(str);
	buff = ft_strchr(str, '"') + 1;
	if ((len = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '"')))
		> COMMENT_LENGTH)
		ft_exit(1, ERR_COM_LEN);
	while (i < len)
		g->header->comment[i++] = *buff++;
}

void			parse_name(char *str, t_parse *g)
{
	int		len;
	int		i;
	char	*buff;

	i = 0;
	check_excess_information(str);
	buff = ft_strchr(str, '"') + 1;
	if ((len = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '"')))
		> PROG_NAME_LENGTH)
		ft_exit(1, ERR_PROG_NAME_LEN);
	while (i < len)
		g->header->prog_name[i++] = *buff++;
}
