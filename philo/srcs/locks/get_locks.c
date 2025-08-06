#include "philosophers.h"

t_bool	get_error_flag(t_shared_data *data, t_locks *locks)
{
	t_bool	*error_flag;
	t_mutex	*lock;
	t_bool	value;

	error_flag = &data->error_flag;
	lock = &locks->error;
	pthread_mutex_lock(lock);
	value = *error_flag;
	pthread_mutex_unlock(lock);
	return (value);
}

t_bool	get_death_flag(t_shared_data *data, t_locks *locks)
{
	t_bool	*death_flag;
	t_mutex	*lock;
	t_bool	value;

	death_flag = &data->does_death_exist;
	lock = &locks->death;
	pthread_mutex_lock(lock);
	value = *death_flag;
	pthread_mutex_unlock(lock);
	return (value);
}

t_bool	get_full_flag(t_shared_data *data, t_locks *locks)
{
	t_bool	*full_flag;
	t_mutex	*lock;
	t_bool	value;

	full_flag = &data->are_philos_full;
	lock = &locks->full;
	pthread_mutex_lock(lock);
	value = *full_flag;
	pthread_mutex_unlock(lock);
	return (value);
}
