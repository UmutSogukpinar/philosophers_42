#include "philosophers.h"
#include "stdio.h"

t_bool	safe_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf(M_LOCK_ERR);
		printf("Error on \033[1;31m\"safe_lock()\"\033[0m function\n");
		return (c_false);
	}
	return (c_true);
}

t_bool	safe_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf(M_UNLCK_ERR);
		printf("Error on \033[1;31m\"safe_unlock()\"\033[0m function\n");
		return (c_false);
	}
	return (c_true);
}
