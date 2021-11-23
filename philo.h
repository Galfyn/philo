/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:43:58 by galfyn            #+#    #+#             */
/*   Updated: 2021/11/23 09:44:00 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_philo
{
	int 	number_philo;
	int		time_to_die;
	int 	time_to_eat;
	int 	time_to_sleep;
	int 	number_of_meals;
}			t_philo;

int check_argv(int argc, char **argv);
int error(char *str);
int handler(int argc, char **argv, t_philo *struct_philo);

#endif
