/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:39:05 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/26 11:07:25 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign(t_stack *a)
{
	t_node	*current;
	t_node	*compare;

	if (!a || a->size == 0)
		return ;
	current = a->top;
	while (current)
	{
		current->index = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->value < current->value)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}
