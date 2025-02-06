/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:02:10 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/06 15:16:17 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# define GET_TIME_ERR "gettimeofday function doesn't work as expected\n"
# define ONE_MS 1000
# define ZERO_POINT_FİVE_MS 500

long		get_time(void);
t_status	spend_time(t_philo *philo, int amount);
t_status	spend_time2(t_philo *philo, double amount);
t_status	spend_time_in_eating(t_philo *philo, int amount);

#endif