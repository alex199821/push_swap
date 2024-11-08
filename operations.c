/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:56:52 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/08 23:03:11 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_target(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	if (cheapest->target->above_median)
		rra(a);
	else
		ra(a);
}

void	rotate_node(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	if (cheapest->above_median)
		rrb(b);
	else
		rb(b);
}

void	rotate_node_and_target(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	if (cheapest->above_median && cheapest->target->above_median)
		rrr(a, b);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rr(a, b);
	else if (!cheapest->above_median && cheapest->target->above_median)
	{
		rb(b);
		rra(a);
	}
	else if (cheapest->above_median && !cheapest->target->above_median)
	{
		rrb(b);
		ra(a);
	}
}

void	perform_operations(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	if (cheapest->index == 0 && cheapest->target->index == 0)
		pa(b, a);
	else if (cheapest->index == 0)
		rotate_target(a, b, cheapest);
	else if (cheapest->target->index == 0)
		rotate_node(a, b, cheapest);
	else
		rotate_node_and_target(a, b, cheapest);
	return ;
}