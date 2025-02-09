/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:27 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/09 15:01:37 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "stdio.h"
#include "stdlib.h"

t_status	error_message(char *func_name, char *message)
{
	if (message)
		printf("%s", message);
	printf("Error on \033[1;31m\"%s()\"\033[0m function\n", func_name);
	return (c_exit);
}

void	free_table(t_philo **table)
{
	int	i;

	if (table)
	{
		i = -1;
		while (table[++i])
			free(table[i]);
		free(table);
	}
}
