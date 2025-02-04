/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:21:08 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/04 15:48:18 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "pthread.h"

# define ALLOC_ERR "Allocation error occured\n"
# define INV_ARGN "Invalid number of arguments\n"
# define INV_ARGS "There is/are invalid argument value at least\n"
# define THRD_CRT_ERR "pthread_create function doesn_t work as expected\n"
# define THRD_JOIN_ERR "pthread_join function doesn_t work as expected\n"
# define MUTEX_INIT_ERR "pthread_mutex_init function doesn't work as expected\n"
# define M_DSTRY_ERR "pthread_mutex_destroy function doesn't work as expected\n"
# define M_LOCK_ERR "pthread_mutex_lock function doesn't work as expected\n"
# define M_UNLCK_ERR "pthread_mutex_unlock function doesn't work as expected\n"

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
	c_exit = 0,
	c_error = -1
}					t_status;

typedef struct s_lock
{
	pthread_mutex_t	lock;

}					t_lock;

typedef struct s_fork
{
	int				id;
	t_bool			is_free;
	t_lock			lock;

}					t_fork;

typedef struct s_data
{
	int				number_of_phils;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_limit;

}					t_data;

typedef struct s_death
{
	t_bool			does_exist;
	t_lock			lock;
}					t_death;

typedef struct s_philo
{
	int				id;
	int				eaten_amount;
	int				starvation;
	t_status		status;
	t_data			*data;
	t_death			*death;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread;
	t_lock			*lock;
	t_bool			*error;

}					t_philo;

t_bool				thread_process(t_philo **table);

t_bool				check_args(int argn, char **args);
t_bool				are_forks_free(t_fork *left, t_fork *right);

t_bool				add_phil(t_philo **table, t_data *data, t_death *death,
						int id);
t_data				*init_data(int argn, char **args);
t_death				*init_death(void);
t_lock				*init_lock(void);
t_bool				*init_error_flag(void);
void				set_lock(t_philo **table, t_lock *lock);
void				set_error_flag(t_philo **table, t_bool *error_flag);

t_bool				safe_lock(pthread_mutex_t *mutex);
t_bool				safe_unlock(pthread_mutex_t *mutex);

t_bool				does_have_death(t_philo *philo);
t_bool				does_come_limit(t_philo *philo);
void				*routine(void *arg);
t_status			p_pick_fork(t_philo *philo);
t_status			p_sleep(t_philo *philo);
t_status			p_think(t_philo *philo);

void				free_data(t_data *data);
t_bool				free_death(t_death *death);
t_bool				free_common_lock(t_lock *lock);
void				free_table(t_philo **table);

void				*ft_calloc(size_t num, size_t size);
int					ft_atoi(const char *str);

#endif