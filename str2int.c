/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:30:54 by hhailat           #+#    #+#             */
/*   Updated: 2026/11/02 13:41:35 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Convert each token to an integer, rejecting invalid or out-of-range values.
*/
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

/*
** Count space-separated tokens in all arguments after the program name.
** Ignore repeated spaces and skip to the end of each counted token.
*/
static int	total_tokens(char **str, int num_arg)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < num_arg)
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

/*
** Collect tokens from arguments starting at start in a NULL-terminated array.
** Terminate partial token lists before cleanup if splitting fails.
*/
static int	collect_tokens(char **str, int num_arg, char **p, int start)
{
	int		k;
	int		j;
	char	**splt;

	k = 0;
	while (start < num_arg)
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

/*
** Allocate the integer array, convert the tokens, and free temporary strings.
** On success, store the array in *out and return its length.
** Return -1 on failure.
*/
int	str2int(char **str, int num_arg, int **out, int start)
{
	int		k;
	int		*p2;
	char	**p;

	p = malloc((total_tokens(str, num_arg) + 1) * sizeof(char *));
	if (!p)
		return (-1);
	k = collect_tokens(str, num_arg, p, start);
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
