/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saved_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:33:12 by macbook           #+#    #+#             */
/*   Updated: 2024/11/07 13:16:24 by macbook          ###   ########.fr       */
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
	int					price;
	int					chunk;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

////TESSSSSSSSSSSSSTTTTTTTT//

void	bubble_sort(int arr[], int size)
{
	int	temp;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// Swap the elements if they are in the wrong order
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int	find_median(t_stack_node *stack)
{
	int				*ar;
	t_stack_node	*current;
	int				i;
	int				size;
	int				median_index;

	i = 0;
	current = stack;
	while (current)
	{
		current = current->next;
		i++;
	}
	ar = (int *)malloc(i * sizeof(int));
	size = i;
	i = 0;
	current = stack;
	while (current)
	{
		ar[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort(ar, size);
	if (size % 2 == 0)
	{
		median_index = size / 2;
	}
	else
	{
		median_index = (size / 2) + 0.5;
	}
	return (ar[median_index]);
}

int	find_median_for_b(t_stack_node *stack)
{
	int				*ar;
	t_stack_node	*current;
	int				i;
	int				size;
	int				median_index;

	i = 0;
	current = stack;
	while (current)
	{
		current = current->next;
		i++;
	}
	ar = (int *)malloc(i * sizeof(int));
	size = i;
	i = 0;
	current = stack;
	while (current)
	{
		ar[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort(ar, size);
	if (size % 2 == 0)
	{
		median_index = size / 2;
	}
	else
	{
		median_index = (size / 2) - 0.5;
	}
	return (ar[median_index]);
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
	new_node->price = -1;
	new_node->chunk = 0;
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
		printf("%d -->", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}

void	print_chunk(t_stack_node *head)
{
	t_stack_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d --> ", temp->chunk);
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
	// write(1, "sa\n", 3);
	(*count)++;
}

void	sb(t_stack_node **b, int *count)
{
	swap(b);
	// write(1, "sb\n", 3);
	(*count)++;
}

void	ss(t_stack_node **a, t_stack_node **b, int *count)
{
	swap(a);
	swap(b);
	// write(1, "ss\n", 3);
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
	// write(1, "pa\n", 3);
	(*count)++;
}

void	pb(t_stack_node **src, t_stack_node **target, int *count)
{
	push(src, target);
	// write(1, "pb\n", 3);
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
	// write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, int *count)
{
	rotate(b);
	(*count)++;
	// write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, int *count)
{
	rotate(a);
	rotate(b);
	(*count)++;
	// write(1, "rr\n", 3);
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
	// write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, int *count)
{
	reverse_rotate(b);
	(*count)++;
	// write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, int *count)
{
	reverse_rotate(a);
	reverse_rotate(b);
	(*count)++;
	// write(1, "rrr\n", 4);
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
	if (i / largest->index >= 2)
	{
		largest->price = largest->index;
	}
	else
	{
		largest->price = -(largest->index - i);
	}
	return (largest);
}

t_stack_node	*find_smallest(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*smallest;
	int				i;

	i = 0;
	if (!stack)
	{
		return (NULL);
	}
	current = *stack;
	smallest = *stack;
	smallest->index = 0;
	while (current)
	{
		if (current->value < smallest->value)
		{
			smallest = current;
			smallest->index = i;
		}
		current = current->next;
		i++;
	}
	smallest->total_length = i;
	if (i / smallest->index >= 2)
	{
		smallest->price = smallest->index;
	}
	else
	{
		smallest->price = -(smallest->index - i);
	}
	return (smallest);
}

// void	push_by_chunks(t_stack_node **a, t_stack_node **b, int list_length,
// 		int *count)
// {
// 	int	median;
// 	int	run;

// 	run = 1;
// 	median = find_median(*a);
// 	if (ft_lstsize(*a) < 3)
// 	{
// 		if ((*a)->next->value && (*a)->value > (*a)->next->value)
// 		{
// 			sa(a, count);
// 		}
// 		return ;
// 	}
// 	while (run)
// 	{
// 		if (find_smallest(a)->value >= median)
// 		{
// 			run = 0;
// 		}
// 		if ((*a)->value < median)
// 		{
// 			pb(a, b, count);
// 			if((*b)->value < (*b)->next->value)
// 			{

// 			}
// 		}
// 		else
// 		{
// 			ra(a, count);
// 		}
// 	}
// 	push_by_chunks(a, b, ft_lstsize(*a), count);
// }

t_stack_node	*find_last_node(t_stack_node *head)
{
	// If the list is empty, return NULL
	if (head == NULL)
		return (NULL);
	// Traverse the list until we reach the last node
	while (head->next != NULL)
		head = head->next;
	// Now 'head' points to the last node
	return (head);
}

void	push_by_chunks(t_stack_node **a, t_stack_node **b, int list_length,
		int *count, int *chunk)
{
	int	median;
	int	run;

	run = 1;
	median = find_median(*a);
	if (ft_lstsize(*a) < 3)
	{
		if ((*a)->next->value && (*a)->value > (*a)->next->value)
		{
			sa(a, count);
		}
		(*chunk)--;
		return ;
	}
	while (run)
	{
		if (find_smallest(a)->value >= median)
		{
			run = 0;
		}
		if ((*a)->value < median)
		{
			pb(a, b, count);
			(*b)->chunk = *chunk;
			if ((*b)->next)
			{
				if ((*b)->value < (*b)->next->value)
				{
					if ((*b)->value < find_last_node(*b)->value)
					{
						rb(b, count);
					}
					else
					{
						sb(b, count);
					}
				}
			}
		}
		else
		{
			ra(a, count);
		}
	}
	(*chunk)++;
	push_by_chunks(a, b, ft_lstsize(*a), count, chunk);
}

static void	push_copy(t_stack_node **src, t_stack_node **target)
{
	t_stack_node	*first_node;

	if (*src == NULL)
		return ;
	// Create a new node and copy the values from the first node of the src list
	first_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (first_node == NULL)
		return ; // Handle memory allocation failure
	first_node->value = (*src)->value;
	first_node->index = (*src)->index;
	first_node->total_length = (*src)->total_length;
	first_node->price = (*src)->price;
	first_node->chunk = (*src)->chunk;
	first_node->prev = NULL;
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

int	chunks_left(t_stack_node *stack, int *chunk)
{
	t_stack_node	*current;

	current = stack;
	// printf("Chunk: %d\n", *chunk);
	while (current != NULL)
	{
		if (current->chunk == *chunk)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	push_by_chunks_b(t_stack_node **a, t_stack_node **b, int list_length,
		int *count, int *chunk)
{
	t_stack_node	*temp;
	t_stack_node	*next_node;
	t_stack_node	*current;
	int				median;
	int				run;

	temp = NULL;
	run = 1;
	if (ft_lstsize(*b) < 2)
	{
		pa(b, a, count);
		return ;
	}
	current = *b;
	// print_list(*b);
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			next_node = current->next;
		}
		else
		{
			next_node = NULL;
		}
		if (current->chunk == (*chunk))
		{
			push_copy(&current, &temp);
		}
		current = next_node;
	}
	print_list(temp);
	print_chunk(temp);
	median = find_median(temp);
	// printf("\n");
	// print_list(*b);
	// print_chunk(*b);
	// print_list(*a);
	printf("Median: %d\n\n", median);
	// printf("Chunk: %d\n", *chunk);
	// printf("\n");
	if (ft_lstsize(temp) == 1)
	{
		pa(b, a, count);
		run = 0;
	}
	else if (ft_lstsize(temp) == 2 && (*b)->chunk == *chunk
		&& (*b)->next->chunk == *chunk)
	{
		pa(b, a, count);
		pa(b, a, count);
		if ((*a)->value > (*a)->next->value)
		{
			sa(a, count);
		}
		run = 0;
	}
	else
	{
		while (run)
		{
			if (find_largest(b)->value <= median)
			{
				run = 0;
			}
			if ((*b)->value > median && (*b)->chunk == *chunk)
			{
				pa(b, a, count);
				if ((*a)->next)
				{
					// if ((*a)->value > (*a)->next->value
					// 	&& (*a)->value > find_last_node(*b)->value)
					// {
					// 	ra(a, count);
					// }
					// if ((*a)->value > (*a)->next->value)
					// {
					// 	sa(a, count);
					// }
					if ((*a)->value > (*a)->next->value)
					{
						// if ((*a)->value > find_last_node(*a)->value)
						// {
						// 	ra(a, count);
						// }
						// else
						// {
						sa(a, count);
						// }
					}
				}
			}
			else
			{
				rb(b, count);
			}
		}
	}
	if (*chunk > 0 && chunks_left(*b, chunk) == 0)
	{
		(*chunk)--;
	}
	// if (*chunk > 0)
	// {
	// 	(*chunk)--;
	// }
	push_by_chunks_b(a, b, ft_lstsize(*b), count, chunk);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b, int list_length,
		int *count)
{
	t_stack_node	*largest_node;
	t_stack_node	*smallest_node;

	if (a == NULL || b == NULL || *a == NULL)
		return ;
	largest_node = find_largest(a);
	smallest_node = find_smallest(a);
	if ((is_sorted(*b) == 1 && list_length == ft_lstsize(*b))
		|| largest_node == NULL)
		return ;
	else if (largest_node->index == 0)
	{
		pb(a, b, count);
		sort_stacks(a, b, list_length, count);
	}
	else if (smallest_node->index == 0)
	{
		pb(a, b, count);
		rb(b, count);
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

void	push_swap(t_stack_node **a, t_stack_node **b, int *count)
{
	int	list_length;
	int	i;
	int	chunk;

	i = 0;
	chunk = 0;
	list_length = ft_lstsize(*a);
	push_by_chunks(a, b, list_length, count, &chunk);
	push_by_chunks_b(a, b, list_length, count, &chunk);
	// sort_stacks(a,b, list_length, count);
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
						21, -693};

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
	// printf("\n\n");
	push_swap(&a, &b, &count);
	print_list(b);
	print_list(a);
	printf("COUNT: %d\n", count);
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