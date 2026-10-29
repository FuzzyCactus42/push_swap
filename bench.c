/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 09:35:32 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/29 17:23:36 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sum(t_counter *counter)
{
	int	result;

	result = counter->pa + counter->pb + counter->ra
		+ counter->rb + counter->rr + counter->rra + counter->rrb
		+ counter->rrr + counter->sa + counter->sb + counter->ss;
	return (result);
}

void	print_movement(t_counter *counter)
{
	ft_print_str("[bench] sa: ", 2);
	ft_print_nbr(counter->sa, 2);
	ft_print_str(" sb: ", 2);
	ft_print_nbr(counter->sb, 2);
	ft_print_str(" ss: ", 2);
	ft_print_nbr(counter->ss, 2);
	ft_print_str(" pa: ", 2);
	ft_print_nbr(counter->pa, 2);
	ft_print_str(" pb: ", 2);
	ft_print_nbr(counter->pb, 2);
	ft_print_str("\n[bench] ra: ", 2);
	ft_print_nbr(counter->ra, 2);
	ft_print_str(" rb: ", 2);
	ft_print_nbr(counter->rb, 2);
	ft_print_str(" rr: ", 2);
	ft_print_nbr(counter->rr, 2);
	ft_print_str(" rra: ", 2);
	ft_print_nbr(counter->rra, 2);
	ft_print_str(" rrb: ", 2);
	ft_print_nbr(counter->rrb, 2);
	ft_print_str(" rrr: ", 2);
	ft_print_nbr(counter->rrr, 2);
	write(2, "\n", 1);
}

static void	print_complexity(double inorder, char *flag)
{
	if (!ft_strncmp(flag, "Simple", 7)
		|| (!ft_strncmp(flag, "Adaptive", 9) && adaptive(inorder) == 1))
		ft_print_str(" / O(n^2)\n", 2);
	else if (!ft_strncmp(flag, "Medium", 7)
		|| (!ft_strncmp(flag, "Adaptive", 9) && adaptive(inorder) == 2))
		ft_print_str(" / O(n*sqrt(n))\n", 2);
	else
		ft_print_str(" / O(n log n)\n", 2);
}

void	bench(double inorder, char *flag, t_counter *counter)
{
	int	in;
	int	persint;

	in = (int)(inorder * 10000 + 0.5);
	persint = in % 100;
	in /= 100;
	ft_print_str("[bench] disorder: ", 2);
	ft_print_nbr(in, 2);
	write(2, ".", 1);
	if (persint < 10)
		write(2, "0", 1);
	ft_print_nbr(persint, 2);
	ft_print_str("%\n[bench] strategy: ", 2);
	ft_print_str(flag, 2);
	print_complexity(inorder, flag);
	ft_print_str("[bench] total_ops: ", 2);
	ft_print_nbr(sum(counter), 2);
	write(2, "\n", 1);
	print_movement(counter);
}
