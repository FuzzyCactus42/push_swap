/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:05:30 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/28 17:59:10 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_flags *flags, t_stack *a, t_stack *b)
{
	t_counter counter = {0};
	
	if (!ft_strncmp(flags->flag, "--simple", 9))
		simple(a, b, &counter);
	else if (!ft_strncmp(flags->flag, "--complex", 10))
		complix(a, b, &counter);
	else if (!ft_strncmp(flags->flag, "--medium", 9))
		medium(a, b, &counter);
	else adaptive(disorder(a));
	if (flags->is_bench)
		bench(disorder(a), flags->flag);
}