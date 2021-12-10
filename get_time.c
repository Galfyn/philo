/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:05:09 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/10 16:05:08 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

long int get_time(void)
{
	long int		time;
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	return (time);
}