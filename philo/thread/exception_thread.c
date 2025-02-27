/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:41:43 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/23 13:51:25 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/timer.h"
#include "../includes/utils.h"
#include "sys/time.h"
#include "unistd.h"

static t_bool	dinner_three(t_philo *philo);
static t_bool	dinner_three_part_two(t_philo *philo);
static t_bool	waiting_part(t_philo *philo);

void	*routine_three(void *arg)
{
	t_philo	*philo;
	t_bool	is_dead;

	philo = (t_philo *)arg;
	philo->death_time = philo->data->milestone + philo->data->time_to_die;
	if (philo->data->error_flag == c_true)
		write(2, "Error on routine_three() function\n", 35);
	while (philo->data->error_flag == c_false)
	{
		pthread_mutex_lock(&(philo->data->print_lock));
		is_dead = philo->data->death_flag;
		pthread_mutex_unlock(&(philo->data->print_lock));
		if (!(dinner_three(philo)) || is_dead)
			return (NULL);
	}
	return (NULL);
}

static t_bool	dinner_three(t_philo *philo)
{
	if ((check_satisfaction(philo->data)))
		return (c_false);
	pthread_mutex_lock(&(philo->data->turn_lock));
	if ((philo->data->turn % 3) + 1 != philo->id)
	{
		pthread_mutex_unlock(&(philo->data->turn_lock));
		return (c_true);
	}
	pthread_mutex_unlock(&(philo->data->turn_lock));
	if ((check_satisfaction(philo->data)))
		return (c_false);
	pthread_mutex_lock(&(philo->first_fork->lock));
	if ((get_time() + philo->data->time_to_eat) <= philo->death_time
		&& !(check_satisfaction(philo->data)))
		p_eat(philo, philo->data);
	else
		return (waiting_part(philo));
	pthread_mutex_lock(&(philo->data->turn_lock));
	philo->data->turn += 1;
	pthread_mutex_unlock(&(philo->data->turn_lock));
	return (dinner_three_part_two(philo));
}

static t_bool	waiting_part(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->first_fork->lock));
	if ((get_time() + philo->data->time_to_eat) > philo->death_time)
	{
		print_status(philo, c_taking_forks);
		print_status(philo, c_taking_forks);
		p_die(philo);
	}
	else if (check_satisfaction(philo->data))
		return (c_false);
	else
	{
		usleep(2000);
		return (c_true);
	}
	return (c_false);
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
