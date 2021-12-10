/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:43:12 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/10 18:31:25 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *check_death(void *parametr)
{
	int 	i;
	t_param	*param;

	param = (t_param *)parametr;
	while (param->death != 1)
	{
		i = 0;
		while (i < param->nb_philo)
		{
			if (get_time() > param->philo[i].last_eat + param->die)
			{
				print_status("is DEAD", i, param, 0);
				param->death = 1;
				return (void*)(1);
			}
			if (param->nb_meals != -1 && param->nb_eat / param->nb_philo >=
			param->nb_meals)
			{
				printf("The philosophers finished their meal\n");
				return (void*)(1);
			}
			i++;
		}

	}
	return (NULL);
}

int main(int argc, char **argv)
{
	int			i;
	t_param		param;
	pthread_t	tid_death;

	i = 0;
	if (check_argv(argc, argv) == 0)
		return (error("Arguments specified incorrectly"));
	if (init(argc, argv, &param) == 0)
		return (error("Error"));
	if (handler(&param) == 0)
		return (error("Error"));
	pthread_create(&tid_death, NULL, check_death, &param);
	pthread_join(tid_death, NULL);
	pthread_detach(tid_death);
	while (i < param.nb_philo)
	{
		pthread_detach(param.philo[i].tid);
		free(&param.philo[i]);
		i++;
	}
}
