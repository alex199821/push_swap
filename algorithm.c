/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:56:05 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/08 23:03:48 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	find_target(t_stack_node *a, t_stack_node *b)
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
