/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 07:18:03 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/26 12:41:05 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_a(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2 || !b || b->size < 2)
		return ;
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
}
