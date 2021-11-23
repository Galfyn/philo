/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:12:29 by galfyn            #+#    #+#             */
/*   Updated: 2021/11/16 19:12:31 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int check_argv(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[i++])
	{
		j = 0;
		while (argv[i][j++])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
	}
	return (1);
}
