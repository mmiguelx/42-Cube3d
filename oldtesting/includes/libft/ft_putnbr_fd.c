/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:08:30 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/16 21:53:11 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long aux;

	aux = n;
	if (aux < 0)
	{
		ft_putchar_fd('-', fd);
		aux = aux * (-1);
	}
	if (aux >= 10)
		ft_putnbr_fd(aux / 10, fd);
	ft_putchar_fd(aux % 10 + '0', fd);
}
