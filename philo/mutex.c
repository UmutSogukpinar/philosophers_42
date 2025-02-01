/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:56:13 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 17:59:34 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

t_bool	lock_fork(t_philo *phil, t_fork *fork, long *time)
{
	t_bool	status;

	pthread_mutex_lock(&(fork->mutex));
	status = get_time(time);
	if (!status)
	{
		pthread_mutex_unlock(&(fork->mutex));
		return (c_false);
	}
	fork->is_free = c_false;
	return (c_true);
}
void	unlock_fork(t_fork *fork)
{
	pthread_mutex_unlock(&(fork->mutex));
	fork->is_free = c_true;
}

void	unlock_both_fork(t_fork *left_fork, t_fork *right_fork)
{
	unlock_fork(left_fork);
	unlock_fork(right_fork);
}
