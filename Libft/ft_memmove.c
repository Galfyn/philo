/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <galfyn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:49:34 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/21 01:18:33 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	i;

	i = 0;
	destination = (char *)dest;
	source = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (destination < source)
	{
		while (n--)
		{
			destination[i] = source[i];
			i++;
		}
	}
	else
	{
		while (n--)
			destination[n] = source[n];
	}
	return (dest);
}
