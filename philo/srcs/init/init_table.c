#include "philosophers.h"

static t_bool	init_locks(t_locks **locks);
static t_bool	init_shared_data(t_shared_data **data);
static void		set_common_data(t_philo *philos, t_shared_data *data,
					t_locks *locks);

t_table	*init_table(char **argv, int argc)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	table->number_of_phils = ft_atoui(argv[1]);
	table->amount_hungery_phil = table->number_of_phils;
	if (!table)
	{
		display_err_msg(ALLOC_ERR);
		return (NULL);
	}
	if (!init_locks(&table->locks) || !init_shared_data(&table->shared_data)
		|| !init_philos(&table->philos, argv, argc))
	{
		free_table(table);
		return (NULL);
	}
	set_left_forks(table->philos);
	set_fork_priority(table->philos);
	set_common_data(table->philos, table->shared_data, table->locks);
	return (table);
}

static void	set_common_data(t_philo *philos, t_shared_data *data,
		t_locks *locks)
{
	size_t	i;
	size_t	len;

	len = philos[0].data.number_of_phils;
	i = 0;
	while (i < len)
	{
		philos[i].locks = locks;
		philos[i].shared_data = data;
		i++;
	}
}

static t_bool	init_locks(t_locks **locks)
{
	t_locks	*dummy;

	*locks = ft_calloc(1, sizeof(t_locks));
	dummy = *locks;
	if (!dummy)
		return (display_err_msg(ALLOC_ERR));
	if (pthread_mutex_init(&dummy->death, NULL) == SUCCESS)
		dummy->death_init = TRUE;
	else
		return (display_err_msg(MTX_INIT_ERR));
	if (pthread_mutex_init(&dummy->full, NULL) == SUCCESS)
		dummy->full_init = TRUE;
	else
		return (display_err_msg(MTX_INIT_ERR));
	if (pthread_mutex_init(&dummy->print, NULL) == SUCCESS)
		dummy->print_init = TRUE;
	else
		return (display_err_msg(MTX_INIT_ERR));
	if (pthread_mutex_init(&dummy->error, NULL) == SUCCESS)
		dummy->error_init = TRUE;
	else
		return (display_err_msg(MTX_INIT_ERR));
	return (TRUE);
}



static t_bool	init_shared_data(t_shared_data **data)
{
	t_shared_data	*dummy;

	*data = ft_calloc(1, sizeof(t_shared_data));
	dummy = *data;
	if (!dummy)
		return (display_err_msg(ALLOC_ERR));
	return (TRUE);
}
