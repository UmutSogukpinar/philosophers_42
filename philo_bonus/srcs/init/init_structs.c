#include "philosophers_bonus.h"
#include <string.h>

static void	init_data(t_data *data, int argc, char **argv);

/* ---------- Parse argv and allocate table (no sem yet) ---------- */
t_bool  init_table(t_table *table, int argc, char **argv)
{
    memset(table, 0, sizeof(*table));
    init_data(&table->data, argc, argv);
    table->pids = ft_calloc(table->data.number_of_phils, sizeof(pid_t));
    if (!table->pids)
	{
        return (FALSE);
	}
	if (!init_sems(table))
	{
		free_table(table);
		return (FALSE);
	}
    return (TRUE);
}

/* Initialize simulation parameters from command line arguments */
static void	init_data(t_data *data, int argc, char **argv)
{
	size_t	n;

	n = (size_t)ft_atoui(argv[1]);
	data->number_of_phils = n;
	data->time_to_die = (t_ms)ft_atoui(argv[2]);
	data->time_to_eat = (t_ms)ft_atoui(argv[3]);
	data->time_to_sleep = (t_ms)ft_atoui(argv[4]);
	if (argc == 6)
		data->eat_limit = ft_atoui(argv[5]);
	else
		data->eat_limit = -1;
}
