/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:13:03 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/14 15:33:40 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	int i = 0;
	printf("%d\n", i);
	i++;
}

void create_procces(t_philo *philo)
{
	int pid;
	sem_t *sem;

	sem = sem_open("fork", O_CREAT, 0600, philo->pr->nb_philo);
	if (sem == SEM_FAILED)
	{
		perror("1");
		error("wds");
	}
	pid = fork();
	if (pid == -1)
		error("fork error");
	if (pid == 0)
		eat(philo);
}

int main(int argc, char **argv)
{
	t_param	param;
	sem_t *sem;
	int 	i;

	i = 0;
	check_argv(argc, argv);
	init(argc, argv, &param);
	sem = sem_open("fork", O_CREAT, 0600, param.nb_philo);
	if (sem == SEM_FAILED)
	{
		perror("create del");
		exit(1);
	}
	while (i < param.nb_philo)
	{
		create_procces(&param.ph[i]);
		i++;
	}
}
