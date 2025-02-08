#ifndef TIMER_H
# define TIMER_H

# include "philosophers.h"

# define GET_TIME_ERR "gettimeofday function doesn't work as expected\n"

long long	get_current_time(void);
t_status	ft_sleep(t_philo *philo, int sleeptime);

#endif