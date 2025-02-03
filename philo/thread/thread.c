/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:02 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/03 13:25:25 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdio.h"

static t_bool	create_joins(t_philo **table);
static t_bool	create_threads(t_philo **table);

t_bool	thread_process(t_philo **table)
{
	if (create_threads(table) == c_false)
	{
		printf("Error on \033[1;31m\"thread_process()\"\033[0m function\n");
		return (c_false);
	}
	if (create_joins(table) == c_false)
	{
		printf("Error on \033[1;31m\"thread_process()\"\033[0m function\n");
		return (c_false);
	}
	return (c_true);
}

static t_bool	create_threads(t_philo **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		if (pthread_create(&(table[i]->thread), NULL, routine, table[i]) != 0)
		{
			printf(THRD_CRT_ERR);
			printf("Error on \033[1;31m\"create_threads()\"\033[0m function\n");
			*(table[i]->error) = c_true;
			return (c_false);
		}
		i++;
	}
	return (c_true);
}

static t_bool	create_joins(t_philo **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		if (pthread_join((table[i]->thread), NULL) != 0)
		{
			printf(THRD_JOIN_ERR);
			printf("Error on \033[1;31m\"create_joins()\"\033[0m function\n");
			*(table[i]->error) = c_true;
			return (c_false);
		}
		i++;
	}
	return (c_true);
}
