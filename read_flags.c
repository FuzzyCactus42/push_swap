/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:47:36 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/26 11:51:16 by hhailat          ###   ########.fr       */
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
static void initialize_flags(t_flags *flags)
{
	flags->num_flags = 0;
	flags->num_bench = 0;
	flags->flag = "--adaptive";
	flags->bench = false;
}
static int	check_flags_error(char **str, int num_args, t_flags *flags)
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
		if (check_flags(str[i], &flags->num_flags, &flags->num_bench) == -1)
			return (-1);
		if (flags->num_flags >= 2 || flags->num_bench >= 2)
			return (-1);
		i++;
	}
	return (1);
}//atoi will check the characters
int	read_flags(char **str, int num_args, t_flags *flags)
{
	int i;

	initialize_flags(flags);
	i = 1;
	if (check_flags_error(str, num_args, flags) == -1)
		return (-1);
	while (i < num_args)
	{
		if (!ft_strncmp(str[i], "--adaptive", 11))
			flags->flag = "--adaptive";
		else if (!ft_strncmp(str[i], "--medium", 9))
			flags->flag = "--medium";
		else if (!ft_strncmp(str[i], "--complex", 10))
			flags->flag = "--complex";
		else if (!ft_strncmp(str[i], "--simple", 9))
			flags->flag = "--simple";
		else if (!ft_strncmp(str[i], "--bench", 8))
			flags->bench = true;
		i++;
	}
	return (1);
}