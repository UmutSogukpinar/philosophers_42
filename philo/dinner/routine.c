#include "stdlib.h"
#include "philosophers.h"
#include "utils.h"

#include "stdio.h"
#include "timer.h"

static void	drop_forks(t_philo *philo);
static t_status	p_eat(t_philo *philo);
static t_status	picking_up_forks(t_philo *philo);
static t_status	p_sleep_and_think(t_philo *philo);

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->last_meal_time = get_current_time();
	while (!(check_routine_finish(philo->data)))
	{
		while (!(check_routine_finish(philo->data))
			&& p_eat(philo) == c_thinking)
			ft_sleep(philo, 1);
		if (check_routine_finish(philo->data))
			return (NULL);
		if (p_sleep_and_think(philo) == c_exit)
			return (NULL);
	}
	return (NULL);
}

static t_status	p_eat(t_philo *philo)
{
	t_status	status;

	status = picking_up_forks(philo);
	if (status != c_eating)
		return (status);
	philo->last_meal_time = get_current_time();
	if (ft_print_status(philo, EAT_MSG) == c_exit)
		return (c_exit);
	if (ft_sleep(philo, philo->data->time_to_eat) == c_exit)
		return (c_exit);
	drop_forks(philo);
	philo->eaten_amount -= 1;
	if (check_satisfaction(philo) == c_true)
		return (c_exit);
	philo->status = c_sleeping;
	return (philo->status);
}

static t_status	picking_up_forks(t_philo *philo)
{
	if (!(philo->left_fork) || !(philo->right_fork))
		return (philo->status);
	safe_lock(&(philo->data->waiter_lock.lock));
	if (!(check_fork(philo)))
	{
		safe_unlock(&(philo->data->waiter_lock.lock));
		return (c_thinking);
	}
	safe_unlock(&(philo->data->waiter_lock.lock));
	if (ft_print_status(philo, FORK_MSG) == c_exit)
		return (c_exit);
	if (ft_print_status(philo, FORK_MSG) == c_exit)
		return (c_exit);
	philo->status = c_eating;
	return (philo->status);
}

static void	drop_forks(t_philo *philo)
{
	if (!(philo->left_fork) || !(philo->right_fork))
		return ;
	safe_lock(&(philo->data->waiter_lock.lock));
	philo->left_fork->is_free = c_true;
	philo->right_fork->is_free = c_true;
	safe_unlock(&(philo->data->waiter_lock.lock));
}

static t_status	p_sleep_and_think(t_philo *philo)
{
	if (check_routine_finish(philo->data))
		return (c_exit);
	if (ft_print_status(philo, SLEEP_MSG) == c_exit)
		return (c_exit);
	if (ft_sleep(philo, philo->data->time_to_sleep) == c_exit)
		return (c_exit);
	if (check_routine_finish(philo->data))
		return (c_exit);
	if (ft_print_status(philo, THINK_MSG) == c_exit)
		return (c_exit);
	philo->status = c_thinking;
	return (philo->status);
}
