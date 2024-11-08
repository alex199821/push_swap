/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:44:05 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/08 23:04:01 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*ptr1;
	const char	*ptr2;

	ptr1 = dst;
	ptr2 = src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (n--)
		{
			*ptr1++ = *ptr2++;
		}
	}
	else
	{
		while (n--)
		{
			ptr1[n] = ptr2[n];
		}
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	if (!dst && !src)
	{
		return (NULL);
	}
	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	while (n--)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	return (dst);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*array;
	size_t	totalsize;

	totalsize = count * size;
	array = (char *)malloc(totalsize);
	if (array == NULL)
	{
		return (NULL);
	}
	ft_memset(array, '\0', totalsize);
	return (array);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*array;

	i = ft_strlen(src);
	array = (char *)ft_calloc(i + 1, sizeof(char));
	if (array == NULL)
	{
		return (NULL);
	}
	ft_memmove(array, src, i + 1);
	return (array);
}

int	countrows(char const *src, char delimiter)
{
	int	count;
	int	inrow;
	int	i;

	count = 0;
	inrow = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == delimiter)
		{
			if (inrow)
			{
				count++;
				inrow = 0;
			}
		}
		else
			inrow = 1;
		i++;
	}
	if (inrow)
		count++;
	return (count);
}

char	**free_all(char **parentarray, int arrayindex)
{
	int	j;

	j = 0;
	while (j < arrayindex)
	{
		free(parentarray[j]);
		j++;
	}
	free(parentarray);
	return (NULL);
}

char	*allocate_and_copy(const char *s, int startindex, int count)
{
	char	*subarray;

	subarray = (char *)malloc(sizeof(char) * (count + 1));
	if (subarray == NULL)
		return (NULL);
	ft_memcpy(subarray, &s[startindex], count);
	subarray[count] = '\0';
	return (subarray);
}

char	**str_div_logic(char **parentarray, const char *s, char c, int ar_index)
{
	int	i;
	int	count;
	int	startindex;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			startindex = i;
			while (s[i] != '\0' && s[i++] != c)
				count++;
			parentarray[ar_index] = allocate_and_copy(s, startindex, count);
			if (parentarray[ar_index++] == NULL)
				return (free_all(parentarray, ar_index));
			count = 0;
		}
		else
			i++;
	}
	return (parentarray);
}

char	**ft_split(char const *s, char c)
{
	char	**parentarray;
	int		ar_index;

	if (s == NULL)
	{
		return (NULL);
	}
	ar_index = 0;
	parentarray = (char **)malloc(sizeof(char *) * (countrows(s, c) + 1));
	if (parentarray == NULL)
	{
		return (NULL);
	}
	if (str_div_logic(parentarray, s, c, ar_index) == NULL)
	{
		return (NULL);
	}
	parentarray[countrows(s, c)] = NULL;
	return (parentarray);
}