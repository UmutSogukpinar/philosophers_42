#include <signal.h>
#include <sys/wait.h>
#include "philosophers_bonus.h"

static void	wait_completion(t_table *t);
static void	terminate_children(pid_t *pids, size_t count);
static void	wait_children(pid_t *pids, size_t count);

t_bool	init_dining(t_table *table)
{
	size_t	i;
	pid_t	pid;
	size_t	n;

	n = table->data.number_of_phils;
	i = 0;
	while (i < n)
	{
		pid = fork();
		if (pid < 0)
		{
			display_err_msg(FORK_ERR);
			terminate_children(table->pids, i);
			wait_children(table->pids, i);
			return (FALSE);
		}
		if (pid == 0)
			exec_child(table->data, table->pids, (int)(i + 1));
		table->pids[i] = pid;
		i++;
	}
	wait_completion(table);
	terminate_children(table->pids, n);
	wait_children(table->pids, n);
	return (TRUE);
}

/* Wait completion policy: FULL N times or one DEATH. */
static void	wait_completion(t_table *t)
{
	sem_wait(t->sems.finish);
}

/* Send SIGTERM to all children (pids[0..count-1]) */
static void	terminate_children(pid_t *pids, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (pids[i] > 0)
			kill(pids[i], SIGTERM);
		i++;
	}
}

/* Reap all children to avoid zombies */
static void	wait_children(pid_t *pids, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (pids[i] > 0)
			waitpid(pids[i], NULL, 0);
		i++;
	}
}
