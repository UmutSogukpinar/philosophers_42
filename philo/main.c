/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:47 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/10 13:42:43 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"
#include "./includes/timer.h"
#include "./includes/utils.h"

static t_bool	main_part_two(t_philo **table, t_data *data);

int	main(int argn, char **args)
{
	t_data	*data;
	t_philo	**table;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (error_message("main", ALLOC_ERR));
	if (!(init_data(argn, args, data)))
		return (error_message("main", NULL));
	table = init_table(data);
	if (!table)
	{
		free_data(data);
		return (error_message("main", NULL));
	}
	set_table(table, data->number_phils);
	if (!(main_part_two(table, data)))
		return (error_message("main", NULL));
	return (0);
}

static t_bool	main_part_two(t_philo **table, t_data *data)
{
	data->milestone = get_time();
	if (data->number_phils == 1)
	{
		print_status(table[0], c_taking_forks);
		ft_sleep(data->milestone + data->time_to_die);
		print_status(table[0], c_death);
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
