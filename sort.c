/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:58:37 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/08 23:02:57 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack_node **stack)
{
	t_stack_node	*largest;
	int				list_length;

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
	while (ft_lstsize(*a) < list_length)
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

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	list_length;

	list_length = ft_lstsize(*a);
	if (list_length <= 3)
		small_sort(a);
	else
	{
		push_to_b(a, b);
		sort_large(a, b, list_length);
	}
}