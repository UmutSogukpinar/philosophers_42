/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:04:19 by umut              #+#    #+#             */
/*   Updated: 2025/02/02 23:16:04 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdio.h"
#include "stdlib.h"

static t_philo	*init_a_phil(int id, t_data *data, t_death *death);
static t_fork	*init_a_fork(int id);
static void	set_forks(t_philo **table, int index);

t_bool	add_phil(t_philo **table, t_data *data, t_death *death, int id)
{
	t_philo	*new;

	new = init_a_phil(id, data, death);
	if (!new)
	{
		free_table(table);
		printf("Error on \033[1;31m\"add_phil()\"\033[0m function\n");
		return (c_false);
	}
	table[id - 1] = new;
	set_forks(table, id - 1);
	return (c_true);
}

static t_philo	*init_a_phil(int id, t_data *data, t_death *death)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_a_phil()\"\033[0m function\n");
		return (NULL);
	}
	new->right_fork = init_a_fork(id);
	if (!(new->right_fork))
	{
		free(new);
		printf("Error on \033[1;31m\"init_a_phil()\"\033[0m function\n");
		return (NULL);
	}
	new->id = id;
	new->data = data;
	new->starvation = data->time_to_die;
	new->left_fork = NULL;
	new->lock = NULL;
	new->death = death;
	new->status = thinking;
	return (new);
}

static t_fork	*init_a_fork(int id)
{
	t_fork	*new;

	new = malloc(sizeof(t_fork));
	if (!new)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_a_fork()\"\033[0m function\n");
		return (NULL);
	}
	new->id = id;
	new->is_free = c_true;
	if (pthread_mutex_init(&(new->lock.lock), NULL) != 0)
	{
		printf(MUTEX_INIT_ERR);
		printf("Error on \033[1;31m\"init_a_fork()\"\033[0m function\n");
		free(new);
		return (NULL);
	}
	return (new);
}
static void	set_forks(t_philo **table, int index)
{
	if (index <= 0)
		return ;
	(table[0])->left_fork = (table[index])->right_fork;
	(table[index])->left_fork = (table[index - 1])->right_fork;
}
