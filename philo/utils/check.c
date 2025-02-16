/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:34 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/16 16:16:05 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "stdio.h"

static t_bool	is_digit(char c);
static t_bool	check_args_two(char *arg);

t_bool	check_args(int argn, char **args)
{
	int	i;
	int	num;

	if (!(argn == 5 || argn == 6))
	{
		printf(INV_ARGN);
		return (c_false);
	}
	i = 0;
	while (++i <= argn - 1)
	{
		if (!(check_args_two(args[i])))
			return (c_false);
		num = ft_atoi(args[i]);
		if (num <= 0)
		{
			printf(INV_ARGS);
			return (c_false);
		}
	}
	return (c_true);
}

t_bool	check_satisfaction(t_data *data)
{
	if (data->eat_limit == -1)
		return (c_false);
	pthread_mutex_lock(&(data->meal_lock));
	if (data->number_phils == data->number_full_phils)
	{
		pthread_mutex_unlock(&(data->meal_lock));
		return (c_true);
	}
	pthread_mutex_unlock(&(data->meal_lock));
	return (c_false);
}

static t_bool	check_args_two(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i] != '\0')
	{
		if (!(is_digit(arg[i])))
			return (c_false);
	}
	return (c_true);
}

static t_bool	is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (c_true);
	return (c_false);
}
