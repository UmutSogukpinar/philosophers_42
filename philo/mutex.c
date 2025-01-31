/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:33:42 by umut              #+#    #+#             */
/*   Updated: 2025/02/01 01:08:52 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	lock_fork(t_fork *fork)
{
	long	time;
	t_bool	status;

	pthread_mutex_lock(&(fork->mutex));
	status = get_time(&time);
	if (!status)
		return (c_false);
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
