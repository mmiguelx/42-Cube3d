/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:05:59 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/12 13:30:05 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*aux;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	aux = malloc(count * size);
	if (!aux)
		return (NULL);
	ft_bzero(aux, count * size);
	return (aux);
}
