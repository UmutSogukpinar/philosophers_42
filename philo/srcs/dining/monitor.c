#include "philosophers.h"

void	*monitor(void *arg)
{
	t_table	*table;
	size_t	i;

	table = (t_table *)arg;
	i = 0;
	while (TRUE)
	{
		if (get_error_flag(table->shared_data, table->locks))
			break ;
		if (get_death_flag(table->shared_data, table->locks))
			break ;
		if (are_philos_satisfied(table))
			break ;
		if (is_any_philo_dead(table))
			break ;
	}
	return (NULL);
}

static t_bool	are_philos_satisfied(t_table *table)
{
	size_t	total_size;
	size_t	full_phils_size;
	size_t	i;

	total_size = table->number_of_phils;
	full_phils_size = 0;
	i = 0;
	while (i < total_size)
	{
		
	}
}
