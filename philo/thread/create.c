/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:53:43 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/09 14:53:52 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_threads(t_philo **table, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_phils)
	{
		pthread_create(&(table[i]->thread), NULL, routine, table[i]);
		i++;
	}
}

void	create_joins(t_philo **table, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_phils)
	{
		pthread_join(table[i]->thread, NULL);
		i++;
	}
}
