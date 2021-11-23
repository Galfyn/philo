/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:25:04 by galfyn            #+#    #+#             */
/*   Updated: 2021/11/23 10:59:34 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int error(char *str)
{
	if (str)
	{
		printf("%s\n", str);
		printf("Example : (./philo number_of_philosophers time_to_die time_to_eat"
			   "time_to_sleep [number_of_times_each_philosopher_must_eat])")
	}
	return (2);
}

