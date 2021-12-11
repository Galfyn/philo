/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <galfyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:46:03 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/11 11:07:19 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		negative;
	int		result;
	long 	max_int;
	int		i;

	negative = 1;
	result = 0;
	max_int = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]) == 1)
		++i;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		max_int = max_int * 10 + (str[i] - '0');
		++i;
	}
	if (max_int > 2147483647)
		return (-1);
	return (result * negative);
}
