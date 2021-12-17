/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:43:12 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/17 19:56:32 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *parametr)
{
	int		i;
	t_param	*prm;

	prm = (t_param *)parametr;
	while (1)
	{
		i = 0;
		usleep(10);
		while (i < prm->nb_philo)
		{
			if (get_time(prm->time_start) > prm->philo[i].last_eat + prm->die)
			{
				pthread_mutex_lock(&prm->write_m);
				printf("%ld %d is die \n", get_time(prm->time_start), i + 1);
				return ((void *)1);
			}
			if (prm->nb_meals == 0)
			{
				pthread_mutex_lock(&prm->write_m);
				printf("The philosophers finished their meal\n");
				return ((void *)1);
			}
			i++;
		}
	}
}

void	create_pthread(t_param *prm)
{
	int			i;
	pthread_t	*tid;

	i = 0;
	tid = malloc(sizeof(pthread_t) * prm->nb_philo);
	if (!tid)
		error("Error: Alocated memory");
	while (i < prm->nb_philo)
	{
		pthread_create(&tid[i], NULL, threade, &prm->philo[i]);
		pthread_detach(tid[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_param		prm;
	pthread_t	tid_death;

	i = 0;
	if (check_argv(argc, argv) == 0)
		return (error("Arguments specified incorrectly"));
	if (init(argc, argv, &prm) == 0)
		return (error("Error"));
	create_pthread(&prm);
	pthread_create(&tid_death, NULL, check_death, &prm);
	pthread_join(tid_death, NULL);
	ft_usleep(10);
	while (i < prm.nb_philo)
	{
		pthread_mutex_destroy(&prm.philo[i].l_f);
		i++;
	}
	pthread_mutex_destroy(&prm.write_m);
	return (0);
}
