/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:30:04 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/17 20:09:15 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	int	number_philo;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '\0')
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	number_philo = ft_atoi(argv[1]);
	if (number_philo == 0 || number_philo > 200)
		return (error("philosophers can be from 1 to 200"));
	return (1);
}

int	error(char *str)
{
	if (str)
		printf("Error: %s\n", str);
	return (0);
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
