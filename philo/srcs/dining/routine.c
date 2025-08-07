#include "philosophers.h"

static t_bool	sleeping(t_philo *philo);
static t_bool	thinking(t_philo *philo);

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

static t_bool	sleeping(t_philo *philo)
{
	if (!display_status(philo, SLEEPING))
		return (FALSE);
	elapse_time(philo->shared_data, philo->locks, philo->data.sleep_time);
	return (TRUE);
}

static t_bool	thinking(t_philo *philo)
{
	return (display_status(philo, THINKING));
}
