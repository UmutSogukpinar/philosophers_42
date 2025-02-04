/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:42:38 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/04 19:08:48 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/timer.h"
#include "stdio.h"

static t_status	p_eat(t_philo *philo);
static t_status	picking_forks(t_philo *phil);

t_status	p_pick_fork(t_philo *philo)
{
	if ((philo->id % 2) == 0 && philo->eaten_amount == 0)
		if (spend_time(philo, 1) == c_exit)
			return (c_exit);
	if (does_have_death(philo))
		return (c_exit);
	safe_lock(&(philo->lock->lock));
	if (!(are_forks_free(philo->left_fork, philo->right_fork)))
	{
		safe_unlock(&(philo->lock->lock));
		return (philo->status);
	}
	philo->status = eating;
	if (picking_forks(philo) == c_exit)
	{
		safe_unlock(&(philo->lock->lock));
		return (c_exit);
	}
	safe_unlock(&(philo->lock->lock));
	if (p_eat(philo) == c_exit)
		return (c_exit);
	if (does_have_death(philo) && does_come_limit(philo))
		return (c_exit);
	return (philo->status);
}

static t_status	picking_forks(t_philo *phil)
{
	phil->left_fork->is_free = c_false;
	if (!(does_have_death(phil)))
		printf("%ld %d has taken a fork\n", get_time(), phil->id);
	else
		return (c_exit);
	phil->right_fork->is_free = c_false;
	if (!(does_have_death(phil)))
		printf("%ld %d has taken a fork\n", get_time(), phil->id);
	else
		return (c_exit);
	phil->status = eating;
	return (phil->status);
}

static t_status	p_eat(t_philo *philo)
{
	long	time;

	time = get_time();
	if (!(does_have_death(philo)))
		printf("%ld %d is eating\n", time, philo->id);
	philo->eaten_amount += 1;
	philo->starvation = philo->data->time_to_die;
	if ((does_have_death(philo)) || (does_come_limit(philo)))
		return (c_exit);
	if (spend_time_in_eating(philo, philo->data->time_to_eat) == c_exit)
		return (c_exit);
	philo->status = sleeping;
	philo->left_fork->is_free = c_true;
	philo->right_fork->is_free = c_true;
	return (philo->status);
}

t_status	p_sleep(t_philo *philo)
{
	if (!(does_have_death(philo)))
		printf("%ld %d is sleeping\n", get_time(), philo->id);
	if (spend_time(philo, philo->data->time_to_sleep) == c_exit)
		return (c_exit);
	philo->status = thinking;
	return (philo->status);
}

t_status	p_think(t_philo *philo)
{
	if (!(does_have_death(philo)))
		printf("%ld %d is thinking\n", get_time(), philo->id);
	if (!(does_have_death(philo)))
		return (philo->status);
	else
		return (c_exit);
}
