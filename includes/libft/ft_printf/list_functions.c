/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:56:51 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/22 19:11:39 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		find_specifier(const char *s, int i, t_case *aux)
{
	int		j;

	j = 0;
	while (*(s + i + j) && is_specifier(*(s + i + j)) == 0)
		++j;
	if (is_specifier(*(s + i + j)) == 1)
	{
		aux->var_type = *(s + i + j);
		return (j + 1);
	}
	return (0);
}

t_case	*create_node(void)
{
	t_case *aux;

	if (!(aux = (t_case*)malloc(sizeof(*aux))))
		return (NULL);
	aux->next = NULL;
	aux->flags = NULL;
	aux->var_type = 0;
	aux->width = 0;
	aux->left_align = 0;
	aux->precision = 0;
	aux->hex_pref = 0;
	aux->plus_sign = 0;
	aux->plus_space = 0;
	aux->zero_filler = 0;
	return (aux);
}

t_case	*building_list(const char *s, t_case *head)
{
	t_case	*aux;
	int		i;
	int		j;

	i = 0;
	aux = head;
	while (*(s + i))
	{
		j = 0;
		if (*(s + i) && *(s + i) == '%')
			j = find_specifier(s, ++i, aux);
		else
		{
			while (*(s + i + j) && *(s + i + j) != '%')
				++j;
		}
		aux->flags = ft_substr(s, i, j);
		i += j;
		if (*(s + i))
		{
			aux->next = create_node();
			aux = aux->next;
		}
	}
	return (head);
}

t_case	*create_list(const char *s)
{
	t_case	*head;

	if (*s)
	{
		head = create_node();
		return (building_list(s, head));
	}
	return (0);
}

void	free_list(t_case **lst)
{
	t_case *next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->flags);
		free(*lst);
		*lst = NULL;
		*lst = next;
	}
}
