#include "philosophers_bonus.h"
#include "fcntl.h"
#include "string.h"

static t_bool   check_sem_initialization(t_table *table);

/* ---------- Create named semaphores ---------- */
t_bool	init_sems(t_table *table)
{
	size_t			n;

	if (!table)
		return (FALSE);
	n = table->data.number_of_phils;
	unlink_common_sems();
	table->sems.forks = sem_open(SEM_FORKS, O_CREAT | O_EXCL, 0644,
			(unsigned int)n);
	table->sems.print = sem_open(SEM_PRINT, O_CREAT | O_EXCL, 0644, 1);
	table->sems.death = sem_open(SEM_DEATH, O_CREAT | O_EXCL, 0644, 0);
	table->sems.finish = sem_open(SEM_FINISH, O_CREAT | O_EXCL, 0644, 0);
    return (check_sem_initialization(table));
}

/* ---------- Unlink all named semaphores ---------- */
void    unlink_common_sems(void)
{
    sem_unlink(SEM_FORKS);
    sem_unlink(SEM_PRINT);
    sem_unlink(SEM_DEATH);
    sem_unlink(SEM_FINISH);
}

/* ---------- validate & cleanup on failure ---------- */
static t_bool   check_sem_initialization(t_table *table)
{
    if (table->sems.forks == SEM_FAILED
        || table->sems.print == SEM_FAILED
        || table->sems.death == SEM_FAILED
        || table->sems.finish  == SEM_FAILED)
    {
        close_common_sems(&table->sems);
        unlink_common_sems();
        memset(&table->sems, 0, sizeof(table->sems));
        return (display_err_msg(SEM_OPEN_ERR));
    }
    return (TRUE);
}

/* ---------- Close opened sem handles (no unlink) ---------- */
void    close_common_sems(t_semaphores *sems)
{
    if (!sems)
        return ;
    if (sems->forks)
        sem_close(sems->forks);
    if (sems->print)
        sem_close(sems->print);
    if (sems->death)
        sem_close(sems->death);
    if (sems->finish) 
        sem_close(sems->finish);
}

