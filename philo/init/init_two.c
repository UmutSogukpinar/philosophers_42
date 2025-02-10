/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:49:18 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/10 15:00:09 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

static t_bool	init_data_two(t_data *data);

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
	if (!(init_data_two(data)))
	{
		error_message("init_data", NULL);
		free(data);
		return (c_false);
	}
	return (c_true);
}

static t_bool	init_data_two(t_data *data)
{
	data->number_full_phils = 0;
	data->death_flag = c_false;
	if (pthread_mutex_init(&(data->meal_lock), NULL) != 0)
	{
		error_message("init_data_two", MUT_INIT_ERR);
		return (c_false);
	}
	if (pthread_mutex_init(&(data->print_lock), NULL) != 0)
	{
		error_message("init_data_two", MUT_INIT_ERR);
		if (pthread_mutex_destroy(&(data->meal_lock)) != 0)
			error_message("init_data_two", MUT_DSTRY_ERR);
		return (c_false);
	}
	return (c_true);
}
