/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:05:30 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/29 17:43:28 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_flags *flags, t_stack *a, t_stack *b)
{
	t_counter	counter;
	double		i;

	counter = (t_counter){0};
	i = disorder(a);
	if (!ft_strncmp(flags->flag, "Simple", 7))
		simple(a, b, &counter);
	else if (!ft_strncmp(flags->flag, "Complex", 8))
		complex(a, b, &counter);
	else if (!ft_strncmp(flags->flag, "Medium", 7))
		medium(a, b, &counter);
	else if ((adaptive(i)) == 1)
		simple(a, b, &counter);
	else if ((adaptive(i)) == 2)
		medium(a, b, &counter);
	else if ((adaptive(i)) == 3)
		complex(a, b, &counter);
	if (flags->is_bench)
		bench(i, flags->flag, &counter);
}
