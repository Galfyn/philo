/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:18:56 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/10 17:09:47 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int init_philo(t_param *param)
{
	int	i;

	i = 0;
	param->philo = (t_philo*) malloc(sizeof(t_philo) * param->nb_philo);
	if (!param->philo)
		return (error("Error allocated memory"));
	while (i < param->nb_philo)
	{
		param->philo[i].last_eat = param->time_start;
		param->philo[i].index = i + 1;
		param->philo[i].r_f = NULL;
		param->philo[i].param = param;
		if (pthread_mutex_init(&param->philo[i].l_f, NULL) != 0)
			return (0);
		if (i == param->nb_philo - 1)
			param->philo[i].r_f = &param->philo[0].l_f;
		else
			param->philo[i].r_f = &param->philo[i + 1].l_f;
		i++;
	}
	return (1);
}


int	init(int argc, char **argv, t_param *param)
{
	if (pthread_mutex_init(&param->write_m, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&param->eating, NULL) != 0)
		return (0);

	param->nb_philo = ft_atoi(argv[1]);
	param->die = ft_atoi(argv[2]);
	param->eat = ft_atoi(argv[3]);
	param->sleep = ft_atoi(argv[4]);
	param->dead_index = -1;
	param->nb_eat = 0;
	param->time_start = get_time();
	param->death = 0;
	param->nb_meals = -1;
	if (argc == 6)
		param->nb_meals = ft_atoi(argv[5]);
	if (init_philo(param) == 0)
		return (0);
	return (1);
}
