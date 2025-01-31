/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:51:41 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/31 19:00:26 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0

# include "pthread.h"

typedef enum e_bool
{
	c_true = 1,
	c_false = 0
}			t_bool;

typedef struct s_fork
{
	int				id;
	t_bool			is_free;
	pthread_mutex_t	mutex;

}			t_fork;

typedef struct s_data
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eat_limit;

}			t_data;

typedef struct s_philo
{
	int			id;
	int			starvation;
	t_data		*data;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread;

}			t_philo;

void		custom_free(void **ptr);
void		free_table(t_philo **table);
t_bool		add_phil(t_philo **table, t_data *data, int id);
t_data		*init_data(int arg_num, char **args);
t_bool		process_second_part(t_philo **table);

int			ft_atoi(const char *str);
long		to_ms(long seconds, long microseconds);

void		display_philos(t_philo **philos);

#endif