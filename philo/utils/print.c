/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:19 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/15 14:18:02 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/timer.h"
#include "stdio.h"

static void	print_others(t_philo *philo, t_status status);

void	print_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&(philo->data->print_lock));
	if (philo->data->death_flag == c_false && status == c_death)
	{
		printf("%lld %d %s", (get_time() - philo->data->milestone), philo->id,
			DEATH_MSG);
		philo->data->death_flag = c_true;
		pthread_mutex_unlock(&(philo->data->print_lock));
		return ;
	}
	else if (philo->data->death_flag == c_true)
	{
		pthread_mutex_unlock(&(philo->data->print_lock));
		return ;
	}
	print_others(philo, status);
	pthread_mutex_unlock(&(philo->data->print_lock));
}

static void	print_others(t_philo *philo, t_status status)
{
	if (status == c_taking_forks)
	{
		printf("%lld %d %s", (get_time() - philo->data->milestone), philo->id,
			FORK_MSG);
		return ;
	}
	if (status == c_eating)
	{
		printf("%lld %d %s", (get_time() - philo->data->milestone), philo->id,
			EAT_MSG);
		return ;
	}
	if (status == c_thinking)
	{
		printf("%lld %d %s", (get_time() - philo->data->milestone), philo->id,
			THINK_MSG);
		return ;
	}
	if (status == c_sleeping)
	{
		printf("%lld %d %s", (get_time() - philo->data->milestone), philo->id,
			SLEEP_MSG);
		return ;
	}
}
