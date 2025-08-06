#include "philosophers.h"

t_bool	get_error_flag(t_table *table)
{
	t_bool	*error_flag;
	t_mutex	*lock;
	t_bool	value;

	error_flag = &table->shared_data->error_flag;
	lock = &table->locks->error;
	pthread_mutex_lock(lock);
	value = *error_flag;
	pthread_mutex_unlock(lock);
	return (value);
}

t_bool	get_death_flag(t_table *table)
{
	t_bool	*death_flag;
	t_mutex	*lock;
	t_bool	value;

	death_flag = &table->shared_data->does_death_exist;
	lock = &table->locks->death;
	pthread_mutex_lock(lock);
	value = *death_flag;
	pthread_mutex_unlock(lock);
	return (value);
}

t_bool	get_full_flag(t_table *table)
{
	t_bool	*full_flag;
	t_mutex	*lock;
	t_bool	value;

	full_flag = &table->shared_data->are_philos_full;
	lock = &table->locks->full;
	pthread_mutex_lock(lock);
	value = *full_flag;
	pthread_mutex_unlock(lock);
	return (value);
}
