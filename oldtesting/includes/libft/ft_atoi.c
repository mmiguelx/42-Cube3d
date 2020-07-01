/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:42:24 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/18 18:21:41 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	number;
	int				i;
	int				is_negative;

	i = 0;
	is_negative = 1;
	number = 0;
	while (ft_isspace(*(str + i)) || (*(str + i) == '+' &&
				ft_isdigit(*(str + i + 1))))
		i++;
	if (*(str + i++) == '-')
		is_negative = -1;
	else
		--i;
	while (ft_isdigit(*(str + i)))
	{
		if (!number)
			number = *(str + i) - '0';
		else
			number = (number * 10) + (*(str + i) - '0');
		++i;
	}
	if (number < MAXLONG)
		return (number * is_negative);
	return (is_negative == 1 ? -1 : 0);
}
