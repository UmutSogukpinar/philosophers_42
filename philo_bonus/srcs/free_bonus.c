#include "philosophers_bonus.h"
#include "stdlib.h"

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
