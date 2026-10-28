/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:40:47 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 17:43:35 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	sa(t_stack *s, t_counter *counter)
{
	if (!s || s->size < 2 || !counter)
		return ;
	swap_stack(s);
	counter->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, t_counter *counter)
{
	if (!b || b->size < 2 || !counter)
		return ;
	swap_stack(b);
	counter->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *s, t_stack *b, t_counter *counter)
{
	if (!counter || ((!s || s->size < 2) && (!b || b->size < 2)))
		return ;
	swap_stack(s);
	swap_stack(b);
	counter->ss++;
	write(1, "ss\n", 3);
}
