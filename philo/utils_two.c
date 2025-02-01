/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:45:42 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/01 16:47:36 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

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

t_fork	*pick_smaller_fork(t_fork *left, t_fork *right)
{
	if ((left->id) > (right->id))
		return (right);
	else
		return (left);
}
