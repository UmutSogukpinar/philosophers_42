#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "error_log.h"
# include "lock.h"
# include "structs.h"

// ===================== Initialization =====================

t_table	*init_table(char **argv, int argc);

t_bool	init_philos(t_philo **philos, char **argv, int argc);

t_bool	init_dining(t_table *table);

void	init_custom_data(t_custom_data *data, char **argv, int argc);
void	set_left_forks(t_philo *philos);
void	set_fork_priority(t_philo *philos);

// ===================== Routines =====================

void	*monitor(void *arg);
void	start_routine(t_philo *philo);
t_bool	eating(t_philo *philo);

// ===================== Free Function(s) =====================

void	free_table(t_table *table);

// ===================== Checker Function(s) =====================

t_bool	check_args(int argc, char **argv);

// ======================= Utils =======================

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
size_t	ft_atoui(const char *str);

t_bool	ft_isspace(char c);
t_bool	ft_isdigit(char c);

void	ft_putstr(char *str, int fd);
void	ft_putendl(char *str, int fd);

t_bool	display_status(t_philo *philo, t_status status);
t_bool	display_err_msg(char *msg);

t_ms	get_timestamp(t_shared_data *data, t_locks *locks);
void	elapse_time(t_shared_data *data, t_locks *locks, t_ms duration);

// ! For Debug
void	display_table(const t_table *table);

#endif