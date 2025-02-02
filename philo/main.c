/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:30:34 by umut              #+#    #+#             */
/*   Updated: 2025/02/02 23:11:11 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdio.h"

static t_bool	process(t_data *data, t_death *death);
static t_bool	process_two(t_philo	**table);
static t_bool	process_three(t_philo **table);

void display_table(t_philo **table) {
    if (!table) {
        printf("Error: Table is NULL!\n");
        return;
    }

    printf("\n===== Philosopher Table =====\n");
    int i = 0;
    while (table[i]) {  // NULL gelene kadar devam et
        printf("\033[1;34mPhilosopher ID:\033[0m %d\n", table[i]->id);
        printf("\033[1;32mStarvation:\033[0m %d\n", table[i]->starvation);
        
        // Filozofun durumu
        char *status;
        switch (table[i]->status) {
            case eating: status = "Eating"; break;
            case thinking: status = "Thinking"; break;
            case sleeping: status = "Sleeping"; break;
            case c_exit: status = "Exited"; break;
            case c_error: status = "Error"; break;
            default: status = "Unknown"; break;
        }
        printf("\033[1;33mStatus:\033[0m %s\n", status);

        // Çatal bilgileri
        printf("\033[1;35mLeft Fork:\033[0m %d\n", table[i]->left_fork ? table[i]->left_fork->id : -1);
        printf("\033[1;36mRight Fork:\033[0m %d\n", table[i]->right_fork ? table[i]->right_fork->id : -1);

        printf("\n----------------------------------\n");

        i++;  // Bir sonraki filozofa geç
    }
}



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
		if (!(add_phil(table, data, death, i)))
		{
			printf("Error on \033[1;31m\"process()\"\033[0m function\n");
			return (c_false);
		}
	if (process_two(table))
		return (c_true);
	printf("Error on \033[1;31m\"process()\"\033[0m function\n");
	return (c_false);
}

static t_bool	process_two(t_philo	**table)
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
		free_lock(common_lock);
		free_table(table);
		return (c_true);
	}
	free_lock(common_lock);
	free_table(table);
	printf("Error on \033[1;31m\"process_two()\"\033[0m function\n");
	return (c_false);
}

static t_bool	process_three(t_philo **table)
{
	display_table(table);
	return (c_true);
}
