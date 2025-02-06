/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:42:38 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/06 12:31:31 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/timer.h"
#include "stdio.h"

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
