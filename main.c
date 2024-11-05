/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:33:12 by macbook           #+#    #+#             */
/*   Updated: 2024/11/05 02:18:35 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					total_length;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

////TESSSSSSSSSSSSSTTTTTTTT//

// Function to count the number of nodes in the linked list
int	count_nodes(t_stack_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

// Function to convert the linked list to an array
int	*list_to_array(t_stack_node *head, int length)
{
	int	*array;

	array = malloc(length * sizeof(int));
	if (!array)
		return (NULL);
	for (int i = 0; i < length; i++)
	{
		array[i] = head->value;
		head = head->next;
	}
	return (array);
}

// Simple bubble sort function
void	bubble_sort(int *array, int length)
{
	int	temp;

	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

// Function to find the median value of the linked list
int	find_median(t_stack_node *head)
{
	int	length;
	int	*array;
	int	median;

	length = count_nodes(head);
	if (length == 0)
		return (0); // or handle empty list case appropriately
	array = list_to_array(head, length);
	if (!array)
		return (0); // or handle memory allocation failure
	bubble_sort(array, length);
	// Calculate the median
	if (length % 2 == 0)
	{
		// Even number of elements
		median = (array[length / 2 - 1] + array[length / 2]) / 2;
	}
	else
	{
		// Odd number of elements
		median = array[length / 2];
	}
	free(array); // Don't forget to free the allocated memory
	return (median);
}
//////////////////////////////////////////

//-----------CREATE LINKED LIST-----------//

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->total_length = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_to_beginning(t_stack_node **head, int value)
{
	t_stack_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return ;
	if (*head != NULL)
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	*head = new_node;
}

void	add_to_end(t_stack_node **head, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	new_node = create_node(value);
	if (!new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

void	print_list(t_stack_node *head)
{
	t_stack_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d --> ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}

//-----------UTILS--------------//
t_stack_node	*remove_from_beginning(t_stack_node **head)
{
	t_stack_node	*removed_node;

	if (*head == NULL)
		return (NULL);
	removed_node = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	removed_node->next = NULL;
	return (removed_node);
}

//-------------SWAP-------------//

static void	swap(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	first_node->next = second_node->next;
	first_node->prev = second_node;
	if (second_node->next != NULL)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	second_node->prev = NULL;
	*stack = second_node;
}

void	sa(t_stack_node **a, int *count)
{
	swap(a);
	write(1, "sa\n", 3);
	(*count)++;
}

void	sb(t_stack_node **b, int *count)
{
	swap(b);
	write(1, "sb\n", 3);
	(*count)++;
}

void	ss(t_stack_node **a, t_stack_node **b, int *count)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	(*count)++;
}

//-------------PUSH-------------//

static void	push(t_stack_node **src, t_stack_node **target)
{
	t_stack_node	*first_node;

	if (*src == NULL)
		return ;
	first_node = remove_from_beginning(src);
	if (*target == NULL)
	{
		*target = first_node;
		first_node->next = NULL;
	}
	else
	{
		first_node->next = *target;
		(*target)->prev = first_node;
		*target = first_node;
	}
}

void	pa(t_stack_node **src, t_stack_node **target, int *count)
{
	push(src, target);
	write(1, "pa\n", 3);
	(*count)++;
}

void	pb(t_stack_node **src, t_stack_node **target, int *count)
{
	push(src, target);
	write(1, "pb\n", 3);
	(*count)++;
}

//-------------ROTATE-------------//

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = remove_from_beginning(stack);
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = first_node;
	first_node->prev = current;
	first_node->next = NULL;
}

void	ra(t_stack_node **a, int *count)
{
	rotate(a);
	(*count)++;
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, int *count)
{
	rotate(b);
	(*count)++;
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, int *count)
{
	rotate(a);
	rotate(b);
	(*count)++;
	write(1, "rr\n", 3);
}

//-------------REVERSE ROTATE-------------//

t_stack_node	*remove_from_end(t_stack_node **head)
{
	t_stack_node	*temp;

	if (*head == NULL)
		return (NULL);
	temp = *head;
	if (temp->next == NULL)
	{
		*head = NULL;
		temp->prev = NULL;
		return (temp);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->prev = NULL;
	return (temp);
}

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	last_node = remove_from_end(stack);
	last_node->next = current;
	current->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack_node **a, int *count)
{
	reverse_rotate(a);
	(*count)++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, int *count)
{
	reverse_rotate(b);
	(*count)++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, int *count)
{
	reverse_rotate(a);
	reverse_rotate(b);
	(*count)++;
	write(1, "rrr\n", 4);
}

//----------------------------------------//

int	ft_lstsize(t_stack_node *stack)
{
	int				i;
	t_stack_node	*current;

	current = stack;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*find_largest(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*largest;
	int				i;

	i = 0;
	if (!stack)
	{
		return (NULL);
	}
	current = *stack;
	largest = *stack;
	largest->index = 0;
	while (current)
	{
		if (current->value > largest->value)
		{
			largest = current;
			largest->index = i;
		}
		current = current->next;
		i++;
	}
	largest->total_length = i;
	return (largest);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b, int list_length,
		int *count)
{
	t_stack_node	*largest_node;

	if (a == NULL || b == NULL || *a == NULL)
		return ;
	largest_node = find_largest(a);
	if ((is_sorted(*b) == 1 && list_length == ft_lstsize(*b))
		|| largest_node == NULL)
		return ;
	else if (largest_node->index == 0)
	{
		pb(a, b, count);
		sort_stacks(a, b, list_length, count);
	}
	else if (largest_node->total_length / largest_node->index <= 1)
	{
		rra(a, count);
		sort_stacks(a, b, list_length, count);
	}
	else if (largest_node->total_length / largest_node->index >= 2)
	{
		ra(a, count);
		sort_stacks(a, b, list_length, count);
	}
}

void	push_by_chunks(t_stack_node **a, t_stack_node **b, int list_length,
		int *count)
{
	int	median;
	int	iterations;

	iterations = 0;
	median = find_median(*a);
	while (ft_lstsize(*a) > list_length / 2)
	{
		if ((*a)->value <= median)
		{
			pb(a, b, count);
		}
		// else if ((*a)->prev && (*a)->prev->value <= median)
		// {
		// 	rra(a, count);
		// }
		else
		{
			rra(a, count);
		}
	}
	if (ft_lstsize(*a) == 0)
	{
		return ;
	}
	else
	{
		push_by_chunks(a, b, ft_lstsize(*a), count);
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b, int *count)
{
	int	list_length;

	list_length = ft_lstsize(*a);
	push_by_chunks(a, b, list_length, count);
	// printf("MEDIAN IS: %d\n", median);
	// sort_stacks(b, a, list_length, count);
}

int	main(void)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				count;
	int				length;
	int				i;
	int				numbers[] = {-1831, 1527, -1245, 777, -232, 1945, 656,
						-1010, 257, -1624, -318, 972, 223, 311, -190, 974, 1509,
						21, -693, 1777, 1396, -1021, -651, 1123, -1570, 880,
						-1568, -158, -1989, -962, -242, 711, -1976, -1544, 1853,
						1979, 197, 1133, -642, -1608, -1666, 1837, -1448, -1346,
						824, -173, 70, -403, 231, 799, -1663, -942, 1426, -1452,
						558, 707, -1107, 1569, -1251, -834, -1240, -1822, -1913,
						1352, -1586, -912, 856, -1533, -505, -1815, 705, -901,
						769, -802, -1916, 13, -109, -678, -153, 295, -1280,
						-111, 110, 761, -667, 446, 515, -1412, 1543, 1855,
						-1959, -414, -1276, 482, -613, 1726, -1025, 1264, 370,
						-672};

	a = NULL;
	b = NULL;
	count = 0;
	length = sizeof(numbers) / sizeof(numbers[0]);
	i = 0;
	while (i < length)
	{
		add_to_beginning(&a, numbers[i]);
		i++;
	}
	print_list(a);
	push_swap(&a, &b, &count);
	print_list(b);
	print_list(a);
	printf("COUNT: %d\n", count);
	return (0);
}

// void	bubble_sort_to_b(t_stack_node **a, t_stack_node **b, int list_length,
// 		int *count)
// {
// 	if (a == NULL || *a == NULL)
// 		return ;
// 	if (list_length == ft_lstsize(*b))
// 		return ;
// 	if ((*a)->next != NULL && ((*a)->value < (*a)->next->value))
// 	{
// 		sa(a, count);
// 		bubble_sort_to_b(a, b, list_length, count);
// 	}
// 	else
// 	{
// 		pb(a, b, count);
// 		bubble_sort_to_b(a, b, list_length, count);
// 	}
// }

// void	bubble_sort_to_a(t_stack_node **a, t_stack_node **b, int list_length,
// 		int *count)
// {
// 	if (b == NULL || *b == NULL)
// 		return ;
// 	if (list_length == ft_lstsize(*a))
// 		return ;
// 	if ((*b)->next != NULL && ((*b)->value > (*b)->next->value))
// 	{
// 		sb(b, count);
// 		bubble_sort_to_a(a, b, list_length, count);
// 	}
// 	else
// 	{
// 		pa(b, a, count);
// 		bubble_sort_to_a(a, b, list_length, count);
// 	}
// }

// void	sort_stacks(t_stack_node **a, t_stack_node **b, int list_length,
// 		int *count)
// {
// 	t_stack_node	*largest_node;

// 	if (a == NULL || b == NULL || *a == NULL)
// 		return ;
// 	largest_node = find_largest(a);
// 	if ((is_sorted(*b) == 1 && list_length == ft_lstsize(*b))
// || largest_node == NULL)
// 		return ;
// 	else if (largest_node->index == 0)
// 	{
// 		pb(a, b, count);
// Take the first element at the top of a and put it at the top of b. Do nothing if a is empty
// 		sort_stacks(a, b, list_length, count);
// 	}
// 	else if (largest_node->total_length / largest_node->index <= 1)
// 	{
// 		rra(a, count);
// Shift down all elements of stack a by 1. The last element becomes the first one.
// 		sort_stacks(a, b, list_length, count);
// 	}
// 	else if (largest_node->total_length / largest_node->index >= 2)
// 	{
// 		ra(a, count);
// Shift up all elements of stack a by 1. The first element becomes the last one.
// 		sort_stacks(a, b, list_length, count);
// 	}
// }

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