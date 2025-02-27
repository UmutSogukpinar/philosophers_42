/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:54:44 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/23 14:33:15 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/timer.h"
#include "../includes/utils.h"
#include "unistd.h"

static t_bool	dinner(t_philo *philo);
static void		taking_fork_and_die(t_philo *philo);

void	*routine_exception(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_status(philo, c_taking_forks);
	ft_sleep(philo->data->milestone + philo->data->time_to_die);
	print_status(philo, c_death);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->death_time = philo->data->milestone + philo->data->time_to_die;
	if (philo->data->error_flag == c_true)
		write(2, "Error on routine() function\n", 29);
	if (philo->id % 2 == 0 && philo->data->error_flag == c_false)
		ft_sleep(get_time() + philo->data->time_to_eat);
	while (philo->data->error_flag == c_false)
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
			taking_fork_and_die(philo);
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

static void	taking_fork_and_die(t_philo *philo)
{
	print_status(philo, c_taking_forks);
	print_status(philo, c_taking_forks);
	p_die(philo);
}
