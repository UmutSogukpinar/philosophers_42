#include "philosophers_bonus.h"
#include "fcntl.h"

int	init_table(t_table *table, int argc, char **argv)
{
	size_t	n;

	memset(table, 0, sizeof(*table));
	n = (size_t)ft_atoi(argv[1]);
	table->cfg.number_of_phils = n;
	table->cfg.time_to_die = (t_ms)ft_atoi(argv[2]);
	table->cfg.time_to_eat = (t_ms)ft_atoi(argv[3]);
	table->cfg.time_to_sleep = (t_ms)ft_atoi(argv[4]);
	table->cfg.eat_limit = ft_atoi(argv[5]);
	table->sems.forks = sem_open(SEM_FORKS, O_CREAT | O_EXCL, 0644, n);
	table->sems.print = sem_open(SEM_PRINT, O_CREAT | O_EXCL, 0644, 1);
	table->sems.death = sem_open(SEM_DEATH, O_CREAT | O_EXCL, 0644, 0);
	table->sems.full = sem_open(SEM_FULL, O_CREAT | O_EXCL, 0644, 0);
	table->sems.limit = sem_open(SEM_LIMIT, O_CREAT | O_EXCL, 0644, (n > 1) ? n / 2 : 1);

	table->pids = (pid_t *)calloc(n, sizeof(pid_t));
	if (!table->pids)
		return (1);
	return (0);
}


