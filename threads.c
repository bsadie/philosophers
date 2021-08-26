#include "philo.h"

int	create_odd_threads(t_philo *philos)
{
	pthread_t	thread;
	int			i;

	i = 0;
	while (i < philos[0].info->count)
	{
		if (i % 2 == 1)
		{
			if (pthread_create(&thread, NULL, actions, &philos[i]) != 0)
				return (-1);
			usleep(50);
		}
		i++;
	}
	return (1);
}

int	create_even_threads(t_philo *philos)
{
	pthread_t	thread;
	int			i;

	i = 0;
	while (i < philos[0].info->count)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&thread, NULL, actions, &philos[i]) != 0)
				return (-1);
			usleep(50);
		}
		i++;
	}
	return (1);
}
