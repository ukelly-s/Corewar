/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clear_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:28:52 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 19:28:54 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_errors.h"
#include "str.h"
#include "util.h"

static int		len_clear_line(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t')
			i++;
		str++;
	}
	return (i);
}

static int		f_len_mark(char *str)
{
	int		j;

	j = 0;
	while (str[j] && str[j] != LABEL_CHAR)
	{
		if (str[j] == ' ' || str[j] == '\t')
			ft_exit(1, ERR_SYNTAX);
		j++;
	}
	return (j);
}

static char		*clear_line_operation(char **str)
{
	char	*line;
	int		len;
	int		check_space;
	int		i;
	int		j;

	i = 0;
	j = 0;
	check_space = 0;
	len = len_clear_line(*str) + 1;
	line = malloc(sizeof(char) * (len + 1));
	while (str[0][j] != '\0')
	{
		if (str[0][j] != ' ' && str[0][j] != '\t')
			line[i++] = str[0][j];
		if ((str[0][j] == ' ' || str[0][j] == '\t') && check_space++ == 0)
			line[i++] = ' ';
		j++;
	}
	line[i] = '\0';
	return (line);
}

static char		*clear_line_mark(char **str, int len)
{
	char			*line;
	register int	i;

	i = 0;
	line = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		line[i] = (*str)[i];
		(*str)[i] = ' ';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char			*clear_line(char **str)
{
	char	*line;
	char	*tmp;

	if ((tmp = ft_strchr(*str, COMMENT_CHAR)) != NULL ||
		(tmp = ft_strchr(*str, ALT_COMMENT_CHAR)) != NULL)
		ft_bzero(tmp, ft_strlen(tmp));
	if (!**str)
		line = ft_memalloc(1);
	else if (mark_operation_type(*str) == LINE_MARK)
	{
		line = clear_line_mark(str, (f_len_mark(*str) + 1));
		if (*(tmp = ft_strtrim(*str)) != '\0')
		{
			free(*str);
			*str = tmp;
			return (line);
		}
		free(tmp);
	}
	else
		line = clear_line_operation(str);
	free(*str);
	*str = NULL;
	return (line);
}
