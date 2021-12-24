/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:38:15 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/24 04:42:26 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init(int argc, char **argv, t_param *param)
{
	param->nb_philo = ft_atoi(argv[1]);
	param->died = ft_atoi(argv[2]);
	param->eat = ft_atoi(argv[3]);
	param->sleep = ft_atoi(argv[4]);
	param->nb_meals = -1;
	if (argc == 6)
		param->nb_meals = ft_atoi(argv[5]);
	param->t_start = get_time(0);
	param->last_eat = get_time(param->t_start);
	sem_unlink("fork");
	sem_unlink("say");
	param->fork = sem_open("fork", O_CREAT, 0600, param->nb_philo);
	param->say = sem_open("say", O_CREAT, 0600, 1);
	param->pid = (pid_t *) malloc(sizeof (pid_t) * param->nb_philo);
	if (!param->pid)
		error("Allocated memory");
}

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

long	get_time(long time_star)
{
	long			time;
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000) - time_star;
	return (time);
}

void	ft_usleep(int time_ms)
{
	long	stop;

	stop = get_time(time_ms) + time_ms;
	while (get_time(time_ms) < stop)
		usleep(200);
}

void	error(char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}
