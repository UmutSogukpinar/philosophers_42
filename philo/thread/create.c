/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:53:43 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/23 11:58:27 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_threads(t_philo **table, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_phils)
	{
		if (pthread_create(&(table[i]->thread), NULL, routine, table[i]) != 0)
		{
			data->error_flag = c_true;
			break ;
		}
		i++;
	}
}

void	create_joins(t_philo **table, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_phils)
	{
		if (pthread_join(table[i]->thread, NULL) != 0)
		{
			data->error_flag = c_true;
			break ;
		}
		i++;
	}
}

t_bool	one_philo_exception(t_philo **table, t_data *data)
{
	if (data->number_phils != 1)
		return (c_true);
	if (pthread_create(&(table[0]->thread), NULL, routine_exception,
			table[0]) != 0)
	{
		data->error_flag = c_true;
		return (c_false);
	}
	if (pthread_join(table[0]->thread, NULL) != 0)
	{
		data->error_flag = c_true;
		return (c_false);
	}
	return (c_true);
}

t_bool	three_philo_exception(t_philo **table, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_phils)
	{
		if (pthread_create(&(table[i]->thread), NULL, routine_three,
				table[i]) != 0)
		{
			data->error_flag = c_true;
			return (c_false);
		}
		i++;
	}
	i = 0;
	while (i < data->number_phils)
	{
		if (pthread_join(table[i]->thread, NULL) != 0)
		{
			data->error_flag = c_true;
			return (c_false);
		}
		i++;
	}
	return (c_true);
}
