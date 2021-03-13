/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 05:57:18 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/10 05:57:20 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define SEPARATOR			' '
# define ALT_SEPARATOR		'\t'
# define ALT_COMMENT_CHAR	';'
# define REGISTER_CHAR		'r'
# define REG_MAX			99

# define ARG_REG			0b01000000
# define ARG_DIR			0b10000000
# define ARG_IND			0b11000000

# include "list.h"
# include "op.h"
# include "hash_map.h"
# include "list.h"
# include "mem.h"

/*
** lexer
*/

typedef enum		e_name_comment_flags
{
	FLAG_DEFAULT,
	FLAG_NAME,
	FLAG_COMMENT
}					t_name_comment_flags;

typedef enum		e_line_type
{
	LINE_UNDEFINED,
	LINE_EMPTY,
	LINE_NAME,
	LINE_COMMENT,
	LINE_OPERATION,
	LINE_MARK
}					t_line_type;

typedef struct		s_cmd
{
	uint8_t			code;
	uint8_t			args_types[3];
	int32_t			args_value[3];
	char			*mark[3];
	uint32_t		size_op;
}					t_cmd;

typedef union		u_code4b
{
	int32_t			digit;
	uint8_t			letter[4];
}					t_code4b;

typedef union		u_code2b
{
	int16_t			digit;
	uint8_t			letter[2];
}					t_code2b;

typedef struct		s_parse
{
	int				name;
	int				comment;
	t_header_asm	*header;
	t_byte			*byte_str;
}					t_parse;

/*
** asm.c
*/
void				assembler(char *filename);

/*
** big_endian_realisation.c
*/

uint32_t			rev_bytes(uint32_t define);
void				get_to_4byte(t_byte *str, int32_t args_value);
void				get_to_2byte(t_byte *str, int32_t args_value);

/*
** parse.c
*/

int					get_number_operation(const char *str);
int					get_line(int fd, char **line);
void				parse(int fd, t_parse *g, t_list *info_operations,
						t_hashmap *info_mark);

/*
** parse_clear_line.c
*/

char				*clear_line(char **str);

/*
** libft
*/

char				*ft_strtrim(char const *s);

/*
** parse_mark.c
*/

void				parse_mark(char *str, t_hashmap *info_mark, t_parse *g);

/*
** parse_name_comment.c
*/

void				parse_comment(char *str, t_parse *g);
void				parse_name(char *str, t_parse *g);

/*
** parse_operation.c
*/

void				parse_operation(char *str, t_list *all_op, t_parse *g);

/*
** translation_bytecode
*/
void				translation_bytecode(t_list *operations,
										t_hashmap *mark, t_parse *g);

/*
** util.c
*/

t_line_type			mark_operation_type(const char *str);
void				get_prog_size(t_cmd *cmd);
char				*replace_extension(char *filename, char *file_extension_asm,
									char *file_extension_disasm);

/*
** free.c
*/

void				free_global_struct(void *data);
void				wrap_hashmap_free(void *data);
void				wrap_list_free(void *data);

#endif
