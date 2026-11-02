/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:38:59 by hhailat           #+#    #+#             */
/*   Updated: 2026/11/02 13:41:48 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Return -1 for a NULL array or duplicate values, and 1 otherwise.
*/
int	check_dup_erorr(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	if (!arr)
		return (-1);
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[j] == arr[i])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
