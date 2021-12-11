/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:02:01 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/11 12:03:57 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *str, int index, t_param *param, int flag)
{
	long int	time;

	time = get_time() - param->time_start;
	pthread_mutex_lock(&param->write_m);
	printf("%ld %d %s\n", time, index, str);
	if (flag != 0)
		pthread_mutex_unlock(&param->write_m);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->eating);
	pthread_mutex_lock(&philo->l_f);
	print_status("has taken a fork", philo->index, philo->param, 1);
	pthread_mutex_lock(philo->r_f);
	print_status("has taken a fork", philo->index, philo->param, 1);
	pthread_mutex_unlock(&philo->param->eating);
	philo->last_eat = get_time();
	print_status("is eating", philo->index, philo->param, 1);
	if (philo->param->nb_meals != -1)
	{
		philo->param->nb_eat++;
	}
	ft_usleep(philo->param->eat);
	pthread_mutex_unlock(&philo->l_f);
	pthread_mutex_unlock(philo->r_f);
}

void	*threade(void *philosopher)
{
	t_philo	*ph;

	ph = (t_philo *)philosopher;
	while (1)
	{
		if (ph->index % 2 == 0)
			usleep(1000);
		eating(ph);
		print_status("is sleeping", ph->index, ph->param, 1);
		ft_usleep(ph->param->sleep);
		print_status("is thinking", ph->index, ph->param, 1);
	}
}

int	handler(t_param *param)
{
	int	i;

	i = 0;
	param->time_start = get_time();
	while (i < param->nb_philo)
	{
		pthread_create(&(param->philo[i].tid), NULL, threade,
			&(param->philo[i]));
		i++;
	}
	return (1);
}
