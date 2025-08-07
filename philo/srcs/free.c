#include "philosophers.h"
#include "stdlib.h"

static void	free_mutex(pthread_mutex_t *mtx, t_bool *is_init);
static void	free_locks(t_locks *locks);
static void	free_philos(t_philo	*philos);

void	free_table(t_table *table)
{
	if (!table)
		return ;
	free_locks(table->locks);
	table->locks = NULL;
	free(table->shared_data);
	table->shared_data = NULL;
	free_philos(table->philos);
	free(table);
}

static void	free_locks(t_locks *locks)
{
	if (!locks)
		return ;
	free_mutex(&locks->meal, &locks->meal_init);
	free_mutex(&locks->full, &locks->full_init);
	free_mutex(&locks->death, &locks->death_init);
	free_mutex(&locks->print, &locks->print_init);
	free_mutex(&locks->error, &locks->error_init);
	free(locks);
}

static void	free_mutex(pthread_mutex_t *mtx, t_bool *is_init)
{
	if (*is_init)
	{
		if (pthread_mutex_destroy(mtx) != SUCCESS)
			display_err_msg(MTX_DSTRY_ERR);
	}
}

static void	free_philos(t_philo	*philos)
{
	size_t	i;
	size_t	len;

	if (!philos)
		return ;
	len = philos[0].data.number_of_phils;
	i = 0;
	while (i < len)
	{
		if (philos[i].right_fork)
		{
			pthread_mutex_destroy(philos[i].right_fork);
			free(philos[i].right_fork);
		}
		philos[i].right_fork = NULL;
		philos[i].left_fork = NULL;
		philos[i].first_fork = NULL;
		philos[i].last_fork = NULL;
		philos[i].shared_data = NULL;
		philos[i].locks = NULL;
		i++;
	}
	free(philos);
}
