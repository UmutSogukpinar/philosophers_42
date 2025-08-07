#include "philosophers.h"
#include "unistd.h"

static t_bool	is_any_philo_dead(t_table *table);
static t_bool	are_philos_satisfied(t_table *table);
static t_ms		get_last_meal_time(t_philo *philo);

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
		if (are_philos_satisfied(table))
		{
			set_full_flag(table->shared_data, table->locks, TRUE);
			break ;
		}
		if (is_any_philo_dead(table))
		{
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

static t_bool	are_philos_satisfied(t_table *table)
{
	size_t	total_size;
	size_t	full_phils_size;
	size_t	i;
	t_bool	*is_full;

	total_size = table->data.number_of_phils;
	full_phils_size = 0;
	i = 0;
	while (i < total_size)
	{
		is_full = &table->philos[i].is_full;
		lock_the_mutex(&table->locks->full);
		if (*is_full)
			full_phils_size += 1;
		unlock_the_mutex(&table->locks->full);
		i++;
	}
	return (full_phils_size == total_size);
}

static t_bool	is_any_philo_dead(t_table *table)
{
	size_t	i;
	t_ms	now;
	t_ms	time_since_last_meal;
	t_philo	*philo;

	i = 0;
	while (i < table->data.number_of_phils)
	{
		philo = &table->philos[i];
		now = get_timestamp(table->shared_data, table->locks);
		time_since_last_meal = now - get_last_meal_time(philo);
		if (time_since_last_meal > table->data.lifetime)
		{
			display_status(philo, DEAD);
			set_death_flag(table->shared_data, table->locks, TRUE);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static t_ms	get_last_meal_time(t_philo *philo)
{
	t_ms	*ref;
	t_ms	value;

	ref = &philo->data.last_meal_time;
	pthread_mutex_lock(&philo->locks->meal);
	value = *ref;
	pthread_mutex_unlock(&philo->locks->meal);
	return (value);
}
