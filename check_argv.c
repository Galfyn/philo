/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:12:29 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/11 12:17:57 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	int	number_philo;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '\0')
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	number_philo = ft_atoi(argv[1]);
	if (number_philo == 0 || number_philo > 200)
		return (error("philosophers can be from 1 to 200"));
	return (1);
}
