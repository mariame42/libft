/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:26:50 by meid              #+#    #+#             */
/*   Updated: 2024/07/17 19:09:49 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	arr = (void *)malloc(count * size);
	if (!(arr))
		return (NULL);
	ft_bzero(arr, (count * size));
	return (arr);
}