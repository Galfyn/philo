/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:43:58 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/17 17:54:18 by galfyn           ###   ########.fr       */
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
	long				last_eat;
	struct s_param		*param;
}						t_philo;

typedef struct s_param
{
	int				nb_philo;
	int				die;
	int				eat;
	int 			sleep;
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
int		handler(t_param *param);
void	print_status(char *str, int index, t_param *param, int flag);
int		init( int argc, char **argv, t_param *param);

_Noreturn void	*threade(void *philosopher);

#endif
