/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 09:25:23 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/19 09:25:31 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	the_start_of_num(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] != '\0')
	{
		if (nptr[i] == '+' || nptr[i] == '-' || (nptr[i] >= '0'
				&& nptr[i] <= '9'))
			return (i);
		if (nptr[i] != ' ' && (nptr[i] < 9 || nptr[i] > 13))
			return (-1);
		i++;
	}
	return (i);
}

static int	get_sign(const char nptr)
{
	if (nptr == '-')
		return (-1);
	return (1);
}

int	is_overflow(long int n)
{
	if (n > 2147483647 || n < -2147483648)
		return (-1);
	return (1);
}

static int	read_digits(const char *nptr, int i, int sign, int *out)
{
	long int	result;

	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (is_overflow(result * sign) == -1)
			return (0);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	*out = (int)(result * sign);
	return (1);
}

int	ft_atoi(const char *nptr, int *out)
{
	int	i;
	int	sign;

	i = the_start_of_num(nptr);
	if (i == -1)
		return (0);
	sign = get_sign(nptr[i]);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	return (read_digits(nptr, i, sign, out));
}
