/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:09:26 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 01:14:23 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdio.h"


static void	*routine(void *arg);

t_bool	process_second_part(t_philo **table)
{
	int	i;

	i = -1;
	display_philos(table);
	while (table[++i])
		if (pthread_create(&(table[i]->thread), NULL, routine, table[i]) != 0)
			return (c_false);
	i = -1;
	while (table[++i])
		pthread_join(table[i]->thread, NULL);
	printf("Main thread starts again\n");
	free_table(table);
	return (c_true);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)(arg);
	p_eat(philo);
	p_sleep(philo);
	p_think(philo);
	return (NULL);
}

static t_bool	p_eat(t_philo *phil)
{
	long	time;
	t_bool	status;
	
	if (phil->right_fork->is_free)
	{
		status = lock_fork(phil->right_fork);
		if (!status)
			return (c_false);
		printf("%ld %d has taken a fork\n", time, phil->id);
		if (phil->left_fork->is_free)
		{
			status = lock_fork(phil->left_fork);
			if (!status)
				return (c_false);
			printf("%ld %d has taken a fork\n", time, phil->id);
			
		}
		else
			unlock_fork(phil->right_fork);
	}
}

static void	p_sleep(t_philo *phil)
{

}

static void	p_think(t_philo *phil)
{
	
}
