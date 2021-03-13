/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:56:46 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 19:56:48 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_errors.h"
#include "array_list.h"
#include "str.h"
#include "util.h"
#include "predicates.h"
#include "op_struct.h"

t_line_type		mark_operation_type(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == SEPARATOR || str[i] == ALT_SEPARATOR)
			&& (str[i + 1] == SEPARATOR || str[i + 1] == ALT_SEPARATOR))
			;
		else if ((str[i] == SEPARATOR || str[i] == ALT_SEPARATOR)
				&& (str[i + 1] == '-' || str[i + 1] == '%' || str[i + 1] == 'r'
				|| ft_isdigit(str[i + 1]) == 1 || str[i + 1] == LABEL_CHAR))
			return (LINE_OPERATION);
		else if (ft_strchr(LABEL_CHARS, str[i]) == NULL && str[i] != LABEL_CHAR)
			ft_exit(1, ERR_INVALID_STRING);
		else if (str[i] == LABEL_CHAR)
			return (LINE_MARK);
		i++;
	}
	ft_exit(1, ERR_INVALID_STRING);
	return (LINE_UNDEFINED);
}

void			get_prog_size(t_cmd *cmd)
{
	int		i;

	i = 0;
	cmd->size_op++;
	if (g_op[cmd->code].args_types_code == 1)
		cmd->size_op++;
	while (i < g_op[cmd->code].args_num)
	{
		if ((cmd->args_types[i] & g_op[cmd->code].args_types[i]))
		{
			if (cmd->args_types[i] == T_REG)
				cmd->size_op++;
			else if (cmd->args_types[i] == T_IND)
				cmd->size_op += 2;
			else
				cmd->size_op += g_op[cmd->code].dir_size;
		}
		i++;
	}
}

char			*replace_extension(char *filename, char *file_extension_asm,
								char *file_extension_disasm)
{
	char	*new_file_name;
	char	*buff;
	size_t	len;

	len = ft_strlen(filename) - 2;
	buff = ft_strndup(filename, len);
	if (ft_strend(filename, file_extension_asm))
		new_file_name = ft_concat(2, buff, file_extension_disasm);
	else
		new_file_name = ft_concat(2, buff, file_extension_asm);
	ft_at_exit_ptr(free, new_file_name, "Freeing file name");
	free(buff);
	return (new_file_name);
}
