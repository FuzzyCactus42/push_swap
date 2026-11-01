/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:40:34 by sallawne          #+#    #+#             */
/*   Updated: 2026/11/01 17:35:33 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
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

typedef struct s_flags
{
	int					num_flags;
	int					num_bench;
	char				*flag;
	bool				is_bench;
}					t_flags;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}					t_operation;

extern int			g_operations[OP_COUNT];

void				push_swap(t_flags *flag, t_stack *a, t_stack *b);
void				medium(t_stack *a, t_stack *b);
int					read_flags(char **str, int num_args, t_flags *flags);
int					check_dup_erorr(int *arr, int count);
int					str2int(char **str, int num_arg, int **out, int start);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *nptr, int *out);
int					fill_stack(t_stack *stack, int *values, int num_values);
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
void				simple(t_stack *a, t_stack *b);
void				rank(t_stack *a);
void				complex(t_stack *a, t_stack *b);
double				disorder(t_stack *a);
int					adaptive(double inorder_v);
int					ft_print_nbr(double i, int fd);
int					ft_print_char(int c, int fd);
int					ft_print_str(char *s, int fd);

void				bench(double inorder, char *flag);
void				chunck_based_algo(t_stack *a, t_stack *b);

#endif
