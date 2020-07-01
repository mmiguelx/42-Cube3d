/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:13:13 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/09 16:24:32 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = 0;
	if (dst >= src)
		ft_memcpy(dst, src, len);
	else
	{
		if (dst || src)
		{
			while (len--)
			{
				*((unsigned char*)dst + i) = *((unsigned char*)src + i);
				++i;
			}
		}
	}
	return (dst);
}
