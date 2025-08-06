#include "philosophers.h"

void	set_error_flag(t_table *table, t_bool result)
{
	t_bool	*error_flag;
	t_mutex	*lock;

	error_flag = &table->shared_data->error_flag;
	lock = &table->locks->error;
	pthread_mutex_lock(lock);
	*error_flag = result;
	pthread_mutex_unlock(lock);
}

void	set_death_flag(t_table *table, t_bool result)
{
	t_bool	*death_flag;
	t_mutex	*lock;
	
	death_flag = &table->shared_data->does_death_exist;
	lock = &table->locks->death;
	pthread_mutex_lock(lock);
	*death_flag = result;
	pthread_mutex_unlock(lock);
}

void	set_full_flag(t_table *table, t_bool result)
{
	t_bool	*full_flag;
	t_mutex	*lock;

	full_flag = &table->shared_data->are_philos_full;
	lock = &table->locks->death;
	pthread_mutex_lock(lock);
	*full_flag = result;
	pthread_mutex_unlock(lock);
}
