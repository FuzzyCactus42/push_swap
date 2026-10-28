/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:40:47 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 13:18:59 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_stack *s, t_bench *bench)
{
	if (!s || s->size < 2 || !bench)
		return ;
	swap_stack(s);
	bench->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, t_bench *bench)
{
	if (!b || b->size < 2 || !bench)
		return ;
	swap_stack(b);
	bench->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *s, t_stack *b, t_bench *bench)
{
	if ((!s || s->size < 2) || (!b || b->size < 2) || !bench)
		return ;
	swap_stack(s);
	swap_stack(b);
	bench->ss++;
	write(1, "ss\n", 3);
}
