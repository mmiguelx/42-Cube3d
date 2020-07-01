/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:56:25 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/12 15:58:59 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*aux;

	aux = malloc(ft_strlen(s1) + 1);
	if (!aux)
		return (NULL);
	return (ft_memcpy(aux, s1, ft_strlen(s1) + 1));
}
