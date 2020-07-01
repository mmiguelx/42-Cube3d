/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 23:22:57 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/12 15:56:42 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src_aux;
	unsigned char	*dst_aux;

	src_aux = (unsigned char *)src;
	dst_aux = dst;
	while (n--)
	{
		*dst_aux++ = *src_aux;
		if (*src_aux++ == (unsigned char)c)
			return (dst_aux);
	}
	return (NULL);
}
