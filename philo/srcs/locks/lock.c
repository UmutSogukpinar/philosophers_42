#include "philosophers.h"

void	lock_the_mutex(t_mutex *lock)
{
	pthread_mutex_lock(lock);
}

void	unlock_the_mutex(t_mutex *lock)
{
	pthread_mutex_unlock(lock);
}
