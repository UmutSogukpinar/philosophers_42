/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:57:03 by umut              #+#    #+#             */
/*   Updated: 2025/02/02 19:18:38 by umut             ###   ########.fr       */
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
