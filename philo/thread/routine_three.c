/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:52:27 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/06 15:18:26 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/timer.h"
#include "stdio.h"

static t_status	p_eat(t_philo *philo);
static t_status	picking_forks(t_philo *phil);

t_status	p_pick_fork(t_philo *philo)
{
	if ((philo->id % 2) == 0 && philo->first_run == 0)
	{
		philo->first_run = 1;
		if (spend_time(philo, 1) == c_exit)
			return (c_exit);
	}
	safe_lock(&(philo->lock->lock));
	while (!(are_forks_free(philo->left_fork, philo->right_fork)))
	{
		if (spend_time(philo, 1) == c_exit)
		{
			safe_unlock(&(philo->lock->lock));
			return (c_exit);
		}
	}
	if (picking_forks(philo) == c_exit)
	{
		safe_unlock(&(philo->lock->lock));
		return (c_exit);
	}
	safe_unlock(&(philo->lock->lock));
	return (p_eat(philo));
}

t_status	p_pick_fork2(t_philo *philo)
{
	if ((philo->id % 2) == 0 && philo->first_run == 0)
	{
		philo->first_run = 1;
		if (spend_time(philo, 1) == c_exit)
			return (c_exit);
	}
	if (does_have_death(philo))
		return (c_exit);
	safe_lock(&(philo->lock->lock));
	if (!(are_forks_free(philo->left_fork, philo->right_fork)))
	{
		safe_unlock(&(philo->lock->lock));
		return (philo->status);
	}
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
	if (does_have_death(philo) && does_come_limit(philo))
		return (c_exit);
	philo->starvation = philo->data->time_to_die;
	philo->eaten_amount += 1;
	if (!(does_have_death(philo)))
		printf("%ld %d is eating\n", get_time(), philo->id);
	if ((does_have_death(philo)) || (does_come_limit(philo)))
		return (c_exit);
	if (spend_time(philo, philo->data->time_to_eat) == c_exit)
		return (c_exit);
	philo->left_fork->is_free = c_true;
	philo->right_fork->is_free = c_true;
	if (is_full(philo) && philo->data->eat_limit != -1)
	{
		philo->is_full = c_true;
		*(philo->number_of_full_phils) += 1;
	}
	if ((does_have_death(philo)) || (does_come_limit(philo)))
		return (c_exit);
	philo->status = sleeping;
	return (philo->status);
}
