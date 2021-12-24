/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 04:40:19 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/24 04:41:34 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	end(t_param *param)
{
	int	status;
	int	j;

	status = 0;
	j = 0;
	while (j < param->nb_philo)
	{
		wait(&status);
		if (status)
		{
			while (j < param->nb_philo)
				kill(param->pid[j++], SIGTERM);
			break ;
		}
		j++;
		if (j == param->nb_philo && status == EXIT_SUCCESS)
			printf("%ld Finish \n", get_time(param->t_start));
	}
	sem_close(param->fork);
	sem_close(param->say);
	free(param->pid);
}

static void	*check_death(void *param)
{
	t_param	*prm;

	prm = (t_param *)param;
	while (1)
	{
		if (get_time(prm->t_start) > prm->last_eat + prm->died)
		{
			sem_wait(prm->say);
			printf("%ld %d died\n", get_time(prm->t_start), prm->index);
			break ;
		}
		usleep(500);
	}
	exit(EXIT_FAILURE);
}

static void	eat(t_param *param)
{
	sem_wait(param->fork);
	sem_wait(param->say);
	printf("%ld %d has taken a fork\n", get_time(param->t_start), param->index);
	sem_post(param->say);
	sem_wait(param->fork);
	sem_wait(param->say);
	printf("%ld %d has taken a fork\n", get_time(param->t_start), param->index);
	sem_post(param->say);
	sem_wait(param->say);
	printf("%ld %d has eating\n", get_time(param->t_start), param->index);
	sem_post(param->say);
	if (param->nb_meals > 0)
		param->nb_meals--;
	param->last_eat = get_time(param->t_start);
	ft_usleep(param->eat);
	sem_post(param->fork);
	sem_post(param->fork);
	sem_wait(param->say);
	printf("%ld %d has sleeping\n", get_time(param->t_start), param->index);
	sem_post(param->say);
	ft_usleep(param->sleep);
	sem_wait(param->say);
	printf("%ld %d has thinking\n", get_time(param->t_start), param->index);
	sem_post(param->say);
}

static void	child_process(t_param *param)
{
	pthread_t	death;

	pthread_create(&death, NULL, check_death, param);
	pthread_detach(death);
	while (1)
	{
		eat(param);
		if (param->nb_meals == 0)
			break ;
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	t_param	param;

	i = 0;
	check_argv(argc, argv);
	init(argc, argv, &param);
	while (i < param.nb_philo)
	{
		param.index = i + 1;
		param.pid[i] = fork();
		if (param.pid[i] == 0)
			child_process(&param);
		i++;
	}
	end(&param);
	exit(EXIT_SUCCESS);
}
