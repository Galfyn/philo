/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threade.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:34:45 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/24 04:50:04 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(long time, int index, char *str, int len)
{
	ft_putnbr(get_time(time));
	write(1, " ", 1);
	ft_putnbr(index);
	write(1, str, len);
}

static void	take_fork(t_param *prm, t_philo *ph)
{
	pthread_mutex_lock(&ph->l_f);
	pthread_mutex_lock(&prm->write_m);
	print_status(prm->time_start, ph->index, " has taken a fork\n", 18);
	pthread_mutex_unlock(&prm->write_m);
	pthread_mutex_lock(ph->r_f);
	pthread_mutex_lock(&prm->write_m);
	print_status(prm->time_start, ph->index, " has taken a fork\n", 18);
	pthread_mutex_unlock(&prm->write_m);
}

static void	eat(t_param *prm, t_philo *ph)
{
	ph->last_eat = get_time(prm->time_start);
	if (prm->nb_meals > 0)
		prm->philo->count_eat++;
	pthread_mutex_lock(&prm->write_m);
	print_status(prm->time_start, ph->index, " is eating\n", 11);
	pthread_mutex_unlock(&prm->write_m);
	ft_usleep(prm->eat);
	pthread_mutex_unlock(&ph->l_f);
	pthread_mutex_unlock(ph->r_f);
}

static void	sleep_think(t_param *prm, t_philo *ph)
{
	pthread_mutex_lock(&prm->write_m);
	print_status(prm->time_start, ph->index, " is sleeping\n", 13);
	pthread_mutex_unlock(&prm->write_m);
	ft_usleep(prm->sleep);
	pthread_mutex_lock(&prm->write_m);
	print_status(prm->time_start, ph->index, " is thinking\n", 13);
	pthread_mutex_unlock(&prm->write_m);
}

void	*thread(void *philosopher)
{
	t_philo	*ph;
	t_param	*param;

	ph = (t_philo *)philosopher;
	param = ph->param;
	if (ph->index % 2 == 0)
		ft_usleep(3);
	while (1)
	{
		if (ph->index % 2 == 0)
			usleep(200);
		take_fork(param, ph);
		eat(param, ph);
		sleep_think(param, ph);
		if (param->philo->count_eat == param->nb_meals)
			break ;
	}
	return (NULL);
}
