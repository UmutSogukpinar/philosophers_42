/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:33:14 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/04 16:10:34 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "stdio.h"
#include "../includes/timer.h"

t_bool	safe_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf(M_LOCK_ERR);
		printf("Error on \033[1;31m\"safe_lock()\"\033[0m function\n");
		return (c_false);
	}
	return (c_true);
}

t_bool	safe_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf(M_UNLCK_ERR);
		printf("Error on \033[1;31m\"safe_unlock()\"\033[0m function\n");
		return (c_false);
	}
	return (c_true);
}

t_bool	does_have_death(t_philo *philo)
{
	long	time;

	safe_lock(&(philo->death->lock.lock));
	if ((philo->death->does_exist == c_false) && (philo->starvation <= 0))
	{
		time = get_time();
		printf("%ld %d died\n", time, philo->id);
		philo->death->does_exist = c_true;
		safe_unlock(&(philo->death->lock.lock));
		return (c_true);
	}
	else if ((philo->death->does_exist == c_true) && (philo->starvation >= 0))
	{
		safe_unlock(&(philo->death->lock.lock));
		return (c_true);
	}
	safe_unlock(&(philo->death->lock.lock));
	return (c_false);
}

t_bool	does_come_limit(t_philo *philo)
{
	if (philo->data->eat_limit == -1)
		return (c_false);
	safe_lock(&(philo->death->lock.lock));
	if (philo->data->eat_limit <= philo->eaten_amount)
	{
		philo->death->does_exist = c_true;
		safe_unlock(&(philo->death->lock.lock));
		return (c_true);
	}
	safe_unlock(&(philo->death->lock.lock));
	return (c_false);
}
