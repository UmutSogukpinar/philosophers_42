#include "philosophers.h"

static t_bool	one_philo_eating(t_philo *philo);
static t_bool	pick_up_fork(t_philo *philo);
static void		put_down_fork(t_philo *philo);
static void	check_satisfaction(t_philo *philo);

t_bool	eating(t_philo *philo)
{
	t_ms	*meal_time_ref;

	if (philo->data.number_of_phils == 1)
		return (one_philo_eating(philo));
	if (!pick_up_fork(philo))
		return (FALSE);
	if (!display_status(philo, EATING))
	{
		put_down_fork(philo);
		return (FALSE);
	}
	elapse_time(philo->shared_data, philo->locks, philo->data.meal_time);
	meal_time_ref = &philo->data.last_meal_time; 
	pthread_mutex_lock(&philo->locks->meal);
	*meal_time_ref = get_timestamp(philo->shared_data, philo->locks);
	philo->data.number_eat += 1;
	pthread_mutex_unlock(&philo->locks->meal);
	check_satisfaction(philo);
	put_down_fork(philo);
	return (TRUE);
}

static t_bool	one_philo_eating(t_philo *philo)
{
	display_status(philo, PICKING_UP_FORK);
	return (FALSE);
}

static t_bool	pick_up_fork(t_philo *philo)
{
	lock_the_mutex(philo->first_fork);
	lock_the_mutex(philo->last_fork);
	if (!display_status(philo, PICKING_UP_FORK) || !display_status(philo,
			PICKING_UP_FORK))
	{
		put_down_fork(philo);
		return (FALSE);
	}
	return (TRUE);
}

static void	put_down_fork(t_philo *philo)
{
	unlock_the_mutex(philo->last_fork);
	unlock_the_mutex(philo->first_fork);
}

static void	check_satisfaction(t_philo *philo)
{
	if (philo->data.eat_limit == -1)
		return ;
	if (philo->data.number_eat >= philo->data.eat_limit)
	{
		pthread_mutex_lock(&philo->locks->full);
		philo->is_full = TRUE;
		pthread_mutex_unlock(&philo->locks->full);
	}
}

