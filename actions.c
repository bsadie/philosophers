#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_message(philo->info, philo->ph_id, MSG_FORK);
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_message(philo->info, philo->ph_id, MSG_FORK);
	philo->is_eating = 1;
	philo->time_last = get_time();
	print_message(philo->info, philo->ph_id, MSG_EAT);
	ft_usleep(philo->info->time_to_eat);
	if (philo->info->must_eat_times != -1)
		philo->eat_count++;
	if (philo->eat_count == philo->info->must_eat_times)
		philo->ate_enough = 1;
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	philo->is_eating = 0;
}

void	sleep_think(t_philo *philo)
{
	print_message(philo->info, philo->ph_id, MSG_SLEEP);
	ft_usleep(philo->info->time_to_sleep);
	print_message(philo->info, philo->ph_id, MSG_THINK);
}

void	*actions(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->time_last = get_time();
	while (1)
	{
		pthread_mutex_lock(&philo->info->check_dead);
		if (philo->info->dead || philo->ate_enough)
		{
			pthread_mutex_unlock(&philo->info->check_dead);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->info->check_dead);
		while (!philo->info->dead && !philo->ate_enough)
		{
			eat(philo);
			sleep_think(philo);
		}
	}
	return (NULL);
}
