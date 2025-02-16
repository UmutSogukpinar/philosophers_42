/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:47 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/16 18:19:02 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/timer.h"
#include "./includes/utils.h"

static t_bool	main_part_two(t_philo **table, t_data *data);

int	main(int argn, char **args)
{
	t_data	*data;
	t_philo	**table;

	if (argn != 5 && argn != 6)
		return ((error_message("main", INV_ARGN)) - 254);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return ((error_message("main", ALLOC_ERR)) - 254);
	if (!(init_data(argn, args, data)))
		return (error_message("main", NULL) - 254);
	table = init_table(data);
	if (!table)
	{
		free_data(data);
		return (error_message("main", NULL) - 254);
	}
	set_table(table, data->number_phils);
	if (!(main_part_two(table, data)))
		return (error_message("main", NULL) - 254);
	return (0);
}

static t_bool	main_part_two(t_philo **table, t_data *data)
{
	data->milestone = get_time();
	if (data->number_phils == 1 || data->number_phils == 3)
	{
		if (one_philo_exception(table, data) == c_false)
		{
			free_table(table);
			free_data(data);
			return (c_false);
		}
		// three_philo_exception
		free_table(table);
		free_data(data);
		return (c_true);
	}
	create_threads(table, data);
	create_joins(table, data);
	free_table(table);
	free_data(data);
	return (c_true);
}
