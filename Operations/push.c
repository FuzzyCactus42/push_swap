/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 06:53:37 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 15:27:24 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*temp;

	if (!a || a->size == 0 || !bench || !b)
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
	bench->pb++;
	write(1, "pb\n", 3);
}

void	push_a(t_stack *b, t_stack *a, t_bench *bench)
{
	t_node	*temp;

	if (!b || b->size == 0 || !a || !bench)
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
	bench->pa++;
	write(1, "pa\n", 3);
}
