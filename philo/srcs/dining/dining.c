#include "philosophers.h"

static void		*dining(void *arg);
static void		join_philo_threads(t_table *table);
static t_bool	start_philo_threads(t_table *table);
static void		clean_broken_table(t_philo *philos, size_t index);

t_bool	init_dining(t_table *table)
{
	size_t	i;

	// table->milestone = get_timestamp(); // TODO: implement later
	while (i < table->number_of_phils)
	{
		table->philos[i].data.last_meal_time = table->milestone;
		table->philos[i].data.milestone = table->milestone;
		i++;
	}
	if (!start_philo_threads(table))
		return (FALSE);
	join_philo_threads(table);
	return (TRUE);
}

static t_bool	start_philo_threads(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_phils)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &dining,
				&table->philos[i]) != SUCCESS)
		{
			set_error_flag(table->shared_data, table->locks, TRUE);
			clean_broken_table(table->philos, i);
			return (display_err_msg(PHTREAD_CRT_ERR));
		}
		i++;
	}
	if (pthread_create(&table->monitor, NULL, &monitor, table) != SUCCESS)
	{
		set_error_flag(table->shared_data, table->locks, TRUE);
		return (display_err_msg(PHTREAD_CRT_ERR));
	}
	return (TRUE);
}

static void	join_philo_threads(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_phils)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->monitor, NULL);
}

static void	*dining(void *arg)
{
	t_philo	*phil;

	phil = (t_philo *)arg;
	if (get_error_flag(phil->shared_data, phil->locks))
		return (NULL);
	start_routine(phil);
	return (NULL);
}

static void	clean_broken_table(t_philo *philos, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		if (philos[i].thread)
			pthread_join(philos[i].thread, NULL);
		i++;
	}
}
