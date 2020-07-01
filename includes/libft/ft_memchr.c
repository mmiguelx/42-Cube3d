/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:48:46 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/08 20:57:43 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *aux;

	aux = (unsigned char*)s;
	while (n--)
	{
		if (*(aux++) == (unsigned char)c)
			return (--aux);
	}
	return (NULL);
}
