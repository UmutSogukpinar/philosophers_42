/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:55 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/03 17:51:24 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdio.h"
#include "timer.h"

const char	*get_status_string(t_status status)
{
	if (status == eating)
		return ("Eating");
	if (status == thinking)
		return ("Thinking");
	if (status == sleeping)
		return ("Sleeping");
	if (status == c_exit)
		return ("Exited");
	if (status == c_error)
		return ("Error");
	return ("Unknown");
}

void	display_philo(t_philo *philo)
{
	if (!philo)
		return ;
	printf("\n=============================\n");
	printf("Philosopher ID: %d\n", philo->id);
	printf("Starvation Level: %d\n", philo->starvation);
	printf("Current Status: %s\n", get_status_string(philo->status));
	printf("Time to Die: %d ms\n", philo->data->time_to_die);
	printf("Time to Eat: %d ms\n", philo->data->time_to_eat);
	printf("Time to Sleep: %d ms\n", philo->data->time_to_sleep);
	printf("Eat Limit: %d\n", philo->data->eat_limit);
	printf("Left Fork ID: %d (%s)\n",
			philo->left_fork->id,
			philo->left_fork->is_free ? "Available" : "In Use");
	printf("Right Fork ID: %d (%s)\n",
			philo->right_fork->id,
			philo->right_fork->is_free ? "Available" : "In Use");
	printf("Death Signal: %s\n", philo->death->does_exist ? "YES" : "NO");
	printf("Error Flag: %s\n", *(philo->error) ? "ERROR" : "OK");
	printf("=============================\n");
}
static void	*quit_routine(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((*(philo->error)) == c_true)
		return (quit_routine(philo));
	while (((*(philo->error)) == c_false) && (((philo->death->does_exist)) == c_false))
	{
		
	}
	return (NULL);
}

static void	*quit_routine(t_philo *philo)
{
	philo->death->does_exist = c_true;
	printf("Error on \033[1;31m\"routine()\"\033[0m function\n");
	return (NULL);
}
