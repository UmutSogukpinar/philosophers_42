#include "philosophers.h"

static void	pick_up_fork(t_philo *philo);
static void	put_down_fork(t_philo *philo);

void	start_dining(t_philo *philo)
{

}

static void	eating(t_philo *philo)
{
	pick_up_fork(philo);

	put_down_fork(philo);
}

static void	pick_up_fork(t_philo *philo)
{
	lock_the_mutex(philo->first_fork);
	
	lock_the_mutex(philo->last_fork);
}

static void	put_down_fork(t_philo *philo)
{
	unlock_the_mutex(philo->last_fork);
	unlock_the_mutex(philo->first_fork);
}
