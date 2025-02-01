/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:51:36 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 12:45:33 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdio.h"
#include "stdlib.h"

static t_bool	process(char **args, t_data *data, t_bool *death);

#include <stdio.h>

void	display_philos(t_philo **table)
{
	int	i;

	if (!table)
	{
		printf("Table is empty or NULL.\n");
		return;
	}
	i = 0;
	while (table[i])
	{
		printf("Philosopher %d:\n", table[i]->id);
		printf("  Starvation: %d\n", table[i]->starvation);
		printf("  Left Fork ID: %d | Status: %s\n",
			table[i]->left_fork->id,
			table[i]->left_fork->is_free ? "Free" : "Taken");
		printf("  Right Fork ID: %d | Status: %s\n",
			table[i]->right_fork->id,
			table[i]->right_fork->is_free ? "Free" : "Taken");
		printf("------------------------------------------------\n");
		i++;
	}
}


int	main(int arg_num, char **args)
{
	t_data	*data;
	t_bool	*death;

	if (!(arg_num == 5 || arg_num == 6))
		return (0);
	data = init_data(arg_num, args);
	if (!data)
		return (1);
	death = init_death();
	if (!death)
	{
		custom_free((void **)&(data));
		return (1);
	}
	if (process(args, data, death))
	{
		custom_free((void **)&(data));
		custom_free((void **)&(death));
		return (1);
	}
	custom_free((void **)&(data));
	custom_free((void **)&(death));
	return (0);
}

static t_bool	process(char **args, t_data *data, t_bool *death)
{
	t_philo	**table;
	int		phil_num;
	int		i;

	phil_num = ft_atoi(args[1]);
	if (phil_num <= 0)
		return (c_false);
	table = malloc(sizeof(t_philo *) * (phil_num + 1));
	if (!table)
		return (c_false);
	i = -1;
	while (++i < phil_num)
		table[i] = NULL;
	table[phil_num] = NULL;
	i = 0;
	while (++i <= phil_num)
		if (!(add_phil(table, data, death, i)))
			return (c_false);
	if (process_second_part(table))
		return (c_true);
	else
		return (c_false);
}
