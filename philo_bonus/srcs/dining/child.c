#include "philosophers_bonus.h"

void    exec_child(t_data data, pid_t *pids, int id)
{
    t_philo philo;

    free(pids);
    philo.data = data;
    philo.id = id;
    philo.last_meal = 0;
    philo.meals = 0;
}