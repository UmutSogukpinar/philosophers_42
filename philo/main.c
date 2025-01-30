/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:51:36 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/30 21:39:54 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdio.h"
#include "stdlib.h"

t_bool	process(int arg_num, char **args, t_data *data);

void	display_philos(t_philo **philos)
{
	if (!philos)
	{
		printf("Philosopher array is NULL\n");
		return ;
	}
	printf("=== Philosophers Information ===\n");
	for (int i = 0; philos[i] != NULL; i++)
	{
		printf("Philosopher ID: %d\n", philos[i]->id);
		if (philos[i]->data)
		{
			printf("  Time to Die: %d ms\n", philos[i]->data->time_to_die);
			printf("  Time to Eat: %d ms\n", philos[i]->data->time_to_eat);
			printf("  Time to Sleep: %d ms\n", philos[i]->data->time_to_sleep);
			printf("  Eat Limit: %d\n", philos[i]->data->eat_limit);
		}
		else
		{
			printf("  Data: NULL\n");
		}
		if (philos[i]->left_fork)
		{
			printf("  Left Fork ID: %d (Is Free: %s)\n",
				philos[i]->left_fork->id,
				philos[i]->left_fork->is_free == c_true ? "Yes" : "No");
		}
		else
		{
			printf("  Left Fork: NULL\n");
		}
		if (philos[i]->right_fork)
		{
			printf("  Right Fork ID: %d (Is Free: %s)\n",
				philos[i]->right_fork->id,
				philos[i]->right_fork->is_free == c_true ? "Yes" : "No");
		}
		else
		{
			printf("  Right Fork: NULL\n");
		}
		printf("-------------------------\n");
	}
}

int	main(int arg_num, char **args)
{
	t_data	*data;

	if (!(arg_num == 5 || arg_num == 6))
		return (0);
	data = init_data(arg_num, args);
	if (!data)
		return (1);
	if (process(arg_num, args, data))
	{
		custom_free((void **)&(data));
		return (1);
	}
	custom_free((void **)&(data));
	return (0);
}

t_bool	process(int arg_num, char **args, t_data *data)
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
		if (!(add_phil(table, data, i)))
			return (c_false);
	display_philos(table);
	free_table(table);
	return (c_true);
}
