/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:43:12 by galfyn            #+#    #+#             */
/*   Updated: 2021/11/23 09:43:14 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
	t_philo struct_philo;

	if (check_argv(argc, argv) == 0)
		return (error("Arguments specified incorrectly"));
	handler(argc, argv, &struct_philo);
}
