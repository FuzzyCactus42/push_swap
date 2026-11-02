/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:05:30 by hhailat           #+#    #+#             */
/*   Updated: 2026/11/01 21:43:32 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_flags *flags, t_stack *a, t_stack *b)
{
	int		operations[OP_COUNT];
	int		operation;
	double	i;

	operation = 0;
	while (operation < OP_COUNT)
		operations[operation++] = 0;
	i = disorder(a);
	if (i != 0)
	{
		if (!ft_strncmp(flags->flag, "Simple", 7))
			simple(a, b, operations);
		else if (!ft_strncmp(flags->flag, "Complex", 8))
			complex(a, b, operations);
		else if (!ft_strncmp(flags->flag, "Medium", 7))
			medium(a, b, operations);
		else if ((adaptive(i)) == 1)
			simple(a, b, operations);
		else if ((adaptive(i)) == 2)
			medium(a, b, operations);
		else if ((adaptive(i)) == 3)
			complex(a, b, operations);
	}
	if (flags->is_bench)
		bench(i, flags->flag, operations);
}
