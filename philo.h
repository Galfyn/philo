/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:43:58 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/24 07:39:35 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t		l_f;
	pthread_mutex_t		*r_f;
	int					index;
	int					count_eat;
	long				last_eat;
	struct s_param		*param;
}						t_philo;

typedef struct s_param
{
	int				nb_philo;
	int				die;
	int				eat;
	int				sleep;
	int				nb_meals;
	long			time_start;
	pthread_mutex_t	write_m;
	t_philo			*philo;
}					t_param;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		check_argv(int argc, char **argv);
int		error(char *str);
long	get_time(long time_start);
void	ft_usleep(int time_ms);
void	ft_putnbr(long n);
int		init( int argc, char **argv, t_param *param);
void	*thread(void *philosopher);

#endif
