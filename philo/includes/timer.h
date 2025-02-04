/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:02:10 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/05 00:02:17 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# define GET_TIME_ERR "gettimeofday function doesn't work as expected\n"
# define ONE_MS 1000
# define ZERO_POINT_FİVE_MS 500

long		get_time(void);
t_status	spend_time(t_philo *philo, int amount);
t_status	spend_time_in_eating(t_philo *philo, int amount);

#endif