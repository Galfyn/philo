/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:25:50 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/11 14:25:51 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void init_philo(t_param *param)
{
	param->ph = (t_philo *) malloc(sizeof(t_philo) * param->nb_philo);
	if (!param->ph)
		error("Allocated memory");

}

void init(int argc, char **argv, t_param *param)
{
	param->nb_philo = ft_atoi(argv[1]);
	param->died = ft_atoi(argv[2]);
	param->eat = ft_atoi(argv[3]);
	param->sleep = ft_atoi(argv[4]);
	param->nb_meals = -1;
	if (argc == 6)
		param->nb_meals = ft_atoi(argv[5]);

	init_philo(param);
}
