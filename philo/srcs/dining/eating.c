#include "philosophers.h"

static t_bool	pick_up_fork(t_philo *philo);
static void		put_down_fork(t_philo *philo);

t_bool	eating(t_philo *philo)
{
	if (!pick_up_fork(philo))
		return (FALSE);
	if (!display_status(philo, EATING))
	{
		put_down_fork(philo);
		return (FALSE);
	}
	elapse_time(philo->data.meal_time);
	display_status(philo, EATING);
	philo->data.last_meal_time = get_timestamp(philo->shared_data,
			philo->locks);
	philo->data.number_eat += 1;
	put_down_fork(philo);
	return (TRUE);
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
