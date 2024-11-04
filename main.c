/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:33:12 by macbook           #+#    #+#             */
/*   Updated: 2024/11/04 16:22:28 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int					value;
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

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

//-------------PUSH-------------//

// static void	push(t_stack_node **src, t_stack_node **target)
// {
// 	t_stack_node	*first_node;

// 	if (*src == NULL)
// 		return ;
// 	first_node = remove_from_beginning(src);
// 	if (target == NULL)
// 	{
// 		*target = first_node;
// 		first_node->next = NULL;
// 	}
// 	else
// 	{
// 		first_node->next = *target;
// 		first_node->next->prev = first_node;
// 		*target = first_node;
// 	}
// }

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

void	pa(t_stack_node **src, t_stack_node **target)
{
	push(src, target);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **src, t_stack_node **target)
{
	push(src, target);
	write(1, "pb\n", 3);
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

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
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

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
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

	if (!stack)
	{
		return (NULL);
	}
	current = *stack;
	largest = *stack;
	while (current)
	{
		if (current->value > largest->value)
			largest = current;
		current = current->next;
	}
	return (largest);
}

// t_stack_node	*ft_lstlast(t_stack_node *stack)
// {
// 	t_stack_node	*current;

// 	current = stack;
// 	if (current)
// 	{
// 		while (current->next != NULL)
// 		{
// 			current = current->next;
// 		}
// 	}
// 	return (current);
// }

void	sort_stacks(t_stack_node **a, t_stack_node **b, int list_length)
{
	t_stack_node	*largest_node;

	if (is_sorted(*a) == 1 && list_length == ft_lstsize(*a))
	{
		printf("LIST IS SORTED");
		return ;
	}
	else
	{
		largest_node = find_largest(a);
		printf("Largest Node Value is: %d\n", largest_node->value);
		// if(*a->value > ft_lstlast(*a)->value)
		// {
		// 	rra(&a);
		// }
		// tiny_sort(a);
		return ;
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	list_length;

	list_length = ft_lstsize(*a);
	sort_stacks(a, b, list_length);
}

int	main(void)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	add_to_beginning(&a, 1);
	add_to_beginning(&a, -34);
	add_to_beginning(&a, 7);
	add_to_beginning(&a, 199);
	add_to_beginning(&a, 22);
	add_to_beginning(&a, -98);
	add_to_beginning(&a, 67);
	add_to_beginning(&a, 123);
	// add_to_end(&head, 30);
	// add_to_end(&head, 40);
	print_list(a);
	push_swap(&a, &b);
	// swap(&a);
	// push(&a, &b);
	// pb(&a, &b);
	// print_list(a);
	// print_list(b);
	// print_list(b);
	return (0);
}
