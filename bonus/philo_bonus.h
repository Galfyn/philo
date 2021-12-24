/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:13:38 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/24 04:42:50 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_param{
	int		index;
	int		nb_philo;
	int		died;
	int		eat;
	int		sleep;
	int		nb_meals;
	long	t_start;
	long	last_eat;
	sem_t	*fork;
	sem_t	*say;
	pid_t	*pid;
}			t_param;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	error(char *str);
void	ft_usleep(int time_ms);
long	get_time(long time_star);
int		check_argv(int argc, char **argv);
void	init(int argc, char **argv, t_param *param);
#endif
