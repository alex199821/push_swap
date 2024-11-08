/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:33:12 by macbook           #+#    #+#             */
/*   Updated: 2024/11/08 03:03:32 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	new_node->above_median = NULL;
	new_node->price = INT_MAX;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->target = NULL;
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
		return (NULL);
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
	return (smallest);
}

void	small_sort(t_stack_node **stack, int *count)
{
	t_stack_node	*largest;
	int				list_length;

	largest = find_largest(stack);
	if (*stack == largest)
		ra(stack, count);
	else if ((*stack)->next == largest)
		rra(stack, count);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, count);
}

void	push_to_b(t_stack_node **a, t_stack_node **b, int *count)
{
	while (ft_lstsize(*a) > 3)
		pa(a, b, count);
}

void	set_positions(t_stack_node *stack)
{
	int	i;
	int	median_index;

	i = 0;
	if (!stack)
		return ;
	median_index = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median_index)
			stack->above_median = false;
		else
			stack->above_median = true;
		stack = stack->next;
		i++;
	}
}

static void find_target(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current;
    t_stack_node *target;

    while (b)
    {
        current = a;
        target = NULL;
        while (current)
        {
            if (current->value > b->value &&
                (!target || current->value < target->value))
            {
                target = current;
            }
            current = current->next;
        }
        if (!target)
            b->target = find_smallest(&a);
        else
            b->target = target;

        b = b->next;
    }
}

static void	count_price(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;
	int	price;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		price = 0;
		if (b->above_median && b->target->above_median)
			price = (size_b - b->index) + (size_a - b->target->index);
		else if (!b->above_median && b->target->above_median)
			price = (b->index) + (size_a - b->target->index);
		else if (b->above_median && !b->target->above_median)
			price = (size_b - b->index) + (b->target->index);
		else if (!b->above_median && !b->target->above_median)
			price = (b->index) + (b->target->index);
		b->price = price;
		b = b->next;
	}
}

t_stack_node	*find_cheapest(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*cheapest;

	if (!stack)
		return (NULL);
	current = *stack;
	cheapest = *stack;
	while (current)
	{
		if (current->price < cheapest->price)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

///--------------------ROTATION OPERATIONS-------------------//

void	rotate_target(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest, int *count)
{
	if (cheapest->target->above_median)
		rra(a, count);
	else
		ra(a, count);
}

void	rotate_node(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest,
		int *count)
{
	if (cheapest->above_median)
		rrb(b, count);
	else
		rb(b, count);
}

void	rotate_node_and_target(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest, int *count)
{
	if (cheapest->above_median && cheapest->target->above_median)
		rrr(a, b, count);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rr(a, b, count);
	else if (!cheapest->above_median && cheapest->target->above_median)
	{
		rb(b, count);
		rra(a, count);
	}
	else if (cheapest->above_median && !cheapest->target->above_median)
	{
		rrb(b, count);
		ra(a, count);
	}
}

void	perform_operations(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest, int *count)
{
	if (cheapest->index == 0 && cheapest->target->index == 0)
		pa(b, a, count);
	else if (cheapest->index == 0)
		rotate_target(a, b, cheapest, count);
	else if (cheapest->target->index == 0)
		rotate_node(a, b, cheapest, count);
	else
		rotate_node_and_target(a, b, cheapest, count);
	return ;
}
///--------------------ROTATION OPERATIONS-------------------//

void	push_swap(t_stack_node **a, t_stack_node **b, int *count)
{
	t_stack_node	*cheapest;

	set_positions(*a);
	set_positions(*b);
	find_target(*a, *b);
	count_price(*a, *b);
	cheapest = find_cheapest(b);
	perform_operations(a, b, cheapest, count);
}

void	sort_large(t_stack_node **a, t_stack_node **b, int list_length,
		int *count)
{
	small_sort(a, count);
	while (ft_lstsize(*a) < list_length)
	{
		push_swap(a, b, count);
	}
	while ((*a)->value != find_smallest(a)->value)
	{
		if (find_smallest(a)->above_median == true)
			rra(a, count);
		else
			ra(a, count);
	}
}

void	sort(t_stack_node **a, t_stack_node **b, int *count)
{
	int	list_length;

	list_length = ft_lstsize(*a);
	if (list_length <= 3)
		small_sort(a, count);
	else
	{
		push_to_b(a, b, count);
		sort_large(a, b, list_length, count);
	}
}

void	print_list(t_stack_node *head)
{
	t_stack_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d, ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				count;
	int				i;
	int				numbers[] = {949924, -166623, -909966, 154379, -83097, -763674, -799808, 282428, -895606, 496830, 161011, -250742, -629003, -76255, 780886, -980214, 781814, 983283, -117713, 545821, 562988, -842998, -916664, 583905, 838140, 854535, -272429, 996695, 382958, -802632, 928153, -633574, -990296, -967775, -725642, -853923, -787089, 332127, 96905, -860636, 230694, -930587, 65838, 842095, -28349, -291665, -305289, 551154, 352671, -953450, 303531, -677694, 377511, -839570, -446810, 355020, 653939, 507131, -738543, 306224, 859025, 620407, -527255, 1000502, 316624, -493922, 1010707, 446134, -368792, 226827, -563896, 683834, -878866, 295253, 838795, 887389, -36429, 288041, 537695, -470587, -212890, 592224, 485920, 344746, 496968, -502899, -458612, -127328, 34889, -393074, -84264, -101966, -691435, -963323, 909947, -206715, 182079, -601475, 241398, -370982};

	a = NULL;
	b = NULL;
	count = 0;
	i = 0;
	while (i < sizeof(numbers) / sizeof(numbers[0]))
	{
		add_to_beginning(&a, numbers[i]);
		i++;
	}
	sort(&a, &b, &count);
	print_list(a);
	printf("COUNT: %d\n", count);
	printf("Is sorted: %d\n", is_sorted(a));
	return (0);
}

// void	print_node_data(t_stack_node *head)
// {
// 	t_stack_node	*temp;

// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("Node Value is: %d, Node's Index is: %d, ", temp->value,
// 			temp->index);
// 		printf("and its above median: %d\n", temp->above_median);
// 		printf("Its Target is: %d, Its Target index is: %d, ",
// 			temp->target->value, temp->target->index);
// 		printf("price to push is: %d, and its target above median: %d\n\n\n",
// 			temp->price, temp->target->above_median);
// 		temp = temp->next;
// 	}
// 	printf("NULL\n");
// }

// void	print_single_node_data(t_stack_node *head)
// {
// 	t_stack_node	*temp;

// 	temp = head;
// 	printf("Node Value is: %d, Node's Index is: %d, ", temp->value,
// 		temp->index);
// 	printf("and its above median: %d\n", temp->above_median);
// 	printf("Its Target is: %d, Its Target index is: %d, ", temp->target->value,
// 		temp->target->index);
// 	printf("price to push is: %d, and its target above median: %d\n\n\n",
// 		temp->price, temp->target->above_median);
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