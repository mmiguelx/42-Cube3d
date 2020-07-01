/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:51:57 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/16 17:12:42 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*aux;
	int		i;

	if (!s || !f || !(aux = ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(aux + i) = f(i, *(s + i));
		++i;
	}
	return (aux);
}
