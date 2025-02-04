/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:39 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/04 23:07:33 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "stdio.h"
#include "stdlib.h"

t_lock	*init_lock(void)
{
	t_lock	*new;

	new = malloc(sizeof(t_lock));
	if (!new)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_lock()\"\033[0m function\n");
		return (NULL);
	}
	if (pthread_mutex_init(&(new->lock), NULL) != 0)
	{
		printf(MUTEX_INIT_ERR);
		printf("Error on \033[1;31m\"init_lock()\"\033[0m function\n");
		free(new);
		return (NULL);
	}
	return (new);
}

void	set_lock(t_philo **table, t_lock *lock)
{
	int	i;

	i = 0;
	while (table[i])
	{
		table[i]->lock = lock;
		i++;
	}
}

void	set_lock2(t_philo **table, t_lock *lock)
{
	int	i;

	i = 0;
	while (table[i])
	{
		table[i]->lock2 = lock;
		i++;
	}
}

t_bool	*init_error_flag(void)
{
	t_bool	*flag;

	flag = malloc(sizeof(t_bool));
	if (!flag)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_error_flag()\"\033[0m function\n");
		return (NULL);
	}
	*flag = c_false;
	return (flag);
}

void	set_error_flag(t_philo **table, t_bool *error_flag)
{
	int	i;

	i = 0;
	while (table[i])
	{
		table[i]->error = error_flag;
		i++;
	}
}
