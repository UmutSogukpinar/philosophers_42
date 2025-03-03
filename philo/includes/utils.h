/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:52:06 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/15 14:09:51 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philosophers.h"

void		print_status(t_philo *philo, t_status status);
void		*ft_calloc(size_t num, size_t size);
int			ft_atoi(const char *str);

t_bool		check_args(int argn, char **args);
t_bool		check_satisfaction(t_data *data);

void		set_table(t_philo **table, int number_of_phils);
t_status	error_message(char *func_name, char *message);

void		free_table(t_philo **table);
void		free_data(t_data *data);

#endif