/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:12:40 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/10 13:35:19 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

static void	free_fork(t_fork *fork);
static void	free_philo(t_philo *philo);

void	free_table(t_philo **table)
{
	int	i;

	if (table)
	{
		i = -1;
		while (table[++i])
		{
			free_philo(table[i]);
		}
		free(table);
	}
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (pthread_mutex_destroy(&(data->meal_lock)) != 0)
			error_message("free_fork", MUT_DSTRY_ERR);
		if (pthread_mutex_destroy(&(data->print_lock)) != 0)
			error_message("free_fork", MUT_DSTRY_ERR);
		free(data);
	}
}

static void	free_philo(t_philo *philo)
{
	if (philo)
	{
		free_fork(philo->right_fork);
		free(philo);
	}
}

static void	free_fork(t_fork *fork)
{
	if (fork)
	{
		if (pthread_mutex_destroy(&(fork->lock)) != 0)
			error_message("free_fork", MUT_DSTRY_ERR);
		free(fork);
	}
}
