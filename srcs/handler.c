/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:02:01 by galfyn            #+#    #+#             */
/*   Updated: 2021/11/18 13:17:50 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void init(t_philo *struct_philo, int argc, char **argv)
{
	struct_philo->number_philo = ft_atoi(argv[1]);
	struct_philo->time_to_die = ft_atoi(argv[2]);
	struct_philo->time_to_eat = ft_atoi(argv[3]);
	struct_philo->time_to_sleep = ft_atoi(argv[4]);
	struct_philo->number_of_meals = 0;
	if (argc == 6)
		struct_philo->number_of_meals = ft_atoi(argv[5]);
}

int handler(int argc, char **argv, t_philo *struct_philo)
{
	init(struct_philo, argc, argv);

	return (1);
}
