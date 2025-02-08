#include "sys/time.h"
#include "stdio.h"
#include "timer.h"
#include "utils.h"
#include "unistd.h"

long long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf(GET_TIME_ERR);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_status	ft_sleep(t_philo *philo, int sleeptime)
{
	long long	wakeup_time;

	wakeup_time = get_current_time() + sleeptime;
	while (wakeup_time > get_current_time())
	{
		usleep(50);
		if (check_death(philo))
			return (c_exit);
	}
	return (philo->status);
}
