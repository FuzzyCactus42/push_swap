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

int	ft_print_nbr(double i)
{
	int		len;
	long	s;
	int		temp;

	s = i;
	len = 0;
	if (s < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		len++;
		s = -s;
	}
	if (s >= 10)
	{
		temp = ft_print_nbr(s / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_print_char((s % 10) + '0');
	if (temp == -1)
		return (-1);
	return (len + temp);
}

int	ft_print_char(int c)
{
	int	temp;

	temp = write(1, &c, 1);
	if (temp == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	if (!s)
	{
		if (ft_print_char('(') == -1 || ft_print_char('n') == -1
			|| ft_print_char('u') == -1 || ft_print_char('l') == -1
			|| ft_print_char('l') == -1 || ft_print_char(')') == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		if (ft_print_char(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
