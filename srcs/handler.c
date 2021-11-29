/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:02:01 by galfyn            #+#    #+#             */
/*   Updated: 2021/11/29 13:45:05 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int init(t_general *struct_philo, int argc, char **argv, int i)
{
	struct_philo->number_philo = ft_atoi(argv[1]);
	struct_philo->time_to_die = ft_atoi(argv[2]);
	struct_philo->time_to_eat = ft_atoi(argv[3]);
	struct_philo->time_to_sleep = ft_atoi(argv[4]);
	struct_philo->number_of_meals = 0;
	if (argc == 6)
		struct_philo->number_of_meals = ft_atoi(argv[5]);
	struct_philo->philo = malloc(sizeof(t_philo) * struct_philo->number_philo);
	struct_philo->forks = malloc(sizeof(pthread_mutex_t) *
								  struct_philo->number_philo);
	if (!struct_philo->philo || !struct_philo->forks)
		return (error("Error: Allocated memory"));
	while (i < struct_philo->number_philo)
	{
		pthread_mutex_init(&struct_philo->forks[i], NULL);
		struct_philo->philo[i].index = i;
		struct_philo->philo[i].right_fork = i;
		struct_philo->philo[i].left_fork = i + 1;
		if (i == struct_philo->number_philo - 1)
			struct_philo->philo[i].left_fork = struct_philo->philo[0].right_fork;
		i++;
	}
	return (0);
}

//void eat(t_philo philo)
//{
//	
//}

void* operating(void* philo)
{
	t_philo *strct;

	strct = philo;
	if (strct->index % 2 == 0)
	{
		printf("My №%d, i am even %d\n",strct->index, strct->tid);
		pthread_mutex_lock(&strct->general->forks[strct->right_fork]);
		pthread_mutex_lock(&strct->general->forks[strct->left_fork]);
		printf("I am eat\n");
		sleep(strct->general->time_to_eat);
		pthread_mutex_unlock(&strct->general->forks[strct->right_fork]);
		pthread_mutex_unlock(&strct->general->forks[strct->left_fork]);
	}
	else
	{
		printf("My №%d, i am odd %d\n", strct->index, strct->tid);
		pthread_mutex_lock(&strct->general->forks[strct->right_fork]);
		pthread_mutex_lock(&strct->general->forks[strct->left_fork]);
		printf("I am eat\n");
		sleep(strct->general->time_to_eat);
		pthread_mutex_unlock(&strct->general->forks[strct->right_fork]);
		pthread_mutex_unlock(&strct->general->forks[strct->left_fork]);
	}
	return (1);
}
int handler(int argc, char **argv, t_general *general)
{
	int i;
	void* philo;

	i = 0;
	init(general, argc, argv, 0);
	gettimeofday(&general->time_start, NULL);
	while (i < general->number_philo)
	{
		philo = (void*)&general->philo[i];
		if (pthread_create(&general->philo[i].tid, NULL, &operating, philo)
		!= 0)
			return (0);
		usleep(100);
		i++;
	}
	return (1);
}
