/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:27:02 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/28 14:02:56 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
static void	ranking(t_stack *a)
{
	t_node *current;
	t_node *compare;

	current = a->top;
	compare = a->top;
	while (current != NULL)
	{
		current->index = 0;
		while (compare)
		{
			if (compare->value < current->value)
				current->index++;
			compare = compare->next;
		}	
		current = current->next;
		compare = a->top;
	}
}
static int	calc_chunck_size(t_stack *a)
{
	int n;
	int	chunk_size;

	n = a->size;
	chunk_size = 1;
	while ((long)(chunk_size + 1) * (chunk_size + 1) <= n)
	    chunk_size++;
	return (chunk_size);
}
void	chunck_based_algo(t_stack *a, t_stack *b)
{
	int	chunck_size;
	int limt;

	chunck_size = calc_chunck_size(a);
	limt = chunck_size;
	while (limt < a->size)
	{
		while (!(b->size) != limt)
		{
			if (a->top->index < limt)
				push_b(a, b);
			else rra(a);
		}
	}
}