#include "utils.h"
#include "stdio.h"
#include "timer.h"

t_bool	check_args(int argn, char **args)
{
	int	i;
	int	num;

	if (!(argn == 5 || argn == 6))
	{
		printf(INV_ARGN);
		return (c_false);
	}
	i = 0;
	while (++i <= argn - 1)
	{
		num = ft_atoi(args[i]);
		if (num <= 0)
		{
			printf(INV_ARGS);
			return (c_false);
		}
	}
	return (c_true);
}

t_bool	check_death(t_philo *philo)
{
	if (((get_current_time() - (philo->last_meal_time))
		> (long long)philo->data->time_to_die))
		{
			return (c_true);
		}
	return (c_false);
}

t_bool	check_satisfaction(t_philo *philo)
{
	if (philo->eaten_amount == 0)
	{
		safe_lock(&(philo->data->meal_lock.lock));
		philo->data->number_full_phils += 1;
		safe_unlock(&(philo->data->meal_lock.lock));
		if (philo->data->number_full_phils == philo->data->number_phils)
		{
			philo->data->eat_limit_flag = c_true;
			return (c_true);
		}
		return (c_false);
	}
	return (c_false);
}

t_bool	check_fork(t_philo *philo)
{
	if (!(philo->left_fork) || !(philo->right_fork))
		return (c_false);
	if (philo->left_fork->is_free && philo->right_fork->is_free)
	{
		philo->left_fork->is_free = c_false;
		philo->right_fork->is_free = c_false;
		return (c_true);
	}
	return (c_false);
}

t_bool	check_routine_finish(t_data *data)
{
	if (data->death_flag == c_true || data->eat_limit_flag == c_true)
		return (c_true);
	return (c_false);
}

