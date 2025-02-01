/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:02:32 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 10:56:00 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdlib.h"

void	custom_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_table(t_philo **table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	while (table[i] != NULL)
	{
		if (table[i])
		{
			custom_free((void **)&(table[i]->right_fork));
			custom_free((void **)&(table[i]));
		}
		i++;
	}
	free(table);
	table = NULL;
}
