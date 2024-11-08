/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:33:12 by macbook           #+#    #+#             */
/*   Updated: 2024/11/08 23:03:34 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <dlfcn.h>
// #include <limits.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// typedef struct s_stack_node
// {
// 	int					value;
// 	int					index;
// 	int					total_length;
// 	int					price;
// 	bool				above_median;
// 	struct s_stack_node	*target;
// 	struct s_stack_node	*next;
// 	struct s_stack_node	*prev;
// }						t_stack_node;

//---------------LIBT FT--------------//

// size_t	ft_strlen(const char *c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (c[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// void	*ft_memmove(void *dst, const void *src, size_t n)
// {
// 	char		*ptr1;
// 	const char	*ptr2;

// 	ptr1 = dst;
// 	ptr2 = src;
// 	if (!dst && !src)
// 		return (NULL);
// 	if (dst < src)
// 	{
// 		while (n--)
// 		{
// 			*ptr1++ = *ptr2++;
// 		}
// 	}
// 	else
// 	{
// 		while (n--)
// 		{
// 			ptr1[n] = ptr2[n];
// 		}
// 	}
// 	return (dst);
// }

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	char	*ptr1;
// 	char	*ptr2;

// 	if (!dst && !src)
// 	{
// 		return (NULL);
// 	}
// 	ptr1 = (char *)dst;
// 	ptr2 = (char *)src;
// 	while (n--)
// 	{
// 		*ptr1 = *ptr2;
// 		ptr1++;
// 		ptr2++;
// 	}
// 	return (dst);
// }

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	unsigned char	*ptr;

// 	ptr = (unsigned char *)s;
// 	while (n--)
// 	{
// 		*ptr = (unsigned char)c;
// 		ptr++;
// 	}
// 	return (s);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*array;
// 	size_t	totalsize;

// 	totalsize = count * size;
// 	array = (char *)malloc(totalsize);
// 	if (array == NULL)
// 	{
// 		return (NULL);
// 	}
// 	ft_memset(array, '\0', totalsize);
// 	return (array);
// }

// char	*ft_strdup(const char *src)
// {
// 	size_t	i;
// 	char	*array;

// 	i = ft_strlen(src);
// 	array = (char *)ft_calloc(i + 1, sizeof(char));
// 	if (array == NULL)
// 	{
// 		return (NULL);
// 	}
// 	ft_memmove(array, src, i + 1);
// 	return (array);
// }

// //----------------FT_SPLIT-------------//

// int	countrows(char const *src, char delimiter)
// {
// 	int	count;
// 	int	inrow;
// 	int	i;

// 	count = 0;
// 	inrow = 0;
// 	i = 0;
// 	while (src[i] != '\0')
// 	{
// 		if (src[i] == delimiter)
// 		{
// 			if (inrow)
// 			{
// 				count++;
// 				inrow = 0;
// 			}
// 		}
// 		else
// 			inrow = 1;
// 		i++;
// 	}
// 	if (inrow)
// 		count++;
// 	return (count);
// }

// char	**free_all(char **parentarray, int arrayindex)
// {
// 	int	j;

// 	j = 0;
// 	while (j < arrayindex)
// 	{
// 		free(parentarray[j]);
// 		j++;
// 	}
// 	free(parentarray);
// 	return (NULL);
// }

// char	*allocate_and_copy(const char *s, int startindex, int count)
// {
// 	char	*subarray;

// 	subarray = (char *)malloc(sizeof(char) * (count + 1));
// 	if (subarray == NULL)
// 		return (NULL);
// 	ft_memcpy(subarray, &s[startindex], count);
// 	subarray[count] = '\0';
// 	return (subarray);
// }

// char	**str_div_logic(char **parentarray, const char *s, char c, int ar_index)
// {
// 	int	i;
// 	int	count;
// 	int	startindex;

// 	i = 0;
// 	count = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != c)
// 		{
// 			startindex = i;
// 			while (s[i] != '\0' && s[i++] != c)
// 				count++;
// 			parentarray[ar_index] = allocate_and_copy(s, startindex, count);
// 			if (parentarray[ar_index++] == NULL)
// 				return (free_all(parentarray, ar_index));
// 			count = 0;
// 		}
// 		else
// 			i++;
// 	}
// 	return (parentarray);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**parentarray;
// 	int		ar_index;

// 	if (s == NULL)
// 	{
// 		return (NULL);
// 	}
// 	ar_index = 0;
// 	parentarray = (char **)malloc(sizeof(char *) * (countrows(s, c) + 1));
// 	if (parentarray == NULL)
// 	{
// 		return (NULL);
// 	}
// 	if (str_div_logic(parentarray, s, c, ar_index) == NULL)
// 	{
// 		return (NULL);
// 	}
// 	parentarray[countrows(s, c)] = NULL;
// 	return (parentarray);
// }

//----------------FT_SPLIT-------------//
//-----------CREATE LINKED LIST-----------//

// t_stack_node	*create_node(int value)
// {
// 	t_stack_node	*new_node;

// 	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->value = value;
// 	new_node->index = -1;
// 	new_node->total_length = 0;
// 	new_node->above_median = NULL;
// 	new_node->price = INT_MAX;
// 	new_node->next = NULL;
// 	new_node->prev = NULL;
// 	new_node->target = NULL;
// 	return (new_node);
// }


// void	add_to_end(t_stack_node **head, int value)
// {
// 	t_stack_node	*new_node;
// 	t_stack_node	*temp;

// 	new_node = create_node(value);
// 	if (!new_node)
// 		return ;
// 	if (*head == NULL)
// 	{
// 		*head = new_node;
// 	}
// 	else
// 	{
// 		temp = *head;
// 		while (temp->next != NULL)
// 			temp = temp->next;
// 		temp->next = new_node;
// 		new_node->prev = temp;
// 	}
// }

// //-----------UTILS--------------//

// t_stack_node	*remove_from_beginning(t_stack_node **head)
// {
// 	t_stack_node	*removed_node;

// 	if (*head == NULL)
// 		return (NULL);
// 	removed_node = *head;
// 	*head = (*head)->next;
// 	if (*head != NULL)
// 		(*head)->prev = NULL;
// 	removed_node->next = NULL;
// 	return (removed_node);
// }

//-------------SWAP-------------//

// static void	swap(t_stack_node **stack)
// {
// 	t_stack_node	*first_node;
// 	t_stack_node	*second_node;

// 	if (*stack == NULL || (*stack)->next == NULL)
// 		return ;
// 	first_node = *stack;
// 	second_node = first_node->next;
// 	first_node->next = second_node->next;
// 	first_node->prev = second_node;
// 	if (second_node->next != NULL)
// 		second_node->next->prev = first_node;
// 	second_node->next = first_node;
// 	second_node->prev = NULL;
// 	*stack = second_node;
// }

// void	sa(t_stack_node **a)
// {
// 	swap(a);
// 	write(1, "sa\n", 3);
// }

// void	sb(t_stack_node **b)
// {
// 	swap(b);
// 	write(1, "sb\n", 3);
// }

// void	ss(t_stack_node **a, t_stack_node **b)
// {
// 	swap(a);
// 	swap(b);
// 	write(1, "ss\n", 3);
// }

//-------------PUSH-------------//

// static void	push(t_stack_node **src, t_stack_node **target)
// {
// 	t_stack_node	*first_node;

// 	if (*src == NULL)
// 		return ;
// 	first_node = remove_from_beginning(src);
// 	if (*target == NULL)
// 	{
// 		*target = first_node;
// 		first_node->next = NULL;
// 	}
// 	else
// 	{
// 		first_node->next = *target;
// 		(*target)->prev = first_node;
// 		*target = first_node;
// 	}
// }

// void	pa(t_stack_node **src, t_stack_node **target)
// {
// 	push(src, target);
// 	write(1, "pa\n", 3);
// }

// void	pb(t_stack_node **src, t_stack_node **target)
// {
// 	push(src, target);
// 	write(1, "pb\n", 3);
// }

//-------------ROTATE-------------//

// static void	rotate(t_stack_node **stack)
// {
// 	t_stack_node	*first_node;
// 	t_stack_node	*current;

// 	if (*stack == NULL || (*stack)->next == NULL)
// 		return ;
// 	first_node = remove_from_beginning(stack);
// 	current = *stack;
// 	while (current->next != NULL)
// 		current = current->next;
// 	current->next = first_node;
// 	first_node->prev = current;
// 	first_node->next = NULL;
// }

// void	ra(t_stack_node **a)
// {
// 	rotate(a);
// 	write(1, "ra\n", 3);
// }

// void	rb(t_stack_node **b)
// {
// 	rotate(b);
// 	write(1, "rb\n", 3);
// }

// void	rr(t_stack_node **a, t_stack_node **b)
// {
// 	rotate(a);
// 	rotate(b);
// 	write(1, "rr\n", 3);
// }

//-------------REVERSE ROTATE-------------//

// static void	reverse_rotate(t_stack_node **stack)
// {
// 	t_stack_node	*last_node;
// 	t_stack_node	*current;

// 	if (*stack == NULL || (*stack)->next == NULL)
// 		return ;
// 	current = *stack;
// 	last_node = remove_from_end(stack);
// 	last_node->next = current;
// 	current->prev = last_node;
// 	*stack = last_node;
// }

// void	rra(t_stack_node **a)
// {
// 	reverse_rotate(a);
// 	write(1, "rra\n", 4);
// }

// void	rrb(t_stack_node **b)
// {
// 	reverse_rotate(b);
// 	write(1, "rrb\n", 4);
// }

// void	rrr(t_stack_node **a, t_stack_node **b)
// {
// 	reverse_rotate(a);
// 	reverse_rotate(b);
// 	write(1, "rrr\n", 4);
// }

//----------------------------------------//

// int	ft_lstsize(t_stack_node *stack)
// {
// 	int				i;
// 	t_stack_node	*current;

// 	current = stack;
// 	i = 0;
// 	while (current != NULL)
// 	{
// 		current = current->next;
// 		i++;
// 	}
// 	return (i);
// }

// t_stack_node	*find_largest(t_stack_node **stack)
// {
// 	t_stack_node	*current;
// 	t_stack_node	*largest;
// 	int				i;

// 	i = 0;
// 	if (!stack)
// 		return (NULL);
// 	current = *stack;
// 	largest = *stack;
// 	largest->index = 0;
// 	while (current)
// 	{
// 		if (current->value > largest->value)
// 		{
// 			largest = current;
// 			largest->index = i;
// 		}
// 		current = current->next;
// 		i++;
// 	}
// 	largest->total_length = i;
// 	return (largest);
// }

// t_stack_node	*find_smallest(t_stack_node **stack)
// {
// 	t_stack_node	*current;
// 	t_stack_node	*smallest;
// 	int				i;

// 	i = 0;
// 	if (!stack)
// 	{
// 		return (NULL);
// 	}
// 	current = *stack;
// 	smallest = *stack;
// 	smallest->index = 0;
// 	while (current)
// 	{
// 		if (current->value < smallest->value)
// 		{
// 			smallest = current;
// 			smallest->index = i;
// 		}
// 		current = current->next;
// 		i++;
// 	}
// 	smallest->total_length = i;
// 	return (smallest);
// }

// void	small_sort(t_stack_node **stack)
// {
// 	t_stack_node	*largest;
// 	int				list_length;

// 	largest = find_largest(stack);
// 	if (*stack == largest)
// 		ra(stack);
// 	else if ((*stack)->next == largest)
// 		rra(stack);
// 	if ((*stack)->value > (*stack)->next->value)
// 		sa(stack);
// }

// void	push_to_b(t_stack_node **a, t_stack_node **b)
// {
// 	while (ft_lstsize(*a) > 3)
// 		pb(a, b);
// }

// void	set_positions(t_stack_node *stack)
// {
// 	int	i;
// 	int	median_index;

// 	i = 0;
// 	if (!stack)
// 		return ;
// 	median_index = ft_lstsize(stack) / 2;
// 	while (stack)
// 	{
// 		stack->index = i;
// 		if (i <= median_index)
// 			stack->above_median = false;
// 		else
// 			stack->above_median = true;
// 		stack = stack->next;
// 		i++;
// 	}
// }

// static void	find_target(t_stack_node *a, t_stack_node *b)
// {
// 	t_stack_node	*current;
// 	t_stack_node	*target;

// 	while (b)
// 	{
// 		current = a;
// 		target = NULL;
// 		while (current)
// 		{
// 			if (current->value > b->value && (!target
// 					|| current->value < target->value))
// 			{
// 				target = current;
// 			}
// 			current = current->next;
// 		}
// 		if (!target)
// 			b->target = find_smallest(&a);
// 		else
// 			b->target = target;
// 		b = b->next;
// 	}
// }

// static void	count_price(t_stack_node *a, t_stack_node *b)
// {
// 	int	size_a;
// 	int	size_b;
// 	int	price;

// 	size_a = ft_lstsize(a);
// 	size_b = ft_lstsize(b);
// 	while (b)
// 	{
// 		price = 0;
// 		if (b->above_median && b->target->above_median)
// 			price = (size_b - b->index) + (size_a - b->target->index);
// 		else if (!b->above_median && b->target->above_median)
// 			price = (b->index) + (size_a - b->target->index);
// 		else if (b->above_median && !b->target->above_median)
// 			price = (size_b - b->index) + (b->target->index);
// 		else if (!b->above_median && !b->target->above_median)
// 			price = (b->index) + (b->target->index);
// 		b->price = price;
// 		b = b->next;
// 	}
// }

// t_stack_node	*find_cheapest(t_stack_node **stack)
// {
// 	t_stack_node	*current;
// 	t_stack_node	*cheapest;

// 	if (!stack)
// 		return (NULL);
// 	current = *stack;
// 	cheapest = *stack;
// 	while (current)
// 	{
// 		if (current->price < cheapest->price)
// 			cheapest = current;
// 		current = current->next;
// 	}
// 	return (cheapest);
// }

///--------------------ROTATION OPERATIONS-------------------//

// void	rotate_target(t_stack_node **a, t_stack_node **b,
// 		t_stack_node *cheapest)
// {
// 	if (cheapest->target->above_median)
// 		rra(a);
// 	else
// 		ra(a);
// }

// void	rotate_node(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
// {
// 	if (cheapest->above_median)
// 		rrb(b);
// 	else
// 		rb(b);
// }

// void	rotate_node_and_target(t_stack_node **a, t_stack_node **b,
// 		t_stack_node *cheapest)
// {
// 	if (cheapest->above_median && cheapest->target->above_median)
// 		rrr(a, b);
// 	else if (!cheapest->above_median && !cheapest->target->above_median)
// 		rr(a, b);
// 	else if (!cheapest->above_median && cheapest->target->above_median)
// 	{
// 		rb(b);
// 		rra(a);
// 	}
// 	else if (cheapest->above_median && !cheapest->target->above_median)
// 	{
// 		rrb(b);
// 		ra(a);
// 	}
// }

// void	perform_operations(t_stack_node **a, t_stack_node **b,
// 		t_stack_node *cheapest)
// {
// 	if (cheapest->index == 0 && cheapest->target->index == 0)
// 		pa(b, a);
// 	else if (cheapest->index == 0)
// 		rotate_target(a, b, cheapest);
// 	else if (cheapest->target->index == 0)
// 		rotate_node(a, b, cheapest);
// 	else
// 		rotate_node_and_target(a, b, cheapest);
// 	return ;
// }
///--------------------ROTATION OPERATIONS-------------------//

// void	small_sort(t_stack_node **stack)
// {
// 	t_stack_node	*largest;
// 	int				list_length;

// 	largest = find_largest(stack);
// 	if (*stack == largest)
// 		ra(stack);
// 	else if ((*stack)->next == largest)
// 		rra(stack);
// 	if ((*stack)->value > (*stack)->next->value)
// 		sa(stack);
// }

// void	push_swap(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*cheapest;

// 	set_positions(*a);
// 	set_positions(*b);
// 	find_target(*a, *b);
// 	count_price(*a, *b);
// 	cheapest = find_cheapest(b);
// 	perform_operations(a, b, cheapest);
// }

// void	sort_large(t_stack_node **a, t_stack_node **b, int list_length)
// {
// 	small_sort(a);
// 	while (ft_lstsize(*a) < list_length)
// 	{
// 		push_swap(a, b);
// 	}
// 	while ((*a)->value != find_smallest(a)->value)
// 	{
// 		if (find_smallest(a)->above_median == true)
// 			rra(a);
// 		else
// 			ra(a);
// 	}
// }

// void	sort(t_stack_node **a, t_stack_node **b)
// {
// 	int	list_length;

// 	list_length = ft_lstsize(*a);
// 	if (list_length <= 3)
// 		small_sort(a);
// 	else
// 	{
// 		push_to_b(a, b);
// 		sort_large(a, b, list_length);
// 	}
// }

// void	free_linked_list(t_stack_node *stack)
// {
// 	t_stack_node	*current;
// 	t_stack_node	*next_node;

// 	current = stack;
// 	while (current != NULL)
// 	{
// 		next_node = current->next;
// 		free(current);
// 		current = next_node;
// 	}
// }

// char	**free_ar_of_ars(char **parentarray)
// {
// 	int	j;

// 	j = 0;
// 	if (parentarray == NULL)
// 		return (NULL);
// 	while (parentarray[j] != NULL)
// 	{
// 		free(parentarray[j]);
// 		j++;
// 	}
// 	free(parentarray);
// 	return (NULL);
// }

//---------------ATOL---------------//

// int	iswhitespace(char c)
// {
// 	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
// 		|| c == '\r')
// 	{
// 		return (1);
// 	}
// 	return (0);
// }

// long	ft_atol(const char *str)
// {
// 	int		i;
// 	long	res;
// 	long	sign;

// 	i = 0;
// 	sign = 1;
// 	res = 0;
// 	while (iswhitespace(str[i]) == 1)
// 		i++;
// 	if (str[i] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 	{
// 		i++;
// 	}
// 	while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'))
// 	{
// 		res = res * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (res * sign);
// }

//--------------ATOL---------------//

//-------------IS NUMBER STRING -------------//
// bool	is_number_string(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (iswhitespace(str[i]) == 1)
// 		i++;
// 	if (str[i] == '\0')
// 		return (false);
// 	if (str[i] == '+' || str[i] == '-')
// 		i++;
// 	if (str[i] == '\0')
// 		return (false);
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] < '0' || str[i] > '9')
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

// bool	check_if_only_ints(char **string)
// {
// 	int	i;

// 	if (string)
// 	{
// 		i = 0;
// 		while (string[i])
// 		{
// 			if (is_number_string(string[i]))
// 			{
// 				i++;
// 			}
// 			else
// 			{
// 				return (false);
// 			}
// 		}
// 	}
// 	return (true);
// }
// //-------------IS NUMBER STRING -------------//

// bool	has_minmax_int(t_stack_node *stack)
// {
// 	t_stack_node	*current;

// 	current = stack;
// 	while (current != NULL)
// 	{
// 		if (current->value > INT_MAX || current->value < INT_MIN)
// 		{
// 			return (true);
// 		}
// 		current = current->next;
// 	}
// 	return (false);
// }

// bool	has_duplicates(t_stack_node *stack)
// {
// 	t_stack_node	*current;
// 	t_stack_node	*inner_current;

// 	current = stack;
// 	while (current != NULL)
// 	{
// 		inner_current = current->next;
// 		while (inner_current != NULL)
// 		{
// 			if (current->value == inner_current->value)
// 			{
// 				return (true);
// 			}
// 			inner_current = inner_current->next;
// 		}
// 		current = current->next;
// 	}
// 	return (false);
// }

// void	leaks(void)
// {
// 	system("leaks push_swap");
// }

int	initialize_and_sort(t_stack_node **a, t_stack_node **b, char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			if (ft_atol(array[i]) > INT_MAX || ft_atol(array[i]) < INT_MIN)
				return (free_ar_of_ars(array), write(2, "ERROR\n", 7), 1);
			add_to_end(a, ft_atol(array[i]));
			i++;
		}
	}
	free_ar_of_ars(array);
	if (has_duplicates(*a))
		return (write(2, "ERROR\n", 7), 1);
	else
		sort(a, b);
	return (0);
}

char	**arrange_args_inar(int argc, char **argv)
{
	char	**args;
	int i;
	
	args = malloc(argc * sizeof(char *));
	i = 0;
	if (!args)
	{
		write(2, "ERROR\n", 7);
		return (NULL);
	}
	i++;
	while (argv[i])
	{
		args[i - 1] = ft_strdup(argv[i]);
		if (!args[i - 1])
		{
			free_ar_of_ars(args);
			write(2, "ERROR\n", 7);
			return (NULL);
		}
		i++;
	}
	args[i - 1] = NULL;
	return (args);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				i;

	a = NULL;
	b = NULL;
	// atexit(leaks);
	i = 0;
	if (argc < 2)
		return (write(2, "ERROR\n", 7), 1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = arrange_args_inar(argc, argv);
		if (!args)
			return (write(2, "ERROR\n", 7), 1);
	}
	if (check_if_only_ints(args))
		return (initialize_and_sort(&a, &b, args));
	else
		return (free_ar_of_ars(args), write(2, "ERROR\n", 7), 1);
	free_linked_list(a);
	return (0);
}

// Whole list of commands i have:
// sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.
