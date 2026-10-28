
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:27:02 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/28 16:39:10 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	calc_chunck_size(t_stack *a)
{
	int	n;
	int	chunk_size;

	n = a->size;
	chunk_size = 1;
	while ((long)(chunk_size + 1) * (chunk_size + 1) <= n)
		chunk_size++;
	return (chunk_size);
}

static int	get_max_position(t_stack *b)
{
	t_node	*current;
	int		p;

	p = 0;
	current = b->top;
	while (current->index != b->size - 1)
	{
		current = current->next;
		p++;
	}
	return (p);
}

static void	push2a(t_stack *b, t_stack *a, t_bench *bench)
{
	int	p;

	while (b->size)
	{
		p = get_max_position(b);
		while (b->top->index != b->size - 1)
		{
			if (p <= b->size / 2)
				rotate_b(b, bench);
			else
				rrb(b, bench);
		}
		push_a(b, a, bench);
	}
}

void	chunck_based_algo(t_stack *a, t_stack *b, t_bench *bench)
{
	int	chunck_size;
	int	limit;

	if (!a || !b || !bench)
		return ;
	chunck_size = calc_chunck_size(a);
	limit = chunck_size;
	while (0 < a->size)
	{
		while (b->size < limit && a->top != NULL)
		{
			if (a->top->index < limit)
				push_b(a, b, bench);
			else
				rra(a, bench);
		}
		limit += chunck_size;
	}
		push2a(b, a, bench);
}
