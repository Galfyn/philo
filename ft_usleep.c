#include "philo.h"

void ft_usleep(int time_ms)
{
	long int stop;

	stop = get_time() + time_ms;
	while (get_time() < stop)
		usleep(100);
}