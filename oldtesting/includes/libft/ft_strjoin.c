/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:43:22 by mpernia-          #+#    #+#             */
/*   Updated: 2019/12/31 05:45:17 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	s1_size;
	char	*aux;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1);
	size = s1_size + ft_strlen(s2);
	aux = ft_calloc(sizeof(char), size + 1);
	if (!aux)
		return (NULL);
	ft_memcpy(aux, s1, s1_size);
	ft_strlcat(aux, s2, size + 1);
	free((char*)s2);
	return (aux);
}
