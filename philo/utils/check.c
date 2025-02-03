/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:21:39 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/03 18:02:26 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "stdio.h"

t_bool	check_args(int argn, char **args)
{
	int	i;
	int	num;

	if (!(argn == 5 || argn == 6))
	{
		printf(INV_ARGN);
		return (c_false);
	}
	i = 0;
	while (++i <= argn - 1)
	{
		num = ft_atoi(args[i]);
		if (num <= 0)
		{
			printf(INV_ARGS);
			return (c_false);
		}
	}
	return (c_true);
}

t_bool	are_forks_free(t_fork *left, t_fork *right)
{
	return (left->is_free && right->is_free);
}
