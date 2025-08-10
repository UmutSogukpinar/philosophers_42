#include "philosophers_bonus.h"
#include "stdio.h" // ! For debug
#include "unistd.h"

// static const char	*get_status_msg(t_status status);

t_bool	display_err_msg(char *msg)
{
	ft_putendl(DEFAULT_ERR_MSG, STDERR_FILENO);
	ft_putendl(ERROR_BAR, STDERR_FILENO);
	if (msg)
		ft_putendl(msg, STDERR_FILENO);
	ft_putendl(ERROR_BAR, STDERR_FILENO);
	return (FALSE);
}

// static const char	*get_status_msg(t_status status)
// {
// 	if (status == EATING)
// 		return (EAT_MSG);
// 	if (status == SLEEPING)
// 		return (SLEEP_MSG);
// 	if (status == THINKING)
// 		return (THINK_MSG);
// 	if (status == DEAD)
// 		return (DEATH_MSG);
// 	if (status == PICKING_UP_FORK)
// 		return (FORK_MSG);
// 	return ("unknown");
// }

// ! FOR DEBUG

/* Display table data for debugging purposes */
void	display_table(const t_table *table)
{
	size_t	i;

	if (!table)
		return ;

	printf("==== Table Debug Info ====\n");
	printf("Number of philosophers: %zu\n", table->data.number_of_phils);
	printf("Time to die: %llu ms\n", (unsigned long long)table->data.time_to_die);
	printf("Time to eat: %llu ms\n", (unsigned long long)table->data.time_to_eat);
	printf("Time to sleep: %llu ms\n", (unsigned long long)table->data.time_to_sleep);
	printf("Eat limit: %d\n", table->data.eat_limit);

	printf("PIDs: ");
	if (!table->pids)
	{
		printf("(null)\n");
		return ;
	}
	i = 0;
	while (i < table->data.number_of_phils)
	{
		printf("%d", table->pids[i]);
		if (i + 1 < table->data.number_of_phils)
			printf(", ");
		i++;
	}
	printf("\n==========================\n");
}
