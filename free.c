/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:59:56 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/09 02:40:47 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_linked_list(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	current = stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

char	**free_ar_of_ars(char **parentarray)
{
	int	i;

	i = 0;
	if (parentarray == NULL)
		return (NULL);
	while (parentarray[i] != NULL)
	{
		free(parentarray[i]);
		i++;
	}
	free(parentarray);
	return (NULL);
}
