#include "philosophers.h"
#include "utils.h"
#include "timer.h"
#include "unistd.h"
#include "stdio.h"

static void	monitor(t_greece *ionia, t_data *data);

void	start_dining(t_greece *ionia)
{
	int	i;

	i = -1;
	ionia->data->start_time = get_current_time();
	while (++i < ionia->data->number_phils)
	{
		pthread_create(&((ionia->table)[i]->thread), NULL, routine, (ionia->table)[i]);
		usleep(100);
	}
	monitor(ionia, ionia->data);
	i = -1;
	while (++i < ionia->data->number_phils)
		pthread_join((ionia->table)[i]->thread, NULL);
}

static void	monitor(t_greece *ionia, t_data *data)
{
	int	queue;

	queue = 0;
	while (c_true)
	{
		if (queue == data->number_phils)
			queue = 0;
		safe_lock(&(data->dead_lock.lock));
		if (check_death((ionia->table)[queue]))
		{
			if (!(data->death_flag))
				printf("%llu %d %s", get_current_time() - data->start_time,
					ionia->table[queue]->id, DEATH_MSG);
			data->death_flag = c_true;
			safe_unlock(&(data->dead_lock.lock));
			break ;
		}
		safe_unlock(&(data->dead_lock.lock));
		if (data->eat_limit_flag)
			break ;
		queue++;
	}
}
