/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   R_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:26:05 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/26 12:39:53 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	Rivers_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	Rivers_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	Rivers_rotate(a);
	Rivers_rotate(b);
	write(1, "rrr\n", 4);
}
