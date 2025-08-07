#include "philosophers.h"

void	start_routine(t_philo *philo)
{
	while (TRUE)
	{
		if (!eating(philo))
			return ;
		if (!sleeping(philo))
			return ;
		if (!thinking(philo))
			return ;
	}
}

static	t_bool	thinking(t_philo *philo)
{
	return (display_status(philo, THINKING));
}

static	t_bool	sleeping(t_philo *philo)
{
	elapse_time(philo->data.sleep_time);
	return (display_status(philo, SLEEPING));
}
