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

static int	count_strings(char **str)
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
		while (str[i][j++] != '\0')
			count++;
		i++;
		count++;//for null terminator
	}
	return (count);
}

static void fill_arr(char **r1, char *r2)
{
	int	i;
	int j;
	int b;

	j = 0;
	i = 0;
	b = 0;
	while (r1[i] != NULL)
	{
		j = 0;
		while (r1[i][j] != '\0')
		{
			r2[b++] = r1[i][j++];
		}
		i++;
	}
	r2[b] = '\0';
}
int check_erorr(char **str, int num_arg)
{
	int	i;
	char **p;
	char *p2;
	
	i = 1;
	while (i < num_arg)
	{
		p = ft_split(str[i], ' ');
		i++;
	}
	i = 0;
	p2 = malloc ((1 + count_strings(str) * sizeof (char)));//realocate for atoi
	if (!p2)
		return(-1);
		fill_arr(p, p2);
		i++;
	return(1);
}
