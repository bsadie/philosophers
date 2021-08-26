#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define MSG_ERR_ARGC "must be 4 or 5 args"
# define MSG_ERR_ARGS "invalid args"
# define MSG_ERR_INIT "init error"
# define MSG_FORK "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIED "died"
# define MSG_ENOUGH "meals count over"

typedef struct s_info
{
	int					count;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_times;
	unsigned long		time_start;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		check_dead;
	pthread_mutex_t		check_meals;
	int					dead;
	struct s_philo		*philos;
}			t_info;

typedef struct s_philo
{
	t_info			*info;
	int				left_fork;
	int				right_fork;
	unsigned long	time_start;
	unsigned long	time_last;
	int				is_eating;
	int				is_dead;
	int				ate_enough;
	int				eat_count;
	int				ph_id;
}			t_philo;

int				is_digits(const char *str);
int				ft_error(const char *str);
int				ft_atoi(const char *str);
void			ft_usleep(int miliseconds);
void			print_message(t_info *info, int ph_id, const char *str);
unsigned long	get_time(void);

int				check_params(t_info *info, char *argv[]);
int				init_all(t_info *info);
int				create_odd_threads(t_philo *philos);
int				create_even_threads(t_philo *philos);
void			sleep_think(t_philo *philo);
void			*actions(void *args);
void			check_philos(t_info *info);

void			free_mutex(t_info *info);
void			free_info(t_info *info);

#endif
