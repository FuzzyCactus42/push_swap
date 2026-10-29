/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:20:27 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 17:52:59 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node   *find_min(t_stack *a, int *min_pos)
{
    t_node  *current;
    t_node  *min;
    int     i;

    current = a->top;
    min = current;
    *min_pos = 0;
    i = 0;
    while (current)
    {
        if (current->value < min->value)
        {
            min = current;
            *min_pos = i;
        }
        current = current->next;
        i++;
    }
    return (min);
}

void    simple(t_stack *a, t_stack *b, t_bench *bench)
{
    t_node  *min;
    int     min_pos;

    if (!a || !b || !bench)
        return ;
    while (a->size > 0)
    {
        min = find_min(a, &min_pos);
        if (min_pos <= a->size / 2)
        {
            while (a->top != min)
                rotate_a(a, bench);
        }
        else
        {
            while (a->top != min)
                rra(a, bench);
        }
        push_b(a, b, bench);
    }
    while (b->size > 0)
        push_a(b, a, bench);
}
