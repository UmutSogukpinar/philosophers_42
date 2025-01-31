/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:25:42 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 00:59:14 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "sys/time.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	acc;

	acc = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		acc = acc * 10 + (str[i] - 48);
		i++;
	}
	return (sign * acc);
}

long	to_ms(long seconds, long microseconds)
{
	return ((seconds * 1000) + (microseconds / 1000));
}

t_bool	get_time(long *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 0)
	{
		*time = to_ms(tv.tv_sec, tv.tv_sec);
		return (c_true);
	}
	printf("gettimeofday error\n");
	return (c_false);
}
