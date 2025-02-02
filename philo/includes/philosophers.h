/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:31:43 by umut              #+#    #+#             */
/*   Updated: 2025/02/02 22:55:57 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "pthread.h"

# define ALLOC_ERR "Allocation error occured\n"
# define INV_ARGN "Invalid number of arguments\n"
# define INV_ARGS "There is/are invalid argument value at least\n"
# define MUTEX_INIT_ERR "pthread_mutex_init function does not work as expected\n"
# define MUTEX_DSTRY_ERR "pthread_mutex_destroy function does not work as expected\n"

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
	t_bool	death;
	t_lock	lock;
}					t_death;

typedef struct s_philo
{
	int				id;
	int				starvation;
	t_status		status;
	t_data			*data;
	t_death			*death;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread;
	t_lock			*lock;

}					t_philo;

t_bool	check_args(int argn, char **args);

t_bool	add_phil(t_philo **table, t_data *data, t_death *death, int id);
t_data	*init_data(int argn, char **args);
t_death	*init_death();
t_lock	*init_lock();
void	set_lock(t_philo **table, t_lock *lock);

void	free_data(t_data *data);
t_bool	free_death(t_death *death);
t_bool	free_lock(t_lock *lock);
void	free_table(t_philo **table);

void	*ft_calloc(size_t num, size_t size);
int		ft_atoi(const char *str);

#endif