/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 07:24:20 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/26 11:37:33 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;
typedef struct s_flags
{
	int num_flags;
	int num_bench;

	char	*flag;
	bool	bench;
}	t_flags;
int		read_flags(char **str, int num_args, t_flags *flags);
int 	check_dup_erorr(int *arr, int count);
int		str2int(char **str, int num_arg, int **out, int start);
int		check_flags_error(char **str, int num_args, t_flags *flags);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr, int *out);
void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		append_value(t_stack *stack, int value);

#endif
