/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:40:34 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/27 07:36:05 by sallawne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

void				init_stack(t_stack *stack);
void				free_stack(t_stack *stack);
int					append_value(t_stack *stack, int value);
void				sa(t_stack *s);
void				sb(t_stack *b);
void				ss(t_stack *s, t_stack *b);
void				push_b(t_stack *a, t_stack *b);
void				push_a(t_stack *b, t_stack *a);
void				rotate_a(t_stack *a);
void				rotate_b(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				sort_simple(t_stack *a, t_stack *b);
void				simple(t_stack *a, t_stack *b);
void				assign(t_stack *a);
void				radix_sort(t_stack *a, t_stack *b);
double  disorder(t_stack *a);

#endif
