/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 06:53:37 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/26 09:46:52 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a || a->size == 0)
		return ;
	temp = a->top;
	a->top = temp->next;
	a->size--;
	if (a->size == 0)
	{
		a->top = NULL;
		a->bottom = NULL;
	}
	if (b->size == 0)
	{
		temp->next = NULL;
		b->top = temp;
		b->bottom = temp;
	}
	else
	{
		temp->next = b->top;
		b->top = temp;
	}
	b->size++;
	write(1, "pb\n", 3);
}

void	push_a(t_stack *b, t_stack *a)
{
	t_node	*temp;

	if (!b || b->size == 0 || !a)
		return ;
	temp = b->top;
	b->top = temp->next;
	b->size--;
	if (b->size == 0)
	{
		b->top = NULL;
		b->bottom = NULL;
	}
	if (a->size == 0)
	{
		temp->next = NULL;
		a->top = temp;
		a->bottom = temp;
	}
	else
	{
		temp->next = a->top;
		a->top = temp;
	}
	a->size++;
	write(1, "pa\n", 3);
}
