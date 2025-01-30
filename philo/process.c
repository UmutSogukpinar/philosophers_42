/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:09:26 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/30 22:53:23 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include "stdio.h"
#include "unistd.h"

static void    *routine(void *arg);

t_bool  process_second_part(t_philo **table)
{
    int i;

    i = -1;
    while (table[++i])
        if (pthread_create(&(table[i]->thread), NULL, routine, table[i]) != 0)
            return (c_false);
    i = -1;
    while (table[++i])
        pthread_join(table[i]->thread, NULL);
    display_philos(table);
    free_table(table);
    return (c_true);
}

static void    *routine(void *arg)
{
    t_philo *philo;
   
    philo = (t_philo *)(arg);
    printf("philosophers %d thinks\n", philo->id);
    sleep(2);
    printf("philosophers %d stops thinking\n", philo->id);
    return (NULL);
}
