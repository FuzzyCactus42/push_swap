/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 13:21:43 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/24 13:21:45 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t  i;

        i = 0;
        while (i < n)
        {
                if (s1[i] != s2[i])
                        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                if (s1[i] == '\0')
                        return (0);
                i++;
        }
        return (0);
}
