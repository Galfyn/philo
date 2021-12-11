/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:13:38 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/11 14:46:03 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_philo{
	long	last_eat;
	struct s_param *pr;
}t_philo;

typedef struct s_param{
	int 	nb_philo;
	int		died;
	int 	eat;
	int 	sleep;
	int 	nb_meals;
	sem_t	*fork;
	sem_t	*say;
	t_philo *ph;

}t_param;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
long	get_time(void);
void	error(char *str);
int		check_argv(int argc, char **argv);
void	init(int argc, char **argv, t_param *param);
#endif
