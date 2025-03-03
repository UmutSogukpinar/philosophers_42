/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:37 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/16 16:51:53 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "sys/time.h"
#include "unistd.h"

t_ms	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (((long long)t.tv_sec * 1000) + ((long long)t.tv_usec / 1000));
}

void	ft_sleep(t_ms waiting_time)
{
	t_ms	t;

	t = get_time();
	while (waiting_time - t > 5)
	{
		usleep(1000 * (waiting_time - t - 5));
		t = get_time();
	}
	while (waiting_time > t)
		t = get_time();
}
