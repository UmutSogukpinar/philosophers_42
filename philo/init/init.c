/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:21:23 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/03 15:46:45 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdio.h"
#include "stdlib.h"

t_data	*init_data(int argn, char **args)
{
	t_data	*new;
	int		invalid_target;

	new = malloc(sizeof(t_data));
	if (!new)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_data()\"\033[0m function\n");
		return (NULL);
	}
	new->number_of_phils = ft_atoi(args[1]);
	new->time_to_die = ft_atoi(args[2]);
	new->time_to_eat = ft_atoi(args[3]);
	new->time_to_sleep = ft_atoi(args[4]);
	invalid_target = -1;
	if (argn == 5)
		new->eat_limit = invalid_target;
	else
		new->eat_limit = ft_atoi(args[5]);
	return (new);
}

t_death	*init_death(void)
{
	t_death	*new;

	new = malloc(sizeof(t_death));
	if (!new)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_death()\"\033[0m function\n");
		return (NULL);
	}
	new->does_exist = c_false;
	if (pthread_mutex_init(&(new->lock.lock), NULL) != 0)
	{
		free(new);
		printf(MUTEX_INIT_ERR);
		printf("Error on \033[1;31m\"init_death()\"\033[0m function\n");
		return (NULL);
	}
	return (new);
}
