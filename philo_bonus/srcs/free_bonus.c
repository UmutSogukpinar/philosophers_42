#include "philosophers_bonus.h"
#include "stdlib.h"

void	free_table(t_table *table)
{
	if (!table)
		return ;
	close_all_sems(&table->sems);
	unlink_all_sems();
	free(table->pids);
	table->pids = NULL;
	free(table);
}
