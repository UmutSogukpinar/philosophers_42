#include "philosophers_bonus.h"
#include "stdlib.h"

void	free_table(t_table *table)
{
	if (!table)
		return ;
	close_common_sems(&table->sems);
	unlink_common_sems();
	free(table->pids);
	table->pids = NULL;
	free(table);
}
