#include "philosophers.h"
#include <sys/time.h>
#include "unistd.h"

t_ms	get_timestamp(t_shared_data *data, t_locks *locks)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) != SUCCESS)
	{
		lock_the_mutex(&locks->print);
		display_err_msg(GETTIMEOFDAY_ERR);
		set_error_flag(data, locks, TRUE);
		unlock_the_mutex(&locks->print);
		return (0);
	}
	return ((t_ms)(now.tv_sec * 1000 + now.tv_usec / 1000));
}

void	elapse_time(t_shared_data *data, t_locks *locks, t_ms duration)
{
	t_ms start;
	t_ms now;

	start = get_timestamp(data, locks);
	while (TRUE)
	{
		now = get_timestamp(data, locks);
		if ((now - start) >= duration)
			break ;
		usleep(100);
	}
}
