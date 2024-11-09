/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:59:09 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/09 02:40:53 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	long	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (iswhitespace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
