/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:51:53 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/19 15:41:58 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *aux;

	if (!lst)
		return (NULL);
	head = NULL;
	head = ft_lstnew(f(lst->content));
	if (lst)
	{
		lst = lst->next;
		aux = head;
		while (lst)
		{
			if (!(aux->next = ft_lstnew(f(lst->content))))
				del(lst);
			lst = lst->next;
			aux = aux->next;
		}
	}
	return (head);
}
