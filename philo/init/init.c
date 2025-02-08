#include "stdio.h"
#include "stdlib.h"
#include "philosophers.h"
#include "utils.h"

static t_fork	*init_fork(int id);
static t_philo	*init_philo(int id, t_data *data);
static t_philo	**init_table(int amount, t_data *data);

t_greece	*init_ancient_greece(t_data *data)
{
	t_greece	*ancient_greece;

	ancient_greece = ft_calloc(1, sizeof(t_greece));
	if (!ancient_greece)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_ancient_greece()\"\033[0m function\n");
		return (NULL);
	}
	ancient_greece->data = data;
	ancient_greece->table = init_table(data->number_phils, data);
	if (!(ancient_greece->table))
	{
		free(ancient_greece);
		printf("Error on \033[1;31m\"init_ancient_greece()\"\033[0m function\n");
		return (NULL);
	}
	return (ancient_greece);
}

t_data	*init_data(int argn, char **args)
{
	t_data	*new;

	new = ft_calloc(1, sizeof(t_data));
	if (!new)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_data()\"\033[0m function\n");
		return (NULL);
	}
	new->number_phils = ft_atoi(args[1]);
	new->time_to_die = ft_atoi(args[2]);
	new->time_to_eat = ft_atoi(args[3]);
	new->time_to_sleep = ft_atoi(args[4]);
	new->eat_limit = -1;
	if (argn == 6)
		new->eat_limit = ft_atoi(args[5]);
	new->number_full_phils = 0;
	new->start_time = 0;
	new->death_flag = c_false;
	new->eat_limit_flag = c_false;
	pthread_mutex_init(&(new->meal_lock.lock), NULL);
	pthread_mutex_init(&(new->dead_lock.lock), NULL);
	pthread_mutex_init(&(new->waiter_lock.lock), NULL);
	pthread_mutex_init(&(new->print_lock.lock), NULL);
	return (new);
}

static t_philo	**init_table(int amount, t_data *data)
{
	t_philo	**table;
	int		i;

	table = ft_calloc(amount + 1, sizeof(t_philo *));
	if (!table)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_table()\"\033[0m function\n");
		return (NULL);
	}
	i = -1;
	while (++i < amount)
	{
		table[i] = init_philo(i + 1, data);
		if (table[i] == NULL)
		{
			free_table(table);
			printf("Error on \033[1;31m\"init_table()\"\033[0m function\n");
			return (NULL);
		}
	}
	table[i] = NULL;
	return (table);
}

static t_philo	*init_philo(int id, t_data *data)
{
	t_philo	*new;

	new = ft_calloc(1, sizeof(t_philo));
	if (!new)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_philo()\"\033[0m function\n");
		return (NULL);
	}
	new->id = id;
	new->data = data;
	new->eaten_amount = data->eat_limit;
	new->last_meal_time = 9223372036854775807;
	new->left_fork = NULL;
	new->right_fork = init_fork(id);
	new->status = c_thinking;
	return (new);
}

static t_fork	*init_fork(int id)
{
	t_fork	*new;

	new = ft_calloc(1, sizeof(t_fork));
	if (!new)
	{
		printf(ALLOC_ERR);
		printf("Error on \033[1;31m\"init_fork()\"\033[0m function\n");
		return (NULL);
	}
	new->id = id;
	new->is_free = c_true;
	return (new);
}
