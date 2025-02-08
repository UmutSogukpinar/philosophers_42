#include "unistd.h"
#include "utils.h"
#include "timer.h"
#include "stdio.h"

t_status	ft_print_status(t_philo *philo, char *str)
{
	safe_lock(&(philo->data->print_lock.lock));
	if (check_death(philo) == c_true)
	{
		safe_unlock(&(philo->data->print_lock.lock));
		return (c_exit);
	}
	printf("%llu %d %s", (get_current_time() - philo->data->start_time),
		philo->id, str);
	safe_unlock(&(philo->data->print_lock.lock));
	return (philo->status);
}
