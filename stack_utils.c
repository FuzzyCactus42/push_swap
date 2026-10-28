/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:06:04 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 17:00:33 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	append_value(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (-1);
	node->value = value;
	node->next = NULL;
	node->index = 0;
	if (stack->size == 0)
		stack->top = node;
	else
		stack->bottom->next = node;
	stack->bottom = node;
	stack->size++;
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
int fill_stack(t_stack *stack, int *values, int num_values)
{
	int	i;

	i = 0;
	while (i < num_values)
	{
		if (append_value(stack, values[i]) == -1)
		{
			free(values);
			return (-1);
		}
		i++;
	}
	free (values);
	return (1);
}
