/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:05:30 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/29 22:38:23 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	g_operations[OP_COUNT];

void	push_swap(t_flags *flags, t_stack *a, t_stack *b)
{
	int			operation;
	double		i;

	operation = 0;
	while (operation < OP_COUNT)
		g_operations[operation++] = 0;
	i = disorder(a);
	if (i != 0)//if its allready sorted it will skip these flags
	{
			if (!ft_strncmp(flags->flag, "Simple", 7))
			simple(a, b);
		else if (!ft_strncmp(flags->flag, "Complex", 8))
			complex(a, b);
		else if (!ft_strncmp(flags->flag, "Medium", 7))
			medium(a, b);
		else if ((adaptive(i)) == 1)
			simple(a, b);
		else if ((adaptive(i)) == 2)
			medium(a, b);
		else if ((adaptive(i)) == 3)
			complex(a, b);
	}
	if (flags->is_bench)
		bench(i, flags->flag);
}
