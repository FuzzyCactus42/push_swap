/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:29:26 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/24 17:10:49 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_arr(char **r1, int *r2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (r1[i] != NULL)
	{
		if (ft_atoi(r1[i], &r2[j++]) == -1) // put str into int arr
			return (-1);
		i++;
	}
	return (1);
}

static int	total_tokens(char **str, int num_arg)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < num_arg) // ex: " 123 45 "
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ') // skip space: "   1" | skip spaces ("  4")
				j++;
			if (str[i][j]) // count (1) | count (2) | out
				count++;
			while (str[i][j] && str[i][j] != ' ') // skip 123 | skip 45
				j++;
		}
		i++;
	}
	return (count);
}

int	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (-1);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (-1);
}

int	str2int(char **str, int num_arg, int **out, int start)
{
	int		i;
	int		k;
	int		j;
	int		*p2;
	char	**p;
	char	**splt;

	i = start;
	k = 0;
	p = malloc((total_tokens(str, num_arg) + 1) * sizeof(char *));
	if (!p)
		return (-1);
	while (i < num_arg)
	{
		splt = ft_split(str[i++], ' ');
		if (!splt)
		{
			p[k] = NULL;//if it not NULL the ft_free will destroy the program
			return (ft_free(p));
		}
		j = 0;
		while (splt[j])
			p[k++] = splt[j++];
		free(splt);
	} // we end up with p -> arr of chars splitted
	p[k] = NULL;
	p2 = malloc(k * sizeof(int)); // realocate for atoi
	if (!p2)
		return (ft_free(p));
	if (fill_arr(p, p2) == -1)
	{
		free(p2);
		return (ft_free(p));
	}
	*out = p2;
	ft_free(p);
	return (k);// We want k to count elements
}
