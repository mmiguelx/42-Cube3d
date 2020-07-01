/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:30:47 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/11 19:26:27 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;
	size_t	haystack_size;
	size_t	i;

	needle_size = ft_strlen(needle);
	if (!needle_size)
		return ((char*)haystack);
	i = 0;
	haystack_size = ft_strlen(haystack);
	while (len-- >= needle_size && (haystack_size - i) >= needle_size)
	{
		if (*(haystack + i) == *needle &&
				!ft_memcmp(haystack + i, needle, needle_size))
			return ((char*)haystack + i);
		++i;
	}
	return (NULL);
}
