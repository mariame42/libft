/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:13:08 by phelen            #+#    #+#             */
/*   Updated: 2024/07/11 16:15:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	char				*sub;
	unsigned int		i;
	unsigned int		j;

	str = (char *)s;
	i = 0;
	j = 0;
	if (str[i] == '\0')
		return (NULL);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!(sub))
		return (NULL);
	while (str[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = str[i];
			j++;
		}
		i++;
	}
	return (sub);
}

// "123 world this is a test"
//  01234567890123456789123456789123
//  | 1 |  2 |3|  2 
//     5 s = 1   2    3    4  5  6
static int	part_number(const char *str, char c)
{
	int		num;
	int		i;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
		{
			num++;
		}
		i++;
	}
	return (num);
}

static int	char_number(const char *str, char c)
{
	int		num;

	num = 0;
	while (str[num] && str[num] != c)
		num++;
	return (num);
}

static char	*copy_part(char **arr, char c)
{
	char	*str;
	int		len;

	len = char_number(*arr, c);
	str = ft_substr(*arr, 0, len);
	*arr += len;
	return (str);
}

char	**ft_split(char const *arr, char c)
{
	char	**result;
	char	*str;
	int		number;
	int		index;

	if (!arr)
		return (NULL);
	str = (char *)arr;
	number = part_number(str, c);
	if (!(result = malloc(sizeof(char *) * (number + 1))))
		return (NULL);
	result[number] = NULL;
	index = 0;
	while (index < number)
	{
		while (*str == c)
			str++;
		result[index] = copy_part(&str, c);
		if (!result[index])
			while (index >= 0)
				free(result[index--]);
			free(result);
			return (NULL);
		index++;
	}
	return (result);
}

// Assuming the ft_split function and its helper functions are already defined above this line
int	main(void)
{
	char		**result;
	int			i;
	const char	*str;
	char		delimiter;

	i = 0;
	delimiter = ' ';
	str = "123 world";
	result = ft_split(str, delimiter);
	if (result == NULL)
	{
		printf("Error: ft_split returned NULL\n");
		return (1);
	}
	while (result[i] != NULL)
	{
		printf("result[%d]: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	// printf("result[%d]: %s\n", i, result[i]);
	printf("%s\n", result[0]);
	printf("%p\n", *result);
	free(result);
	return (0);
}
