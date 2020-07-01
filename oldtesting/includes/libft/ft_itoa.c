/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:13:13 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/16 19:56:43 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int int_size;

	int_size = 0;
	if (n <= 0)
		++int_size;
	while (n)
	{
		n = n / 10;
		++int_size;
	}
	return (int_size);
}

char		*ft_itoa(int n)
{
	long	nb;
	char	*number;
	int		int_size;

	nb = n;
	int_size = get_size(n);
	if (!(number = ft_calloc(int_size + 1, sizeof(char))))
		return (NULL);
	if (nb == 0)
		*(number) = '0';
	if (nb < 0)
	{
		*(number) = '-';
		nb = nb * (-1);
	}
	while (int_size && nb > 0)
	{
		--int_size;
		*(number + int_size) = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (number);
}
