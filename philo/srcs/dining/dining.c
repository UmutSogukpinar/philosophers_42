#include "philosophers.h"

t_bool	init_dining(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_phils)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &dining,
				&table->philos[i]) != SUCCESS)
		{
			set_error_flag(table, TRUE);
			display_err_msg(PHTREAD_CRT);
			return (FALSE);
		}
		i++;
	}
	i = 0;
	while (i < table->number_of_phils)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	return (TRUE);
}

void	*dining(void *arg)
{
	t_philo	*phil;

	phil = (t_philo *)arg;
}
