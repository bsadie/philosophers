#include "philo.h"

int	init_threads(t_philo *philos)
{
	if (create_even_threads(philos) < 0)
		return (-1);
	if (create_odd_threads(philos) < 0)
		return (-1);
	return (1);
}

int	init_mutex(pthread_mutex_t *forks, int num_forks)
{
	int	i;

	i = 0;
	while (i < num_forks)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (-1);
		i++;
	}
	return (1);
}

int	init_philos(t_info *info)
{
	int	i;

	i = 0;
	info->philos = malloc(sizeof(t_philo) * info->count);
	if (!info->philos)
		return (-1);
	while (i < info->count)
	{
		info->philos[i].info = info;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->count;
		info->philos[i].ph_id = i + 1;
		info->philos[i].eat_count = 0;
		info->philos[i].is_eating = 0;
		info->philos[i].is_dead = 0;
		info->philos[i].ate_enough = 0;
		i++;
	}
	info->time_start = get_time();
	info->dead = 0;
	return (1);
}

int	init_all(t_info *info)
{
	info->forks = malloc(sizeof(pthread_mutex_t) * info->count);
	if (!info->forks)
		return (-1);
	if (init_mutex(info->forks, info->count) < 0)
		return (-1);
	if (pthread_mutex_init(&info->print, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&info->check_dead, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&info->check_meals, NULL) != 0)
		return (-1);
	if (init_philos(info) < 0)
		return (-1);
	return (init_threads(info->philos));
}
