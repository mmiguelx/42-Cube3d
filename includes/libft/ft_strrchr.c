/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:07:50 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/10 14:13:41 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	n = (ft_strlen(s) + 1);
	while (n--)
	{
		if (*(s + n) == (unsigned char)c)
			return ((char*)s + n);
	}
	return (NULL);
}
