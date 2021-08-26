#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (ft_error(MSG_ERR_ARGC));
	if (check_params(&info, argv) < 0)
		return (ft_error(MSG_ERR_ARGS));
	if (init_all(&info) < 0)
		return (ft_error(MSG_ERR_INIT));
	check_philos(&info);
	ft_usleep(500);
	free_mutex(&info);
	free_info(&info);
	return (0);
}
