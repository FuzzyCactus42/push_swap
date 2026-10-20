/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:40:47 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/20 11:59:50 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack-> top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void sa(t_stack	*s)
{
	if (!s || s->size < 2)
		return ;
	swap_stack(s);
	write(1,"sa\n",3);
}

void	sb(t_stack *b)
{
	if (!b || b->size < 2)
        return ;
    swap_stack(b);
    write(1,"sb\n",3);
}

void	ss(t_stack *s, t_stack *b)
{
	if ((!s || s->size < 2 ) && (!b || b->size < 2))
		return ;
	swap_stack(s);
	swap_stack(b);
	write(1,"ss\n",3);
}
