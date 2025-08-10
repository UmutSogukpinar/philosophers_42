#include "philosophers.h"
#include "string.h"

static t_bool	init_philo(t_philo *philo, char **argv, int argc);

t_bool	init_philos(t_philo **philos, char **argv, int argc)
{
	int		i;
	t_philo	*dummy;
	int		number_of_phils;

	number_of_phils = ft_atoui(argv[1]);
	*philos = ft_calloc(number_of_phils, sizeof(t_philo));
	dummy = *philos;
	if (!dummy)
		return (display_err_msg(ALLOC_ERR));
	i = 0;
	while (i < number_of_phils)
	{
		init_philo(&dummy[i], argv, argc);
		dummy[i].id = i + 1;
		dummy[i].data.number_of_phils = number_of_phils;
		i++;
	}
	return (TRUE);
}

static t_bool	init_philo(t_philo *philo, char **argv, int argc)
{
	memset(philo, 0, sizeof(t_philo));
	init_custom_data(&philo->data, argv, argc);
	philo->right_fork = ft_calloc(1, sizeof(t_mutex));
	if (!philo->right_fork)
		return (display_err_msg(ALLOC_ERR));
	if (pthread_mutex_init(philo->right_fork, NULL) != SUCCESS)
		return (display_err_msg(MTX_INIT_ERR));
	return (TRUE);
}


void	init_custom_data(t_custom_data *data, char **argv, int argc)
{
	data->number_eat = 0;
	data->lifetime = ft_atoui(argv[2]);
	data->meal_time = ft_atoui(argv[3]);
	data->sleep_time = ft_atoui(argv[4]);
	if (argc == 5)
		data->eat_limit = -1;
	else
		data->eat_limit = ft_atoui(argv[5]);
	data->last_meal_time = 0;
}

void	set_left_forks(t_philo *philos)
{
	size_t	i;
	size_t	len;

	len = philos[0].data.number_of_phils;
	i = 0;
	if (len == 1)
	{
		philos[0].left_fork = NULL;
		return ;
	}
	while (i < len)
	{
		philos[i].left_fork = philos[(i + 1) % len].right_fork;
		i++;
	}
}

void	set_fork_priority(t_philo *philos)
{
	size_t	i;
	size_t	len;

	len = philos[0].data.number_of_phils;
	i = 0;
	while (i < len)
	{
		if (i % 2 == 0)
		{
			philos[i].first_fork = philos[i].right_fork;
			philos[i].last_fork = philos[i].left_fork;
		}
		else
		{
			philos[i].first_fork = philos[i].left_fork;
			philos[i].last_fork = philos[i].right_fork;
		}
		i++;
	}
}
