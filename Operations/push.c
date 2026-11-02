/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 06:53:37 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 17:43:42 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_node(t_stack *from, t_stack *to)
{
	t_node	*temp;

	temp = from->top;
	from->top = temp->next;
	from->size--;
	if (from->size == 0)
	{
		from->top = NULL;
		from->bottom = NULL;
	}
	if (to->size == 0)
	{
		temp->next = NULL;
		to->top = temp;
		to->bottom = temp;
	}
	else
	{
		temp->next = to->top;
		to->top = temp;
	}
	to->size++;
}

void	push_b(t_stack *a, t_stack *b, int *operations)
{
	if (!a || a->size == 0 || !b)
		return ;
	push_node(a, b);
	operations[OP_PB]++;
	write(1, "pb\n", 3);
}

void	push_a(t_stack *b, t_stack *a, int *operations)
{
	if (!b || b->size == 0 || !a)
		return ;
	push_node(b, a);
	operations[OP_PA]++;
	write(1, "pa\n", 3);
}
