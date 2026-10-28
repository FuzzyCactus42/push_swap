/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   R_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:26:05 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 17:43:47 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rivers_rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || stack->size < 2)
		return ;
	temp2 = stack->top;
	while (temp2->next != stack->bottom)
	{
		temp2 = temp2->next;
	}
	temp = stack->bottom;
	temp->next = stack->top;
	stack->top = temp;
	stack->bottom = temp2;
	stack->bottom->next = NULL;
}

void	rra(t_stack *a, t_counter *counter)
{
	if (!a || a->size < 2 || !counter)
		return ;
	rivers_rotate(a);
	counter->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b, t_counter *counter)
{
	if (!b || b->size < 2 || !counter)
		return ;
	rivers_rotate(b);
	counter->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, t_counter *counter)
{
	if (!counter || ((!a || a->size < 2) && (!b || b->size < 2)))
		return ;
	rivers_rotate(a);
	rivers_rotate(b);
	counter->rrr++;
	write(1, "rrr\n", 4);
}
