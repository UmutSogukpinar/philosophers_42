/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:54:44 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/10 14:02:01 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/timer.h"
#include "../includes/utils.h"
#include "stdlib.h"

static t_bool	dinner(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->death_time = philo->data->milestone + philo->data->time_to_die;
	if (philo->id % 2 == 0)
		ft_sleep(get_time() + philo->data->time_to_eat);
	while (c_true)
	{
		if (!(dinner(philo)) || philo->data->death_flag)
			return (NULL);
	}
	return (NULL);
}

static t_bool	dinner(t_philo *philo)
{
	pthread_mutex_lock(&(philo->first_fork->lock));
	if ((get_time() + philo->data->time_to_eat) <= philo->death_time
		&& !(check_satisfaction(philo->data)))
		p_eat(philo, philo->data);
	else
	{
		pthread_mutex_unlock(&(philo->first_fork->lock));
		if ((get_time() + philo->data->time_to_eat) > philo->death_time)
			p_die(philo);
		return (c_false);
	}
	if (check_satisfaction(philo->data))
		return (c_false);
	if ((get_time() + philo->data->time_to_sleep) > philo->death_time)
	{
		philo->death_time -= philo->data->time_to_eat;
		p_die(philo);
		return (c_false);
	}
	else
		p_sleep(philo);
	if (check_satisfaction(philo->data))
		return (c_false);
	p_think(philo);
	return (c_true);
}
