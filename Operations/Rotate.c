/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 07:18:03 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 17:43:51 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size == 0 || stack->size == 1)
		return ;
	if (stack->size == 2)
	{
		temp = stack->top;
		stack->top = temp->next;
		temp->next = NULL;
		stack->top->next = temp;
		stack->bottom = temp;
	}
	else
	{
		temp = stack->top;
		stack->top = temp->next;
		temp->next = NULL;
		stack->bottom->next = temp;
		stack->bottom = temp;
	}
}

void	rotate_a(t_stack *a, t_counter *counter)
{
	if (!a || a->size < 2 || !counter)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
	counter->ra++;
}

void	rotate_b(t_stack *b, t_counter *counter)
{
	if (!b || b->size < 2 || !counter)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
	counter->rb++;
}

void	rr(t_stack *a, t_stack *b, t_counter *counter)
{
	if (!counter || ((!a || a->size < 2) && (!b || b->size < 2)))
		return ;
	rotate(a);
	rotate(b);
	counter->rr++;
	write(1, "rr\n", 3);
}
