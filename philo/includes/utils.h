#ifndef UTILS_S
# define UTILS_S

#include "philosophers.h"

t_bool		check_death(t_philo *philo);
t_bool		check_satisfaction(t_philo *philo);
t_bool		check_fork(t_philo *philo);
t_bool		check_args(int argn, char **args);
t_bool		check_routine_finish(t_data *data);

void		free_table(t_philo **table);
void		set_table(t_philo **table, t_data *data);
t_status	ft_print_status(t_philo *philo, char *str);

void		*ft_calloc(size_t num, size_t size);
int			ft_atoi(const char *str);

#endif