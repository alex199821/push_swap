/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:01:24 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/09 03:07:58 by macbook          ###   ########.fr       */
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
t_stack_node			*find_cheapest(t_stack_node **stack);

// atol.c
int						iswhitespace(char c);
long					ft_atol(const char *str);

// error_check.c
bool					is_number_string(const char *str);
bool					check_if_only_ints(char **string);
bool					has_minmax_int(t_stack_node *stack);
bool					has_duplicates(t_stack_node *stack);

// free.c
void					free_linked_list(t_stack_node *stack);
char					**free_ar_of_ars(char **parentarray);

// libft.c
size_t					ft_strlen(const char *c);
void					*ft_memmove(void *dst, const void *src, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_calloc(size_t count, size_t size);
char					*ft_strdup(const char *src);
char					**ft_split(char const *s, char c);

// linked_list.c
void					add_to_end(t_stack_node **head, int value);
t_stack_node			*remove_from_beginning(t_stack_node **head);
t_stack_node			*remove_from_end(t_stack_node **head);
int						lstsize(t_stack_node *stack);

// operations.c
void					perform_operations(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);

// push.c
void					pa(t_stack_node **src, t_stack_node **target);
void					pb(t_stack_node **src, t_stack_node **target);

// reverse_rotate.c
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

// rotate.c
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);

// swap.c
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);

// sort.c
void					small_sort(t_stack_node **stack);
void					push_swap(t_stack_node **a, t_stack_node **b);
void					sort_large(t_stack_node **a, t_stack_node **b,
							int list_length);
void					find_target(t_stack_node *a, t_stack_node *b);
void					count_price(t_stack_node *a, t_stack_node *b);
void					leaks(void);

#endif
