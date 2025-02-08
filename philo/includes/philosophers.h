#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

# define DEATH_MSG "died\n"
# define FORK_MSG "has taken a fork\n"
# define EAT_MSG "is eating\n"
# define SLEEP_MSG "is sleeping\n"
# define THINK_MSG "is thinking\n"

# define ALLOC_ERR "Allocation error occured\n"
# define INV_ARGN "Invalid number of arguments\n"
# define INV_ARGS "There is/are invalid argument value at least\n"
# define M_LOCK_ERR "pthread_mutex_lock function doesn't work as expected\n"
# define M_UNLCK_ERR "pthread_mutex_unlock function doesn't work as expected\n"

typedef enum	e_bool
{
	c_true = 1,
	c_false = 0
}				t_bool;

typedef enum	e_status
{
	c_eating = 3,
	c_thinking = 2,
	c_sleeping = 1,
	c_exit = 0
}				t_status;

typedef struct	s_lock
{
	pthread_mutex_t	lock;

}				t_lock;

typedef	struct	s_fork
{
	int				id;
	t_bool			is_free;

}				t_fork;

typedef struct	s_data
{
	int					number_phils;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_limit;
	int					number_full_phils;
	long long			start_time;
	t_bool				death_flag;
	t_bool				eat_limit_flag;
	t_lock				meal_lock;
	t_lock				dead_lock;
	t_lock				waiter_lock;

}					t_data;

typedef struct	s_philo
{
	int					id;
	int					eaten_amount;
	long long			last_meal_time;
	t_status			status;
	t_fork				*left_fork;
	t_fork				*right_fork;
	t_data				*data;
	pthread_t			thread;	

}					t_philo;

typedef struct	s_greece
{
	t_philo			**table;
	t_data			*data;

}					t_greece;

t_data		*init_data(int argn, char **args);
t_greece	*init_ancient_greece(t_data *data);

void		start_dining(t_greece *ionia);
void		*routine(void *arg);

t_bool		safe_lock(pthread_mutex_t *mutex);
t_bool		safe_unlock(pthread_mutex_t *mutex);


#endif
