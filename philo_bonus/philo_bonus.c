/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:13:03 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/11 14:25:47 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char **argv)
{
	t_param	param;

	check_argv(argc, argv);
	init(argc, argv, &param);
}
