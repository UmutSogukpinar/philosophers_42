/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:25:42 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 17:44:13 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "sys/time.h"
#include "unistd.h"
#include "stdio.h"

long	to_ms(long seconds, long microseconds)
{
	return ((seconds * 1000) + (microseconds / 1000));
}

t_bool	get_time(t_philo *phil, long *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 0)
	{
		*time = to_ms(tv.tv_sec, tv.tv_sec);
		if (phil->death)
			return (c_false);
		return (c_true);
	}
	printf("gettimeofday error\n");
	return (c_false);
}

void	spend_time(t_philo *phil, int amount)
{
	int	i;

	i = -1;
	while ((++i < (amount * 2)) && !(phil->death))
	{
		usleep(ZERO_POINT_FIVE_MS);
		if (i % 2 == 1 && !phil->death)
			phil->starvation -= 1;
		if (is_dead(phil))
			return ;
	}
}

t_status	spend_ms(t_philo *phil, int amount)
{
	int	i;

	i = -1;
	while ((++i < (amount * 2)) && !(phil->death))
	{
		usleep(ZERO_POINT_FIVE_MS);
		if (is_dead(phil))
			return (c_exit);
	}
	return (eating);
}

t_bool	is_dead(t_philo *philo)
{
	long	time;

	if (philo->starvation >= 0 && (philo->death))
	{
		philo->death = c_true;
		return (c_true);
	}
	else if (philo->starvation <= 0 && !(philo->death))
	{
		philo->death = c_true;
		if (!get_time(philo, &time))
			return (c_exit);
		printf("%ld %d died\n", time, philo->id);
	}
	else
		return (c_false);
}
