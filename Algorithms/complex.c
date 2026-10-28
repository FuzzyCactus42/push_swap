/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:35:41 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 19:25:55 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	complex(t_stack *a, t_stack *b, t_counter *bench)
{
	int	max_bit;
	int	bit;
	int	size;

	if (!a || !b || a->size == 0 || !bench)
		return ;
	assign(a);
	max_bit = 0;
	while (((a->size - 1) >> max_bit) > 0)
		max_bit++;
	bit = 0;
	while (max_bit > bit)
	{
		size = a->size;
		while (size > 0)
		{
			if ((a->top->index >> bit) & 1)
				rotate_a(a, bench);
			else
				push_b(a, b, bench);
			size--;
		}
		while (b->size > 0)
			push_a(b, a, bench);
		bit++;
	}
}
