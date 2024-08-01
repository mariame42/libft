/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 06:43:55 by meid              #+#    #+#             */
/*   Updated: 2024/07/17 16:05:12 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char str[20];

// 	strcpy(str, "mariam");
// 	ft_bzero(str, 3);
// 	printf("|%s|\n", str+3);
// }