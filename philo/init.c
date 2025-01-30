/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:46 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/30 21:42:43 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdlib.h"

static t_philo	*init_a_phil(int id, t_data *data);
static t_fork	*init_a_fork(int id);
static void		update_table(t_philo **table, int index);

t_bool	add_phil(t_philo **table, t_data *data, int id)
{
	t_philo	*new;

	new = init_a_phil(id, data);
	if (!new)
	{
		free_table(table);
		return (c_false);
	}
	table[id - 1] = new;
	update_table(table, id - 1);
	return (c_true);
}

static t_philo	*init_a_phil(int id, t_data *data)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->data = data;
	new->left_fork = NULL;
	new->right_fork = init_a_fork(id);
	if (!(new->right_fork))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static t_fork	*init_a_fork(int id)
{
	t_fork	*new;

	new = malloc(sizeof(t_fork));
	if (!new)
		return (NULL);
	new->id = id;
	new->is_free = c_true;
	return (new);
}

static void	update_table(t_philo **table, int index)
{
	if (index == 0)
		return ;
	(table[0])->left_fork = (table[index])->right_fork;
	(table[index])->left_fork = (table[index - 1])->right_fork;
}
