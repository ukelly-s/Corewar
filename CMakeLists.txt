cmake_minimum_required(VERSION 3.17)
project(corewar C)

set(CMAKE_C_STANDARD 99)

#-pedantic -Wshadow -Werror

set(CMAKE_C_FLAGS " -Wall -Wextra ")

include_directories(includes include)
include_directories(includes libft/inc)

add_library(libft STATIC
		libft/inc/ft_printf.h
		libft/inc/array_list.h
		libft/inc/conv.h
		libft/inc/hash_map.h
		libft/inc/io_.h
		libft/inc/list.h
		libft/inc/math.h
		libft/inc/mem.h
		libft/inc/str.h
		libft/inc/util.h
		libft/inc/logger.h
		libft/inc/error.h
		libft/inc/system.h
		libft/src/array_list/arrlist_new.c
		libft/src/array_list/arrlist_peek.c
		libft/src/array_list/arrlist_pop.c
		libft/src/array_list/arrlist_push.c
		libft/src/array_list/arrlist_util.c
		libft/src/array_list/arrlisti_new.c
		libft/src/array_list/arrlisti_peek.c
		libft/src/array_list/arrlisti_pop.c
		libft/src/array_list/arrlisti_push.c
		libft/src/array_list/arrlisti_utils.c
		libft/src/conv/ft_atol.c
		libft/src/hash_map/hash_map_destroy.c
		libft/src/hash_map/hash_map_get.c
		libft/src/hash_map/hash_map_iterate.c
		libft/src/hash_map/hash_map_new.c
		libft/src/hash_map/hash_map_put.c
		libft/src/hash_map/hash_map_resize.c
		libft/src/hash_map/hash_map_utils.c
		libft/src/io/ft_putendl.c
		libft/src/io/ft_putnbr.c
		libft/src/io/ft_putstr.c
		libft/src/io/get_next_line.c
		libft/src/list/list_clear.c
		libft/src/list/list_new.c
		libft/src/list/list_pop.c
		libft/src/list/list_push.c
		libft/src/math/min.c
		libft/src/math/abs.c
		libft/src/math/max.c
		libft/src/math/divmod.c
		libft/src/math/moddiv.c
		libft/src/math/pow.c
		libft/src/math/sqrt.c
		libft/src/math/numlen.c
		libft/src/mem/memalloc.c
		libft/src/mem/memchr.c
		libft/src/mem/memcmp.c
		libft/src/mem/memcpy.c
		libft/src/mem/memmem.c
		libft/src/mem/memset.c
		libft/src/mem/memswap.c
		libft/src/string/ft_chars_count.c
		libft/src/string/ft_free_split.c
		libft/src/string/ft_isint.c
		libft/src/string/ft_strchr.c
		libft/src/string/ft_strdup.c
		libft/src/string/ft_strequ.c
		libft/src/string/ft_strnequ.c
		libft/src/string/ft_strjoin.c
		libft/src/string/ft_strlen.c
		libft/src/string/ft_strndup.c
		libft/src/string/ft_strnlen.c
		libft/src/string/ft_strsplit.c
		libft/src/string/ft_words_count.c
		libft/src/string/ft_concat.c
		libft/src/string/ft_strany.c
		libft/src/string/ft_strrev.c
		libft/src/string/ft_wstrlen.c
		libft/src/string/ft_strstart.c
		libft/src/string/ft_strend.c
		libft/src/util/ft_assert.c
		libft/src/util/ft_kill.c
		libft/src/util/ft_log_error.c
		libft/src/util/ft_exit.c
		libft/src/system/ft_path.c
		libft/src/system/endian.c
		libft/src/system/byte_swap_unsigned.c
		libft/src/system/byte_swap_signed.c
		libft/src/logger/logger_.h
		libft/src/logger/logger.c
		libft/src/logger/logger_appenders.c
		libft/src/logger/logger_config.c
		libft/src/logger/logger_log.c
		libft/src/logger/logger_log_alias.c
		libft/src/conv/ft_atol.c
		libft/src/conv/ft_ultoa_base.c
		libft/src/conv/ft_uitoa_dec.c
		libft/src/conv/ft_uitoa_hex.c
		libft/src/conv/ft_ultoa_hex.c
		libft/inc/bitwise.h
		libft/src/bitwise/hasbyte.c
		libft/src/bitwise/mask.c
		libft/src/bitwise/operations.c
		libft/src/bitwise/shift.c
		libft/src/io/ft_printf/buffered_printer.c
		libft/src/io/ft_printf/float_processing.c
		libft/src/io/ft_printf/float_processing_ag.c
		libft/src/io/ft_printf/float_processing_ef.c
		libft/src/io/ft_printf/float_processing_fast_ldtoa.c
		libft/src/io/ft_printf/float_processing_fast_dtoa.c
		libft/src/io/ft_printf/float_processing_fxd_dbl.c
		libft/src/io/ft_printf/ft_printf_alias.c
		libft/src/io/ft_printf/ft_printf_.c
		libft/src/io/ft_printf/ft_printf_.h
		libft/src/io/ft_printf/ft_printf_const_data.h
		libft/src/io/ft_printf/ft_printf_utils.c
		libft/src/io/ft_printf/get_format_arg.c
		libft/src/io/ft_printf/number_processing.c
		libft/src/io/ft_printf/string_processing.c

		libft/src/util/ft_log_error.c

		libft/inc/predicates.h
		libft/src/predicates/ft_isalnum.c
		libft/src/predicates/ft_isalpha.c
		libft/src/predicates/ft_isascii.c
		libft/src/predicates/ft_isdigit.c
		libft/src/predicates/ft_isprint.c
		libft/src/predicates/ft_isspace.c

		libft/src/string/ft_strtrim.c libft/src/string/strbuilder_.h
		)

set_target_properties(libft PROPERTIES PUBLIC_HEADER
		libft/inc/array_list.h
		libft/inc/conv.h
		libft/inc/hash_map.h
		libft/inc/io_.h
		libft/inc/list.h
		libft/inc/math.h
		libft/inc/mem.h
		libft/inc/str.h
		libft/inc/util.h)

add_executable(corewar $<TARGET_OBJECTS:libft>
		source/vm/vm_options.c
		source/vm/vm_champion_load.c
		source/vm/vm_champion_read.c
		source/vm/vm_print.c
		source/vm/vm_options_logger.c
		source/vm/vm_run.c
		source/vm/vm_cursor.c
		source/vm/vm_exec.c
		source/vm/vm_memory_access.c
		source/vm/vm_check.c
		source/op/op_live.c
		source/op/op_ld.c
		source/op/op_st.c
		source/op/op_and.c
		source/op/op_sub.c
		source/op/op_add.c
		source/op/util.c
		source/op/op_or.c
		source/op/op_xor.c
		source/op/op_zjmp.c
		source/op/op_ldi.c
		source/op/op_sti.c
		source/op/op_fork.c
		source/op/op_lld.c
		source/op/op_lldi.c
		source/op/op_lfork.c
		source/op/op_aff.c)


add_executable(Asssembler $<TARGET_OBJECTS:libft>
		source/assembler/asm_run.c
        source/assembler/parse.c
        source/assembler/asm.c
        source/assembler/util.c
        source/assembler/parse_name_comment.c
        source/assembler/parse_clear_line.c
        source/assembler/parse_operation.c
        source/assembler/parse_mark.c
		source/assembler/translation_bytecode.c
        source/assembler/big_endian_realisation.c
		source/assembler/free.c)
