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
		|| get_death_flag(philo->shared_data, philo->locks)
		|| get_full_flag(philo->shared_data, philo->locks))
	{
		unlock_the_mutex(&philo->locks->print);
		return (FALSE);
	}
	if (status == DEAD)
		set_death_flag(philo->shared_data, philo->locks, TRUE);
	printf("%lu %d %s\n", current_time - philo->data.milestone, philo->id,
			get_status_msg(status));
	unlock_the_mutex(&philo->locks->print);
	return (TRUE);
}

static const char	*get_status_msg(t_status status)
{
	if (status == EATING)
		return (EAT_MSG);
	if (status == SLEEPING)
		return (SLEEP_MSG);
	if (status == THINKING)
		return (THINK_MSG);
	if (status == DEAD)
		return (DEATH_MSG);
	if (status == PICKING_UP_FORK)
		return (FORK_MSG);
	return ("unknown");
}
