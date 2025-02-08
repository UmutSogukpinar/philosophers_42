#include "philosophers.h"
#include "stdlib.h"

void	free_table(t_philo **table)
{
	int	i;

	i = -1;
	if (table)
	{
		while (table[++i])
			free(table[i]);
		free(table);
	}
}

void	set_table(t_philo **table, t_data *data)
{
	int	i;

	if (data->number_phils == 1)
		return ;
	i = -1;
	while (++i < data->number_phils)
		table[i]->left_fork = table[(i + 1) % (data->number_phils)]->right_fork;
}
