/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:35:41 by sallawne          #+#    #+#             */
/*   Updated: 2026/11/02 15:18:51 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix_pass(t_stack *a, t_stack *b, int bit, int *operations)
{
	int	size;

	size = a->size;
	while (size > 0)
	{
		if ((a->top->index >> bit) & 1)
			rotate_a(a, operations);
		else
			push_b(a, b, operations);
		size--;
	}
	while (b->size > 0)
		push_a(b, a, operations);
}

void	complex(t_stack *a, t_stack *b, int *operations)
{
	int	max_bit;
	int	bit;

	if (!a || !b || a->size == 0)
		return ;
	rank(a);
	max_bit = 0;
	while (((a->size - 1) >> max_bit) > 0)
		max_bit++;
	bit = 0;
	while (max_bit > bit)
	{
		radix_pass(a, b, bit, operations);
		bit++;
	}
}
