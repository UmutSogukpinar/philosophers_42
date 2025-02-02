/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:01:14 by umut              #+#    #+#             */
/*   Updated: 2025/02/02 23:17:53 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdlib.h"
#include "stdio.h"

void	free_data(t_data *data)
{
	if (data)
		free(data);
}

t_bool	free_death(t_death *death)
{
	if (death)
	{
		if (pthread_mutex_destroy(&(death->lock.lock)) != 0)
		{
			printf(MUTEX_DSTRY_ERR);
			printf("Error on \033[1;31m\"free_death()\"\033[0m function\n");
			free(death);
			return (c_false);
		}
		free(death);
		return (c_true);
	}
	return (c_true);
}

t_bool	free_lock(t_lock *lock)
{
	if (lock)
	{
		if (pthread_mutex_destroy(&(lock->lock)) != 0)
		{
			printf(MUTEX_DSTRY_ERR);
			printf("Error on \033[1;31m\"free_lock()\"\033[0m function\n");
			free(lock);
			return (c_false);
		}
		free(lock);
		return (c_true);
	}
	return (c_true);
}
