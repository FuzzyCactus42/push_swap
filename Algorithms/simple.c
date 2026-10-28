/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:20:27 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 17:52:59 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple(t_stack *a, t_stack *b, t_counter *bench)
{
	t_node	*current;
	t_node	*min;

	if (!a || !b || !bench)
		return ;
	while (a->size != 0)
	{
		current = a->top;
		min = current;
		while (current)
		{
			if (min->value > current->value)
				min = current;
			current = current->next;
		}
		while (a->top != min)
			rotate_a(a, bench);
		push_b(a, b, bench);
	}
	while (b->size > 0)
		push_a(b, a, bench);
}
