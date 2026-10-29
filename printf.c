/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 09:39:54 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 11:34:42 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_nbr(double i, int fd)
{
	int		len;
	long	s;
	int		temp;

	s = i;
	len = 0;
	if (s < 0)
	{
		if (ft_print_char('-', fd) == -1)
			return (-1);
		len++;
		s = -s;
	}
	if (s >= 10)
	{
		temp = ft_print_nbr(s / 10, fd);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_print_char((s % 10) + '0', fd);
	if (temp == -1)
		return (-1);
	return (len + temp);
}

int	ft_print_char(int c, int fd)
{
	int	temp;

	temp = write(fd, &c, 1);
	if (temp == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *s, int fd)
{
	int	i;

	if (!s)
	{
		if (ft_print_char('(', fd) == -1 || ft_print_char('n', fd) == -1
			|| ft_print_char('u', fd) == -1 || ft_print_char('l', fd) == -1
			|| ft_print_char('l', fd) == -1 || ft_print_char(')', fd) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		if (ft_print_char(s[i], fd) == -1)
			return (-1);
		i++;
	}
	return (i);
}
