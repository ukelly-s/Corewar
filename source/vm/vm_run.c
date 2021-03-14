/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:26:40 by ukelly            #+#    #+#             */
/*   Updated: 2021/03/13 20:26:43 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io_.h"
#include "str.h"
#include "conv.h"
#include "util.h"
#include "vm.h"

static void	vm_dump(void)
{
	char *user_input;

	print_arena();
	if (g_vm.config & VM_STEP_DUMP)
	{
		if (get_next_line(0, &user_input) == -1)
			ft_exit(EXIT_FAILURE, "Reading from STDIN is failed");
		log_info(__func__, "User input: '%s'", user_input);
		if (ft_isuint(user_input))
			g_vm.dump_cycle += (int)ft_atol(user_input);
		else
			g_vm.dump_cycle += g_vm.dump_cycle;
		return ;
	}
	ft_exit(EXIT_SUCCESS, "Stop Corewar Virtual Machine after dump");
}

static void	vm_cycle(void)
{
	register t_list_node	*node;

	g_vm.cycles++;
	g_vm.cycles_after_check++;
	log_info(__func__, "_______ Cycle %d _______", g_vm.cycles);
	if (g_vm.config & VM_VERBOSE_CYCLE)
		verbose_cycle();
	node = g_vm.cursors->front;
	while (node)
	{
		vm_exec((t_cursor *)node->data);
		node = node->next;
	}
}

static void	vm_run(void)
{
	log_info(__func__, "Run Corewar Virtual Machine");
	vm_cursor_set_initial();
	print_intro();
	g_vm.cycles_to_die = CYCLE_TO_DIE;
	while (g_vm.cursors->size)
	{
		if (g_vm.config & VM_DUMP && g_vm.dump_cycle == g_vm.cycles)
			vm_dump();
		vm_cycle();
		if (g_vm.cycles_to_die == g_vm.cycles_after_check
			|| g_vm.cycles_to_die <= 0)
			vm_check();
	}
	print_winner();
	log_info(__func__, "Stop Corewar Virtual Machine");
}

int			main(int ac, char **av)
{
	if (ac < 2)
	{
		print_usage();
		return (0);
	}
//	logger_switch_flags(L_STD_CFG, L_DISABLE);
	logger_switch_flags(L_USE_STDOUT, L_ENABLE);
	logger_set_log_lvl(ERROR);
	logger_set_app_log_lvl(L_STDOUT, ALL);
	ft_bzero(&g_vm, sizeof(t_vm));
	if (!vm_options(ac, av))
		ft_exit(EXIT_FAILURE, "Resolving arguments failed");
	if (g_vm.champ_size == 0)
		ft_exit(EXIT_FAILURE, "No champions");
	if (!vm_load_champions(ac, av))
		ft_exit(EXIT_FAILURE, "Loading champions failed");
	vm_run();
	ft_exit(0, "Success");
}
