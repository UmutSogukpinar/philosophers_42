/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:41:43 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/22 18:25:08 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/timer.h"
#include "../includes/utils.h"
#include "sys/time.h"
#include "unistd.h"

static t_bool	dinner_three(t_philo *philo);
static t_bool	dinner_three_part_two(t_philo *philo);

void	*routine_three(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->death_time = philo->data->milestone + philo->data->time_to_die;
	if (philo->data->error_flag == c_true)
		write(2, "Error on routine_three() function\n", 35);
	while (philo->data->error_flag == c_false)
	{
		if (!(dinner_three(philo)) || philo->data->death_flag)
			return (NULL);
	}
	return (NULL);
}

static t_bool	dinner_three(t_philo *philo)
{
	pthread_mutex_lock(&(philo->first_fork->lock));
	if ((get_time() + philo->data->time_to_eat) <= philo->death_time
		&& !(check_satisfaction(philo->data)) && ((philo->data->turn % 3)
			+ 1 == philo->id))
	{
		p_eat(philo, philo->data);
		philo->data->turn += 1;
	}
	else
	{
		pthread_mutex_unlock(&(philo->first_fork->lock));
		if ((get_time() + philo->data->time_to_eat) > philo->death_time)
			p_die(philo);
		else if (check_satisfaction(philo->data))
			return (c_false);
		else
		{
			usleep(250);
			return (c_true);
		}
		return (c_false);
	}
	return (dinner_three_part_two(philo));
}

static t_bool	dinner_three_part_two(t_philo *philo)
{
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
