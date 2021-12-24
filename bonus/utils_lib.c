/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:28:57 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/11 12:29:59 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int		negative;
	int		result;
	long	max_int;
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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
