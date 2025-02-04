/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:55 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/04 16:32:09 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "stdio.h"
#include "../includes/timer.h"

static void	*quit_routine(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;
	t_status status;

	philo = (t_philo *)arg;
	if ((*(philo->error)) == c_true)
		return (quit_routine(philo));
	while (((*(philo->error)) == c_false) && (((philo->death->does_exist)) == c_false))
	{
		status = thinking;
		while (status == thinking)
		{
			status = p_pick_fork(philo);
			status = spend_time(philo, 1);
		}
		if (status == c_exit || status == c_error)
			return (NULL);
		status = p_sleep(philo);
		if (status == c_exit || status == c_error)
			return (NULL);
		status = p_think(philo);
		if (status == c_exit || status == c_error)
			return (NULL);
	}
	return (NULL);
}

static void	*quit_routine(t_philo *philo)
{
	philo->death->does_exist = c_true;
	printf("Error on \033[1;31m\"routine()\"\033[0m function\n");
	return (NULL);
}
