/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:00:29 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/08 23:03:55 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_number_string(const char *str)
{
	int	i;

	i = 0;
	while (iswhitespace(str[i]) == 1)
		i++;
	if (str[i] == '\0')
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	check_if_only_ints(char **string)
{
	int	i;

	if (string)
	{
		i = 0;
		while (string[i])
		{
			if (is_number_string(string[i]))
			{
				i++;
			}
			else
			{
				return (false);
			}
		}
	}
	return (true);
}

bool	has_minmax_int(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current != NULL)
	{
		if (current->value > INT_MAX || current->value < INT_MIN)
		{
			return (true);
		}
		current = current->next;
	}
	return (false);
}

bool	has_duplicates(t_stack_node *stack)
{
	t_stack_node *current;
	t_stack_node *inner_current;

	current = stack;
	while (current != NULL)
	{
		inner_current = current->next;
		while (inner_current != NULL)
		{
			if (current->value == inner_current->value)
			{
				return (true);
			}
			inner_current = inner_current->next;
		}
		current = current->next;
	}
	return (false);
}