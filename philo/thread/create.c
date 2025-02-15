/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:53:43 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/15 13:24:03 by usogukpi         ###   ########.fr       */
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
