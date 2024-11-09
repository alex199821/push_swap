/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:33:12 by macbook           #+#    #+#             */
/*   Updated: 2024/11/09 03:08:04 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	list_length;

	list_length = lstsize(*a);
	if (list_length < 2)
		return ;
	else if (list_length <= 3)
		small_sort(a);
	else
	{
		push_to_b(a, b);
		sort_large(a, b, list_length);
	}
}

int	initialize_and_sort(t_stack_node **a, t_stack_node **b, char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			if (ft_atol(array[i]) > INT_MAX || ft_atol(array[i]) < INT_MIN)
				return (free_ar_of_ars(array), write(2, "ERROR\n", 7), 1);
			add_to_end(a, ft_atol(array[i]));
			i++;
		}
	}
	free_ar_of_ars(array);
	if (has_duplicates(*a))
		return (write(2, "ERROR\n", 7), 1);
	else
		sort(a, b);
	return (0);
}

char	**arrange_args_inar(int argc, char **argv)
{
	char	**args;
	int		i;

	args = malloc(argc * sizeof(char *));
	i = 0;
	if (!args)
	{
		write(2, "ERROR\n", 7);
		return (NULL);
	}
	i++;
	while (argv[i])
	{
		args[i - 1] = ft_strdup(argv[i]);
		if (!args[i - 1])
		{
			free_ar_of_ars(args);
			write(2, "ERROR\n", 7);
			return (NULL);
		}
		i++;
	}
	args[i - 1] = NULL;
	return (args);
}

// leaks --atExit -- ./push_swap "2  3 6 7 2147483649"

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (write(2, "ERROR\n", 7), 1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = arrange_args_inar(argc, argv);
		if (!args)
			write(2, "ERROR\n", 7);
	}
	if (check_if_only_ints(args))
		initialize_and_sort(&a, &b, args);
	else
		return (free_ar_of_ars(args), write(2, "ERROR\n", 7), 1);
	free_linked_list(a);
	return (0);
}
