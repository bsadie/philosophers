#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;
	unsigned long	t;

	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (t);
}

void	ft_usleep(int miliseconds)
{
	unsigned long	time;

	time = get_time();
	while (get_time() < time + miliseconds)
		usleep(50);
}
