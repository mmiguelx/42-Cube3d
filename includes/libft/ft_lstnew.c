/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:02:57 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/17 20:25:29 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *aux;

	if (!(aux = (t_list*)malloc(sizeof(*aux))))
		return (NULL);
	aux->content = content;
	aux->next = NULL;
	return (aux);
}
