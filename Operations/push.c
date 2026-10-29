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
static t_node   *remove_top(t_stack *stack)
{
    t_node  *temp;

    temp = stack->top;
    stack->top = temp->next;
    stack->size--;
    if (stack->size == 0)
    {
        stack->top = NULL;
        stack->bottom = NULL;
    }
    return (temp);
}

static void add_top(t_stack *stack, t_node *temp)
{
    if (stack->size == 0)
    {
        temp->next = NULL;
        stack->top = temp;
        stack->bottom = temp;
    }
    else
    {
        temp->next = stack->top;
        stack->top = temp;
    }
    stack->size++;
}
void    push_b(t_stack *a, t_stack *b, t_bench *bench)
{
    t_node  *temp;

    if (!a || a->size == 0 || !bench || !b)
        return ;
    temp = remove_top(a);
    add_top(b, temp);
    bench->pb++;
    write(1, "pb\n", 3);
}

void    push_a(t_stack *b, t_stack *a, t_bench *bench)
{
    t_node  *temp;

    if (!b || b->size == 0 || !a || !bench)
        return ;
    temp = remove_top(b);
    add_top(a, temp);
    bench->pa++;
    write(1, "pa\n", 3);
}

