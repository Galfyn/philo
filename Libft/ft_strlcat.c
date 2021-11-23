/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <galfyn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:52:03 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/21 01:18:33 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;
	size_t	ret;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size > len_d || len_d == len_s)
		ret = (len_d + len_s);
	else
		ret = (len_s + size);
	while (src[i] && (len_d + 1) < size)
	{
		dst[len_d] = src[i];
		len_d++;
		i++;
	}
	dst[len_d] = '\0';
	return (ret);
}
