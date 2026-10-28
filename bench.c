/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 09:35:32 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 20:01:13 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench(double inorder, char *flag)
{
	int	in;
	float	persint;

	in = inorder * 100;
	persint = (int)((inorder * 100 - in) * 100);
	write(1, "disorder:\t", 10);
	ft_print_nbr(in);
	write(1, ".", 1);
	ft_print_nbr(persint);
	write(1, "\n", 1);
	ft_print_str(flag);
}
