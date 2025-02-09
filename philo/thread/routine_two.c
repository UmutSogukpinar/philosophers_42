/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:54:33 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/09 16:37:57 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/timer.h"
#include "../includes/utils.h"

void	p_eat(t_philo *philo, t_data *data)
{
	print_status(philo, c_taking_forks);
	pthread_mutex_lock(&(philo->last_fork->lock));
	print_status(philo, c_taking_forks);
	print_status(philo, c_eating);
	ft_sleep(get_time() + data->time_to_eat);
	philo->death_time = get_time() + data->time_to_die;
	if (data->eat_limit != -1)
		philo->eaten_amount += 1;
	if (philo->eaten_amount ==  philo->data->eat_limit)
	{
		pthread_mutex_lock(&(philo->data->meal_lock));
		philo->data->number_full_phils += 1;
		pthread_mutex_unlock(&(philo->data->meal_lock));
	}
	pthread_mutex_unlock(&(philo->last_fork->lock));
	pthread_mutex_unlock(&(philo->first_fork->lock));
}

void	p_die(t_philo *philo)
{
	ft_sleep(philo->death_time);
	print_status(philo, c_death);
}

void	p_sleep(t_philo *philo)
{
	print_status(philo, c_sleeping);
	ft_sleep(get_time() + philo->data->time_to_sleep);
}

void	p_think(t_philo *philo)
{
	print_status(philo, c_thinking);
}
