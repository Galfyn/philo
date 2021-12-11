/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:12:29 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/11 14:20:55 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	int	number_philo;

	i = 1;
	if (argc < 5 || argc > 6)
		error("arguments 5 or 6");
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '\0')
				error("Not number");
			j++;
		}
		if (ft_atoi(argv[i]) <= 0)
			error("Not valid number");
		i++;
	}
	number_philo = ft_atoi(argv[1]);
	if (number_philo > 200)
		error("philosopher 1 - 200");
	return (1);
}
