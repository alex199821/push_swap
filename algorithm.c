/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:56:05 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/09 03:08:09 by macbook          ###   ########.fr       */
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
	median_index = lstsize(stack) / 2;
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
