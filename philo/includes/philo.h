/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:51:41 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 17:42:21 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "pthread.h"

# define ZERO_POINT_FIVE_MS 500

typedef enum e_bool
{
	c_true = 1,
	c_false = 0
}					t_bool;

typedef enum e_status
{
	sleeping = 3,
	thinking = 2,
	eating = 1,
	c_exit = 0
}					t_status;

typedef struct s_fork
{
	int				id;
	t_bool			is_free;
	pthread_mutex_t	mutex;

}					t_fork;

typedef struct s_data
{
	int				number_of_phils;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_limit;

}					t_data;

typedef struct s_philo
{
	int				id;
	int				starvation;
	t_data			*data;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_bool			*death;
	pthread_t		thread;

}					t_philo;

void				custom_free(void **ptr);
void				free_table(t_philo **table);
t_bool				add_phil(t_philo **table, t_data *data, t_bool *death,
						int id);
t_data				*init_data(int arg_num, char **args);
t_bool				*init_death(void);
t_bool				process_second_part(t_philo **table);

t_status			p_sleep(t_philo *phil);
t_status			p_think(t_philo *phil);

t_bool				lock_fork(t_fork *fork, long *time);
void				unlock_fork(t_fork *fork);
void				unlock_both_fork(t_fork *left_fork, t_fork *right_fork);

int					ft_atoi(const char *str);
t_fork				*pick_smaller_fork(t_fork *left, t_fork *right);

long				to_ms(long seconds, long microseconds);
t_bool				get_time(t_philo *phil, long *time);
void				spend_time(t_philo *phil, int amount);
t_status			spend_ms(t_philo *phil, int amount);
t_bool				is_dead(t_philo *philo);

void				display_philos(t_philo **philos);

#endif