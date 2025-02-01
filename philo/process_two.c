/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:08:05 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 17:46:48 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdio.h"

t_status	p_sleep(t_philo *phil)
{
	long	time;

	if (!get_time(phil, &time))
	{
		unlock_both_fork(phil->left_fork, phil->right_fork);
		return (c_exit);
	}
	if (!is_dead(phil))
		printf("%ld %d is sleeping\n", time, phil->id);
	spend_time(phil, phil->data->time_to_sleep);
	if (is_dead(phil))
		return (c_exit);
	return (sleeping);
}

t_status	p_think(t_philo *phil)
{
	long	time;

	if (!get_time(phil, &time))
	{
		unlock_both_fork(phil->left_fork, phil->right_fork);
		return (c_exit);
	}
	if (!is_dead(phil))
		printf("%ld %d is thinking\n", time, phil->id);
    else
        return (c_exit);
	return (thinking);
}
