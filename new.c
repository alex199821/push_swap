/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:33:12 by macbook           #+#    #+#             */
/*   Updated: 2024/11/07 03:58:42 by macbook          ###   ########.fr       */
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

void	printArray(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("\n");
}

int	find_quintile(t_stack_node *stack, int *part)
{
	int				*ar;
	t_stack_node	*current;
	int				i;
	int				size;
	int				quintile_index;

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
	// printArray(ar, size);
	quintile_index = size * ((float)*part / 5) - 1;
	return (ar[quintile_index]);
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

void	push_by_chunks(t_stack_node **a, t_stack_node **b, int *count,
		t_stack_node **saved_stack, int *part)
{
	int	quintile_num;

	quintile_num = find_quintile(*saved_stack, part);
	printf("Quantile is: %d\n", quintile_num);
	printf("Part is: %d\n", *part);
	if (ft_lstsize(*b) >= ft_lstsize(*saved_stack))
	{
		return ;
	}
	while (find_smallest(a)->value > quintile_num)
	{
		if ((*a)->value <= quintile_num)
		{
			pb(a, b, count);
		}
		else
		{
			ra(a, count);
		}
	}
	(*part)++;
	push_by_chunks(a, b, count, saved_stack, part);
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

void	push_swap(t_stack_node **a, t_stack_node **b, int *count)
{
	int				list_length;
	int				part;
	t_stack_node	*next_node;
	t_stack_node	*current;
	t_stack_node	*saved_stack;

	saved_stack = NULL;
	list_length = ft_lstsize(*a);
	current = *a;
	// print_list(*b);
	part = 1;
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
		push_copy(&current, &saved_stack);
		current = next_node;
	}
	// print_list(saved_stack);
	push_by_chunks(a, b, count, &saved_stack, &part);
	// sort_stacks(b, a, list_length, count);
}

int	main(void)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				count;
	int				length;
	int				i;
	int				numbers[] = {42, 6, 8, 29, 26, 44, 11, 9, 35, 24, 49, 45,
						33, 5, 34, 40, 38, 25, 43, 46};

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
	// print_list(a);
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