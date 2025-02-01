/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:09:26 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 17:57:58 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdio.h"

static void		*routine(void *arg);
static t_status	p_take_fork_one(t_philo *phil);
static t_status	p_take_fork_two(t_philo *phil);
static t_status	p_eat(t_philo *phil);

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
	t_philo		*philo;
	t_status	status;

	philo = (t_philo *)(arg);
	while (!(philo->death))
	{
		if (philo->data->number_of_phils % 2 == 1)
			status = p_take_fork_one(philo);
		else
			status = p_take_fork_two(philo);
		if (status == c_exit)
		{
			philo->death = c_true;
			break ;
		}
		if (p_sleep(philo) == c_exit)
		{
			philo->death = c_true;
			break ;
		}
		if (p_think(philo) == c_exit)
		{
			philo->death = c_true;
			break ;
		}
	}
	return (NULL);
}

static t_status	p_take_fork_one(t_philo *phil)
{
	static int	first_run;
	static int	turn;
	long		time;

	first_run = 0;
	turn = 0;
	if (phil->id % 2 == turn && first_run == 0)
	{
		spend_time(phil, phil->data->time_to_eat);
		if (is_dead(phil))
			return (c_exit);
		first_run++;
	}
	if (!(lock_fork(phil->left_fork, &time)))
		return (c_exit);
	if (!(lock_fork(phil->right_fork, &time)))
	{
		pthread_mutex_unlock(phil->left_fork);
		return (c_exit);
	}
	if (!is_dead(phil))
		printf("%ld %d has taken a fork\n", time, phil->id);
	return (p_eat(phil));
}

static t_status	p_take_fork_two(t_philo *phil)
{
	return (eating);
}

static t_status	p_eat(t_philo *phil)
{
	long	time;

	if (!get_time(phil, &time))
	{
		unlock_both_fork(phil->left_fork, phil->right_fork);
		return (c_exit);
	}
	if (!is_dead(phil))
		printf("%ld %d is eating\n", time, phil->id);
	if (spend_ms(phil, phil->data->time_to_eat) == c_exit)
	{
		unlock_both_fork(phil->left_fork, phil->right_fork);
		return (c_exit);
	}
	return (eating);
}
