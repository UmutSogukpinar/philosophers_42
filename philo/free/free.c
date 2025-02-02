/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:36:01 by umut              #+#    #+#             */
/*   Updated: 2025/02/02 23:22:43 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdio.h"
#include "stdlib.h"

static t_bool	free_fork(t_fork *fork);
static t_bool	free_a_phil(t_philo *phil);

void	free_table(t_philo **table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	while (table[i] != NULL)
	{
		if (!(free_a_phil(table[i])))
		{
			printf("Error on \033[1;31m\"free_table()\"\033[0m function\n");
			free(table);
			return ;
		}
		i++;
	}
	free(table);
}

static t_bool	free_a_phil(t_philo *phil)
{
	if (phil)
	{
		phil->left_fork = NULL;
		if (!(free_fork(phil->right_fork)))
		{
			printf("Error on \033[1;31m\"free_phil()\"\033[0m function\n");
			free(phil);
			return (c_false);
		}
		free(phil);
		return (c_true);
	}
	return (c_true);
}

static t_bool	free_fork(t_fork *fork)
{
	if (fork)
	{
		if (pthread_mutex_destroy(&(fork->lock.lock)) != 0)
		{
			printf(MUTEX_DSTRY_ERR);
			printf("Error on \033[1;31m\"free_fork()\"\033[0m function\n");
			free(fork);
			return (c_false);
		}
		free(fork);
		return (c_true);
	}
	return (c_true);
}


