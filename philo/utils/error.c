/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:27 by usogukpi          #+#    #+#             */
/*   Updated: 2025/02/15 16:27:17 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../includes/philosophers.h"

t_status	error_message(char *func_name, char *message)
{
	if (message)
		printf("%s", message);
	printf("Error on \033[1;31m\"%s()\"\033[0m function\n", func_name);
	return (c_error);
}
