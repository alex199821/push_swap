/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:55:24 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/09 03:08:14 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_to_b(t_stack_node **a, t_stack_node **b)
{
	while (lstsize(*a) > 3)
		pb(a, b);
}
