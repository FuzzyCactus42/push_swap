/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erorr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:47:36 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/24 16:26:43 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
		}
		if (str[i] == '\0')
			return (1);
		else
			return (0);
	}
	return (1);
}

static int	check_flags(char *str, int *flags, int *bench)
{
	if (!ft_strncmp(str, "--bench", 8))
	{
		(*bench)++;
		return (1);
	}
	else if (!ft_strncmp(str, "--simple", 9)
		|| !ft_strncmp(str, "--complex", 10)
		|| !ft_strncmp(str, "--medium", 9)
		|| !ft_strncmp(str, "--adaptive", 11))
	{
		(*flags)++;
		return (1);
	}
	else if (!ft_strncmp(str, "--", 2))
		return (-1);
	else
		return (0);
}

int	check_flags_error(char **str, int num_args, int *flags, int *bench)
{
	int	i;

	i = 1;
	while (i < num_args)
	{
		if (check_empty(str[i]))
			return (-1);
		i++;
	}
	i = 1;
	while (i < num_args)
	{
		if (check_flags(str[i], flags, bench) == -1)
			return (-1);
		if (*flags >= 2 || *bench >= 2)
			return (-1);
		i++;
	}
	return (1);
}