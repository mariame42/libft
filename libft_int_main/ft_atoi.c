/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:09:19 by meid              #+#    #+#             */
/*   Updated: 2024/07/17 15:13:53 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] && str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (sign == -1 && res >= 9223372036854775808LLU)
		return (0);
	if (res >= __LONG_LONG_MAX__ && sign != -1)
		return (-1);
	return (sign * (int)res);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_atoi("486356"));
// 	printf("%d\n", ft_atoi("-486356"));
// 	printf("%d\n", ft_atoi("92233720368547758086"));
// 	printf("%d\n", atoi("486356"));
// 	printf("%d\n", atoi("-486356"));
// 	printf("%d\n", atoi("92233720368547758086"));
// }
