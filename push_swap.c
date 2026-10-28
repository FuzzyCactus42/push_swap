/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:05:30 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/28 17:14:38 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char *flag, t_stack *a, t_stack *b)
{
	
	if (!ft_strncmp(flag[0], "--simple", 9))
		simple(a, b, bench);
	if (!ft_strncmp(flag[0], "--complex", 10))
		complix(a, b, bench);
	if (!ft_strncmp(flag[0], "--medium", 9))
		medium(a, b, bench);
	if (!ft_strncmp(flag[0], "--bench", 8))
		
		
}