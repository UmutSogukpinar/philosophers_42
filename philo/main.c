/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:21:48 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/04 16:07:54 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"
#include "stdlib.h"
#include "stdio.h"

static t_bool	process(t_data *data, t_death *death);
static t_bool	process_two(t_philo **table);
static t_bool	process_three(t_philo **table);

int	main(int argn, char **args)
{
	t_data	*data;
	t_death	*death;

	if (!(check_args(argn, args)))
		return (0);
	data = init_data(argn, args);
	death = init_death();
	if (!data || !death)
	{
		free_data(data);
		free_death(death);
		return (1);
	}
	if (process(data, death))
	{
		free_data(data);
		free_death(death);
		return (0);
	}
	free_data(data);
	free_death(death);
	return (1);
}

static t_bool	process(t_data *data, t_death *death)
{
	int		i;
	t_philo	**table;

	table = ft_calloc((data->number_of_phils + 1), sizeof(t_philo *));
	if (!table)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"process()\"\033[0m function\n");
		return (c_false);
	}
	i = 0;
	while (++i <= data->number_of_phils)
	{
		if (!(add_phil(table, data, death, i)))
		{
			printf("Error on \033[1;31m\"process()\"\033[0m function\n");
			return (c_false);
		}
	}
	if (process_two(table))
		return (c_true);
	printf("Error on \033[1;31m\"process()\"\033[0m function\n");
	return (c_false);
}

static t_bool	process_two(t_philo **table)
{
	t_lock	*common_lock;

	common_lock = init_lock();
	if (!common_lock)
	{
		printf("Error on \033[1;31m\"process_two()\"\033[0m function\n");
		free_table(table);
		return (c_false);
	}
	set_lock(table, common_lock);
	if (process_three(table))
	{
		free_common_lock(common_lock);
		free_table(table);
		return (c_true);
	}
	free_common_lock(common_lock);
	free_table(table);
	printf("Error on \033[1;31m\"process_two()\"\033[0m function\n");
	return (c_false);
}

static t_bool	process_three(t_philo **table)
{
	t_bool	*error_flag;

	error_flag = init_error_flag();
	if (!error_flag)
	{
		printf("Error on \033[1;31m\"process_three()\"\033[0m function\n");
		return (c_false);
	}
	set_error_flag(table, error_flag);
	if (thread_process(table) == c_true)
	{
		free(error_flag);
		return (c_true);
	}
	free(error_flag);
	printf("Error on \033[1;31m\"process_three()\"\033[0m function\n");
	return (c_false);
}
