/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:51:55 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/10 14:59:37 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "pthread.h"

# define ALLOC_ERR "Allocation error occured\n"
# define INV_ARGN "Invalid number of arguments\n"
# define INV_ARGS "There is/are invalid argument value at least\n"
# define MUT_INIT_ERR "pthread_mutex_init doesn't work as expected\n"
# define MUT_DSTRY_ERR "pthread_mutex_destroy doesn't work as expected\n"

# define DEATH_MSG "died\n"
# define FORK_MSG "has taken a fork\n"
# define EAT_MSG "is eating\n"
# define SLEEP_MSG "is sleeping\n"
# define THINK_MSG "is thinking\n"

typedef long long	t_ms;

typedef enum e_bool
{
	c_true = 1,
	c_false = 0
}					t_bool;

typedef enum e_status
{
	c_death = 5,
	c_sleeping = 4,
	c_eating = 3,
	c_taking_forks = 2,
	c_thinking = 1,
	c_exit = 0,
	c_error = -1
}					t_status;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	lock;

}					t_fork;

typedef struct s_data
{
	int				number_phils;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_limit;
	int				number_full_phils;
	t_ms			milestone;
	t_bool			death_flag;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;

}					t_data;

typedef struct s_philo
{
	int				id;
	int				eaten_amount;
	t_ms			death_time;
	t_data			*data;
	t_fork			*right_fork;
	t_fork			*left_fork;
	t_fork			*first_fork;
	t_fork			*last_fork;
	pthread_t		thread;

}					t_philo;

t_philo				**init_table(t_data *data);
t_bool				init_data(int argn, char **args, t_data *data);
void				set_table(t_philo **table, int number_of_phils);
void				create_threads(t_philo **table, t_data *data);
void				create_joins(t_philo **table, t_data *data);
void				*routine(void *arg);

void				p_eat(t_philo *philo, t_data *data);
void				p_die(t_philo *philo);
void				p_sleep(t_philo *philo);
void				p_think(t_philo *philo);

#endif
