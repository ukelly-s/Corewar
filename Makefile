# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ukelly <ukelly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 20:40:53 by ukelly            #+#    #+#              #
#    Updated: 2020/11/26 21:08:20 by ukelly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
VM = corewar
LIBFT_A = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
SRC_DIR = source
OBJ_DIR = obj

INCLUDE = -I./include
INCLUDE += -I./libft/inc

HEADERS = include/asm.h
HEADERS += include/asm_errors.h
HEADERS += include/op.h
HEADERS += include/op_struct.h

HEADERS_VM = include/vm.h
HEADERS_VM += include/vm_exec.h
HEADERS_VM += include/vm_struct.h
HEADERS_VM += include/op.h
HEADERS_VM += include/op_struct.h


SRCS_ASM = assembler/asm.c
SRCS_ASM += assembler/asm_run.c
SRCS_ASM += assembler/parse.c
SRCS_ASM += assembler/util.c
SRCS_ASM += assembler/parse_name_comment.c
SRCS_ASM += assembler/parse_clear_line.c
SRCS_ASM += assembler/parse_operation.c
SRCS_ASM += assembler/parse_mark.c
SRCS_ASM += assembler/big_endian_realisation.c
SRCS_ASM += assembler/translation_bytecode.c
SRCS_ASM += assembler/free.c

SRCS_VM_VM = vm/vm_run.c
SRCS_VM_VM += vm/vm_options.c
SRCS_VM_VM += vm/vm_champion_load.c
SRCS_VM_VM += vm/vm_champion_read.c
SRCS_VM_VM += vm/vm_print.c
SRCS_VM_VM += vm/vm_options_logger.c
SRCS_VM_VM += vm/vm_cursor.c
SRCS_VM_VM += vm/vm_exec.c
SRCS_VM_VM += vm/vm_memory_access.c
SRCS_VM_VM += vm/vm_check.c

SRCS_VM_OP = op/op_live.c
SRCS_VM_OP += op/op_ld.c
SRCS_VM_OP += op/op_st.c
SRCS_VM_OP += op/op_and.c
SRCS_VM_OP += op/op_sub.c
SRCS_VM_OP += op/op_add.c
SRCS_VM_OP += op/util.c
SRCS_VM_OP += op/op_or.c
SRCS_VM_OP += op/op_xor.c
SRCS_VM_OP += op/op_zjmp.c
SRCS_VM_OP += op/op_ldi.c
SRCS_VM_OP += op/op_sti.c
SRCS_VM_OP += op/op_fork.c
SRCS_VM_OP += op/op_lld.c
SRCS_VM_OP += op/op_lldi.c
SRCS_VM_OP += op/op_lfork.c
SRCS_VM_OP += op/op_aff.c


SRCS_ASM_PATH = $(addprefix $(SRC_DIR)/, $(SRCS_ASM))
SRCS_VM_OP_PATH = $(addprefix $(SRC_DIR)/,$(SRCS_VM_OP))
SRCS_VM_VM_PATH = $(addprefix $(SRC_DIR)/,$(SRCS_VM_VM))


OBJS_VM_VM = $(SRCS_VM_VM:.c=.o)
OBJS_VM_OP = $(SRCS_VM_OP:.c=.o)
OBJS_ASM = $(SRCS_ASM:.c=.o)

OBJS_VM_VM_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_VM_VM))
OBJS_VM_OP_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_VM_OP))
OBJS_ASM_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_ASM))

.PHONY: clean fclean all re make_lib

all: $(ASM) $(VM)

$(LIBFT_A) : make_lib
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS_VM_VM_PATH))
	@mkdir -p $(dir $(OBJS_VM_OP_PATH))
	@mkdir -p $(dir $(OBJS_ASM_PATH))

make_lib :
	$(MAKE) -C $(LIBFT_DIR)

$(ASM): $(LIBFT_A) $(OBJS_ASM_PATH) $(HEADERS)
	$(CC) -o $@  $(OBJS_ASM_PATH) $(LIBFT_A) $(INCLUDE)

$(VM): $(LIBFT_A) $(OBJS_VM_OP_PATH)  $(OBJS_VM_VM_PATH) $(HEADERS_VM)
	$(CC) -o $@  $(OBJS_VM_OP_PATH) $(OBJS_VM_VM_PATH) $(LIBFT_A) $(INCLUDE)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS) $(HEADERS_VM) Makefile
	$(CC) -o $@ -c $< $(INCLUDE) $(FLAGS)

clean :
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) -rf $(ASM) $(VM)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all


.PHONY: clean fclean all re make_lib
