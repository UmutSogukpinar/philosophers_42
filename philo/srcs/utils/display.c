#include "philosophers.h"
#include "stdio.h" // ! For debug
#include "unistd.h"

static const char	*get_status_msg(t_status status);

t_bool	display_err_msg(char *msg)
{
	ft_putendl(DEFAULT_ERR_MSG, STDERR_FILENO);
	ft_putendl(ERROR_BAR, STDERR_FILENO);
	if (msg)
		ft_putendl(msg, STDERR_FILENO);
	ft_putendl(ERROR_BAR, STDERR_FILENO);
	return (FALSE);
}

t_bool	display_status(t_philo *philo, t_status status)
{
	t_ms	current_time;

	lock_the_mutex(&philo->locks->print);
	current_time = get_timestamp(philo->shared_data, philo->locks);
	if (get_error_flag(philo->shared_data, philo->locks)
		|| get_death_flag(philo->shared_data, philo->locks))
	{
		unlock_the_mutex(&philo->locks->print);
		return (FALSE);
	}
	if (status == DEAD)
		set_death_flag(philo->shared_data, philo->locks, TRUE);
	printf("%llu %d %s\n",
		current_time,
		philo->id,
		get_status_msg(status));
	unlock_the_mutex(&philo->locks->print);
	return (TRUE);
}

static const char	*get_status_msg(t_status status)
{
	if (status == PICKING_UP_FORK)
		return (FORK_MSG);
	if (status == EATING)
		return (EAT_MSG);
	if (status == SLEEPING)
		return (SLEEP_MSG);
	if (status == THINKING)
		return (THINK_MSG);
	if (status == DEAD)
		return (DEATH_MSG);
	return ("unknown");
}


// ! ======================== Debug ========================

static void	display_philo(const t_philo *philo)
{
	if (!philo)
	{
		printf("Philo is NULL\n");
		return ;
	}
	printf("===== Philosopher %d =====\n", philo->id);
	printf("Alive          : %s\n", philo->is_alive ? "TRUE" : "FALSE");
	printf("Eat Limit      : %d\n", philo->data.eat_limit);
	printf("Eat Count      : %d\n", philo->data.number_eat);
	printf("Number of Phils: %zu\n", philo->data.number_of_phils);
	printf("Lifetime       : %lu ms\n", philo->data.lifetime);
	printf("Meal Time      : %lu ms\n", philo->data.meal_time);
	printf("Sleep Time     : %lu ms\n", philo->data.sleep_time);
	printf("Last Meal Time : %lu ms\n", philo->data.last_meal_time);
	if (philo->shared_data)
	{
		printf("Shared Flags   :\n");
		printf("    Error       : %s\n",
				philo->shared_data->error_flag ? "TRUE" : "FALSE");
		printf("    Death Exist : %s\n",
				philo->shared_data->does_death_exist ? "TRUE" : "FALSE");
		printf("    All Full    : %s\n",
				philo->shared_data->are_philos_full ? "TRUE" : "FALSE");
	}
	else
		printf("Shared Flags   : NULL\n");
	printf("Fork Pointers  :\n");
	printf("    Left Fork   : %s (addr: %p)\n",
			philo->left_fork ? "OK" : "NULL", (void *)philo->left_fork);
	printf("    Right Fork  : %s (addr: %p)\n",
			philo->right_fork ? "OK" : "NULL", (void *)philo->right_fork);
	printf("    First Fork  : %s (addr: %p)\n",
			philo->first_fork ? "OK" : "NULL", (void *)philo->first_fork);
	printf("    Last Fork   : %s (addr: %p)\n",
			philo->last_fork ? "OK" : "NULL", (void *)philo->last_fork);
	printf("==========================\n");
}

void	display_philo_list(t_philo *philos, size_t count)
{
	if (!philos)
	{
		printf("Philo list is NULL\n");
		return ;
	}
	for (size_t i = 0; i < count; ++i)
	{
		display_philo(&philos[i]);
	}
}

void	display_table(const t_table *table)
{
	if (!table)
	{
		printf("Table is NULL\n");
		return ;
	}
	printf("\n=========== TABLE STATUS ===========\n");
	printf("Number of Philosophers : %zu\n", table->number_of_phils);
	// Shared Data
	if (table->shared_data)
	{
		printf("Shared Flags:\n");
		printf("    Error       : %s\n",
				table->shared_data->error_flag ? "TRUE" : "FALSE");
		printf("    Death Exist : %s\n",
				table->shared_data->does_death_exist ? "TRUE" : "FALSE");
		printf("    All Full    : %s\n",
				table->shared_data->are_philos_full ? "TRUE" : "FALSE");
	}
	else
	{
		printf("Shared Flags            : NULL\n");
	}
	// Locks info with init flags
	if (table->locks)
	{
		printf("Locks:\n");
		printf("    Full Mutex   : %s\n",
				table->locks->full_init ? "OK" : "UNINIT");
		printf("    Print Mutex  : %s\n",
				table->locks->print_init ? "OK" : "UNINIT");
		printf("    Death Mutex  : %s\n",
				table->locks->death_init ? "OK" : "UNINIT");
	}
	else
	{
		printf("Locks                   : NULL\n");
	}
	printf("Monitor Thread ID       : %lu\n", (unsigned long)table->monitor);
	printf("\n------ PHILOSOPHER LIST ------\n");
	display_philo_list(table->philos, table->number_of_phils);
	printf("================================\n\n");
}
