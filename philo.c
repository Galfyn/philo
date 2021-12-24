/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:43:12 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/24 08:56:25 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	count_meals(t_param *prm, t_philo philo, int *eating)
{
	if (prm->nb_meals > 0 && philo.count_eat == prm->nb_meals)
		++*eating;
	if (*eating == prm->nb_meals)
	{
		pthread_mutex_lock(&prm->write_m);
		printf("The philosophers finished their meal\n");
		return (1);
	}
	return (0);
}

static void	*check_death(void *parametr)
{
	int		i;
	int		eating;
	t_param	*prm;

	eating = 0;
	prm = (t_param *)parametr;
	while (1)
	{
		i = -1;
		usleep(10);
		while (++i < prm->nb_philo)
		{
			if (get_time(prm->time_start) > prm->philo[i].last_eat + prm->die)
			{
				pthread_mutex_lock(&prm->write_m);
				printf("%ld %d died", get_time(prm->time_start), i + 1);
				return ((void *)1);
			}
			if (count_meals(prm, prm->philo[i], &eating) == 1)
				return ((void *)2);
		}
	}
}

static void	create_pthread(t_param *prm)
{
	int			i;
	pthread_t	*tid;

	i = 0;
	tid = malloc(sizeof(pthread_t) * prm->nb_philo);
	if (!tid)
		error("Error: Alocated memory");
	while (i < prm->nb_philo)
	{
		pthread_create(&tid[i], NULL, thread, &prm->philo[i]);
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
