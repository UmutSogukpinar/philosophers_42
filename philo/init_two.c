/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:56:40 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/31 13:37:29 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdio.h"
#include "stdlib.h"

static t_bool	check_datas(t_data *data);

t_data	*init_data(int arg_num, char **args)
{
	t_data	*new;

	if (!(arg_num == 5 || arg_num == 6))
		return (NULL);
	new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->time_to_die = ft_atoi(args[2]);
	new->time_to_eat = ft_atoi(args[3]);
	new->time_to_sleep = ft_atoi(args[4]);
	if (arg_num == 5)
		new->eat_limit = -1;
	else if (arg_num == 6)
		new->eat_limit = ft_atoi(args[5]);
	if (!check_datas(new))
	{
		free(new);
		printf("Invalid arguments\n");
		return (NULL);
	}
	return (new);
}

static t_bool	check_datas(t_data *data)
{
	if (data->time_to_die == 0 || data->time_to_eat == 0
		|| data->time_to_sleep == 0 || data->eat_limit == 0)
		return (c_false);
	else
		return (c_true);
}
