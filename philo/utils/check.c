/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:34 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/09 16:35:32 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"
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

t_bool	check_satisfaction(t_data *data)
{
	if (data->eat_limit == -1)
		return (c_false);
	if (data->number_phils == data->number_full_phils)
		return (c_true);
	else
		return (c_false);
}
