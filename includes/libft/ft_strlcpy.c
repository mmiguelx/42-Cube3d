/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:33:25 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/16 15:24:22 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if (!dst || !src)
		return (0);
	if (dstsize)
	{
		i = 0;
		while (--dstsize && *(src + i))
		{
			*(dst + i) = *(src + i);
			++i;
		}
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}
