#include "philo.h"

int	valid_params(t_info *info)
{
	if (info->count <= 0 \
		|| info->time_to_die <= 0 \
		|| info->time_to_eat <= 0 \
		|| info->time_to_sleep <= 0 \
		|| (info->must_eat_times <= 0 && info->must_eat_times != -1))
		return (ft_error("Args must be positive"));
	if (info->count > 200)
		return (ft_error("Must be 1 - 200 philos"));
	if (info->time_to_die < 60 \
		|| info->time_to_eat < 60 \
		|| info->time_to_sleep < 60)
		return (ft_error("Time args must be > 60 ms"));
	return (1);
}

int	check_params(t_info *info, char *argv[])
{
	if (!is_digits(argv[1]) || !is_digits(argv[2]) \
		|| !is_digits(argv[3]) || !is_digits(argv[4]))
		return (-1);
	if (argv[5])
	{
		if (!is_digits(argv[5]))
			return (-1);
	}
	info->count = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->must_eat_times = ft_atoi(argv[5]);
	else
		info->must_eat_times = -1;
	return (valid_params(info));
}

int	check_alive(t_info *info, int i)
{
	pthread_mutex_lock(&info->check_dead);
	if (!info->philos[i].is_eating \
		&& info->philos[i].time_last + info->time_to_die < get_time())
	{
		info->dead = 1;
		pthread_mutex_unlock(&info->check_dead);
		return (0);
	}
	pthread_mutex_unlock(&info->check_dead);
	return (1);
}

void	check_philos(t_info *info)
{
	int	i;
	int	end;

	while (1)
	{
		i = 0;
		end = 0;
		while (i < info->count)
		{
			if (!check_alive(info, i))
			{
				print_message(info, info->philos[i].ph_id, MSG_DIED);
				return ;
			}
			if (info->philos[i].ate_enough)
				end++;
			if (end == info->count)
			{
				print_message(info, 0, MSG_ENOUGH);
				return ;
			}
			i++;
		}
	}
}
