/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:20:27 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/26 16:39:23 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	simple(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*min;

	if (!a || !b)
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
			rotate_a(a);
		push_b(a, b);
	}
	while (b->size > 0)
		push_a(b, a);
}
