/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:57:46 by umut              #+#    #+#             */
/*   Updated: 2025/02/02 22:59:46 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*p;
	size_t			total;

	total = num * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
