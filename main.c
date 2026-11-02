/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:51:33 by hhailat           #+#    #+#             */
/*   Updated: 2026/11/02 16:47:50 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_erorr(void)
{
	write(2, "Error\n", 6);
}

static int	prepare_stack(t_stack *a, int argc, char **argv, t_flags *flags)
{
	int	i;
	int	int_elements;
	int	*int_arr;

	int_arr = NULL;
	i = flags->num_bench + flags->num_flags + 1;
	int_elements = str2int(argv, argc, &int_arr, i);
	if (int_elements == -1 || check_dup_erorr(int_arr, int_elements) == -1)
	{
		free(int_arr);
		return (-1);
	}
	if (int_elements <= 5)
		flags->flag = "Simple";
	return (fill_stack(a, int_arr, int_elements));
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_flags	flags;

	if (argc <= 1)
		return (0);
	if (read_flags(argv, argc, &flags) == -1)
	{
		print_erorr();
		return (-1);
	}
	init_stack(&a);
	init_stack(&b);
	if (prepare_stack(&a, argc, argv, &flags) == -1)
	{
		print_erorr();
		free_stack(&a);
		return (-1);
	}
	push_swap(&flags, &a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
