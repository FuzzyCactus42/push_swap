/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallawne <sallawne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:40:34 by sallawne          #+#    #+#             */
/*   Updated: 2026/10/28 13:28:50 by sallawne         ###   ########.fr       */
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

typedef struct s_bench
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
}   t_bench;

void				init_stack(t_stack *stack);
void				free_stack(t_stack *stack);
int					append_value(t_stack *stack, int value);
void				sa(t_stack *s,t_bench *bench);
void				sb(t_stack *b,t_bench *bench);
void				ss(t_stack *s, t_stack *b,t_bench *bench);
void				push_b(t_stack *a, t_stack *b,t_bench *bench);
void				push_a(t_stack *b, t_stack *a,t_bench *bench);
void				rotate_a(t_stack *a,t_bench *bench);
void				rotate_b(t_stack *b,t_bench *bench);
void				rr(t_stack *a, t_stack *b,t_bench *bench);
void				rra(t_stack *a,t_bench *bench);
void				rrb(t_stack *b,t_bench *bench);
void				rrr(t_stack *a, t_stack *b,t_bench *bench);
void				simple(t_stack *a, t_stack *b,t_bench *bench);
void				assign(t_stack *a);
void				radix_sort(t_stack *a, t_stack *b,t_bench *bench);
double				disorder(t_stack *a);
int					adaptive(double inorder_v);
int ft_print_nbr(double i);
int ft_print_char(int c);
int ft_print_str(char *s);


#endif
