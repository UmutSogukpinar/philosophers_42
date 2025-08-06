#include "philosophers.h"

void	set_error_flag(t_shared_data *data, t_locks *locks, t_bool result)
{
	t_bool	*error_flag;
	t_mutex	*lock;

	error_flag = &data->error_flag;
	lock = &locks->error;
	pthread_mutex_lock(lock);
	*error_flag = result;
	pthread_mutex_unlock(lock);
}

void	set_death_flag(t_shared_data *data, t_locks *locks, t_bool result)
{
	t_bool	*death_flag;
	t_mutex	*lock;
	
	death_flag = &data->does_death_exist;
	lock = &locks->death;
	pthread_mutex_lock(lock);
	*death_flag = result;
	pthread_mutex_unlock(lock);
}

void	set_full_flag(t_shared_data *data, t_locks *locks, t_bool result)
{
	t_bool	*full_flag;
	t_mutex	*lock;

	full_flag = &data->are_philos_full;
	lock = &locks->full;
	pthread_mutex_lock(lock);
	*full_flag = result;
	pthread_mutex_unlock(lock);
}
