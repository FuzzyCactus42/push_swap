/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:30:54 by hhailat           #+#    #+#             */
/*   Updated: 2026/11/02 16:46:20 by hhailat          ###   ########.fr       */
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
		if (ft_atoi(r1[i], &r2[j++]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

static int	total_tokens(char **str, int argc)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ')
				j++;
			if (str[i][j])
				count++;
			while (str[i][j] && str[i][j] != ' ')
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

static int	collect_tokens(char **str, int argc, char **p, int start)
{
	int		k;
	int		j;
	char	**splt;

	k = 0;
	while (start < argc)
	{
		splt = ft_split(str[start++], ' ');
		if (!splt)
		{
			p[k] = NULL;
			return (ft_free(p));
		}
		j = 0;
		while (splt[j])
			p[k++] = splt[j++];
		free(splt);
	}
	p[k] = NULL;
	return (k);
}

int	str2int(char **str, int argc, int **out, int start)
{
	int		k;
	int		*p2;
	char	**p;

	p = malloc((total_tokens(str, argc) + 1) * sizeof(char *));
	if (!p)
		return (-1);
	k = collect_tokens(str, argc, p, start);
	if (k == -1)
		return (-1);
	p2 = malloc(k * sizeof(int));
	if (!p2)
		return (ft_free(p));
	if (fill_arr(p, p2) == -1)
	{
		free(p2);
		return (ft_free(p));
	}
	*out = p2;
	ft_free(p);
	return (k);
}
