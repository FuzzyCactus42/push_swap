/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 07:14:26 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/27 09:08:02 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
double	disorder(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		inorder;

	if (!a || a->size < 2)
		return (0.0);
	current = a->top;
	inorder = 0;
	while(current)
	{
		compare = current->next;

		while(compare)
		{
			if (compare->value < current->value)
				inorder++;
			compare = compare->next;
		}
		current = current->next;
	}
	return((inorder *100.0) / ((a->size*(a->size - 1))/2.0));
}
