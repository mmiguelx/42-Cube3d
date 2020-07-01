/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:46:02 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/20 16:20:50 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	prefix;
	size_t	suffix;
	size_t	s1_size;
	char	*aux;

	if (!s1 || !set)
		return (0);
	prefix = 0;
	suffix = 0;
	s1_size = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + prefix)) && *(s1 + prefix))
		++prefix;
	if (prefix >= s1_size)
		return (ft_strdup(""));
	while (ft_strchr(set, *(s1 + s1_size - suffix - 1)))
		++suffix;
	s1_size = s1_size - prefix - suffix;
	if (!(aux = ft_calloc(sizeof(char), s1_size + 1)))
		return (NULL);
	ft_memcpy(aux, s1 + prefix, s1_size);
	return (aux);
}
