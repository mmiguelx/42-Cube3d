/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:46:51 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/16 15:18:13 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t n;

	i = ft_strlen(dst);
	if (size > i)
	{
		n = 0;
		while (--size - i && *(src + n))
		{
			*(dst + i + n) = *(src + n);
			++n;
		}
		*(dst + i + n) = '\0';
		return (i + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
