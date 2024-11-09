/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:58:37 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/09 03:07:31 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target;

	while (b)
	{
		current = a;
		target = NULL;
		while (current)
		{
			if (current->value > b->value && (!target
					|| current->value < target->value))
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

void	count_price(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;
	int	price;

	size_a = lstsize(a);
	size_b = lstsize(b);
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

void	small_sort(t_stack_node **stack)
{
	t_stack_node	*largest;

	largest = find_largest(stack);
	if (*stack == largest)
		ra(stack);
	else if ((*stack)->next == largest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	set_positions(*a);
	set_positions(*b);
	find_target(*a, *b);
	count_price(*a, *b);
	cheapest = find_cheapest(b);
	perform_operations(a, b, cheapest);
}

void	sort_large(t_stack_node **a, t_stack_node **b, int list_length)
{
	small_sort(a);
	while (lstsize(*a) < list_length)
	{
		push_swap(a, b);
	}
	while ((*a)->value != find_smallest(a)->value)
	{
		if (find_smallest(a)->above_median == true)
			rra(a);
		else
			ra(a);
	}
}
