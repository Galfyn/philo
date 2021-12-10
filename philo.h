/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:43:58 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/10 17:09:47 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int 				index;
	pthread_t			tid;
	pthread_mutex_t		l_f;
	pthread_mutex_t		*r_f;
	long int			last_eat;
	struct s_param		*param;
}						t_philo;

typedef struct s_param
{
	long 			nb_philo;
	long 			die;
	long 			eat;
	long 			sleep;
	long 			nb_meals;
	int 			dead_index;
	int 			nb_eat;
	int 			death;
	long int		time_start;
	pthread_mutex_t write_m;
	pthread_mutex_t eating;
	t_philo			*philo;
}					t_param;





int check_argv(int argc, char **argv);
int error(char *str);
long int get_time(void);
void ft_usleep(int time_ms);
int handler(t_param *param);
void print_status(char *str, int index, t_param *param, int flag);
int	init( int argc, char **argv, t_param *param);

#endif
