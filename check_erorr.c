/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erorr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:29:26 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/19 14:40:51 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	count_strings(char **str)
{
	int i;
	int j;
	int count;

	j = 0;
	i = 0;
	count = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[j++] != '\0')
			count++;
		i++;
		count++;//for null terminator
	}
}
int check_erorr(char **str, int num_arg)
{
	int	i;
	char **p;
	char **p2;
	
	i = 1;
	while (i < num_arg)
	{
		p = ft_split(*str[i], " ");
		i++;
	}
	i = 0;
	p2 = malloc ((1 + count_strings(str) * sizeof (char)));//realocate for atoi
	while (i < num_arg)
	{
		fill_
	}
}
