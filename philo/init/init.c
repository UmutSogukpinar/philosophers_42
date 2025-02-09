/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:52:59 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/09 16:31:24 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

static t_philo	*init_philo(int id, t_data *data);
static t_fork	*init_fork(int id);

t_bool	init_data(int argn, char **args, t_data *data)
{
	if (argn != 6 && argn != 5)
	{
		free(data);
		return (c_false);
	}
	if (!(check_args(argn, args)))
	{
		free(data);
		return (c_false);
	}
	data->eat_limit = -1;
	data->number_phils = ft_atoi(args[1]);
	data->time_to_die = ft_atoi(args[2]);
	data->time_to_eat = ft_atoi(args[3]);
	data->time_to_sleep = ft_atoi(args[4]);
	if (argn == 6)
		data->eat_limit = ft_atoi(args[5]);
	data->number_full_phils = 0;
	data->death_flag = c_false;
	pthread_mutex_init(&(data->meal_lock), NULL);
	pthread_mutex_init(&(data->print_lock), NULL);
	return (c_true);
}

void	set_table(t_philo **table, int number_of_phils)
{
	int	i;

	if (number_of_phils == 1)
		return ;
	i = -1;
	while (++i < number_of_phils)
	{
		table[i]->left_fork = table[(i + 1) % number_of_phils]->right_fork;
		if (i % 2 == 0)
		{
			table[i]->first_fork = table[i]->right_fork;
			table[i]->last_fork = table[i]->left_fork;
		}
		else if (i % 2 == 1)
		{
			table[i]->first_fork = table[i]->left_fork;
			table[i]->last_fork = table[i]->right_fork;
		}
	}
}

t_philo	**init_table(t_data *data)
{
	t_philo	**new;
	int		i;

	new = ft_calloc((data->number_phils + 1), sizeof(t_philo *));
	if (!new)
	{
		error_message("init_table", ALLOC_ERR);
		return (NULL);
	}
	i = -1;
	while (++i < data->number_phils)
	{
		new[i] = init_philo(i + 1, data);
		if (!(new[i]))
		{
			free_table(new);
			error_message("init_table", ALLOC_ERR);
			return (NULL);
		}
	}
	return (new);
}

static t_philo	*init_philo(int id, t_data *data)
{
	t_philo	*new;

	new = ft_calloc(1, sizeof(t_philo));
	if (!new)
	{
		error_message("init_philo", ALLOC_ERR);
		return (NULL);
	}
	new->id = id;
	new->data = data;
	new->eaten_amount = 0;
	new->left_fork = NULL;
	new->right_fork = init_fork(id);
	return (new);
}

static t_fork	*init_fork(int id)
{
	t_fork	*new;

	new = ft_calloc(1, sizeof(t_fork));
	if (!new)
	{
		error_message("init_fork", ALLOC_ERR);
		return (NULL);
	}
	new->id = id;
	pthread_mutex_init(&(new->lock), NULL);
	return (new);
}
