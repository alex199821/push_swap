/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:01:24 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/08 23:08:38 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					total_length;
	int					price;
	bool				above_median;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// algorithm_utils.c
t_stack_node			*find_largest(t_stack_node **stack);
t_stack_node			*find_smallest(t_stack_node **stack);
void					push_to_b(t_stack_node **a, t_stack_node **b);

// algorithm.c
void					set_positions(t_stack_node *stack);
static void				find_target(t_stack_node *a, t_stack_node *b);
static void				count_price(t_stack_node *a, t_stack_node *b);
t_stack_node			*find_cheapest(t_stack_node **stack);

//atol.c
int	iswhitespace(char c);
long	ft_atol(const char *str);

//error_check.c
bool	is_number_string(const char *str);
bool	check_if_only_ints(char **string);
bool	has_minmax_int(t_stack_node *stack);
bool	has_duplicates(t_stack_node *stack);

//free.c
void	free_linked_list(t_stack_node *stack);
char	**free_ar_of_ars(char **parentarray);

//libft.c



#endif
