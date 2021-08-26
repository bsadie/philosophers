#include "philo.h"

void	free_mutex(t_info *info)
{
	int	i;

	if (info->forks)
	{
		i = 0;
		while (i < info->count)
		{
			pthread_mutex_destroy(&info->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->check_dead);
	pthread_mutex_destroy(&info->check_meals);
}

void	free_info(t_info *info)
{
	if (info)
	{
		free(info->forks);
		free(info->philos);
	}
}
