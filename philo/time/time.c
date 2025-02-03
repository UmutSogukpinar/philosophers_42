/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:56:43 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/03 18:20:28 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"
#include "timer.h"
#include "unistd.h"

static long	get_ms(long sec, long microsec)
{
	return (sec * 1000) + (microsec / 1000);
}

long	get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		printf(GET_TIME_ERR);
		printf("Error on \033[1;31m\"get_time()\"\033[0m function\n");
	}
	return (get_ms(current_time.tv_sec, current_time.tv_usec));
}

t_status	spend_time(t_philo *philo, int amount)
{
	int	i;

	if (does_have_death(philo))
		return (c_exit);
	i = -1;
	while (++i < amount)
	{
		usleep(ONE_MS);
		philo->starvation -= 1;
		if (does_have_death(philo))
			return (c_exit);
	}
	return (philo->status);
}

t_status	spend_time_in_eating(t_philo *philo, int amount)
{
	int	i;

	if (does_have_death(philo))
		return (c_exit);
	i = -1;
	while (++i < amount)
	{
		usleep(ONE_MS);
		if (does_have_death(philo))
			return (c_exit);
	}
	return (philo->status);
}
