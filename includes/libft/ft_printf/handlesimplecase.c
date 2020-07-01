/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlesimplecase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 23:17:37 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/22 19:11:35 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_singlechar(t_case *format, va_list args)
{
	format = check_flags(format, args);
	format->width = (format->width > 0 ? format->width : 1);
	if (format->width > 1 && format->left_align == 0)
		(format->zero_filler == 0 ? ft_putcharntimes(' ', format->width - 1) :
									ft_putcharntimes('0', format->width - 1));
	if (!ft_strchr(format->flags, 'l'))
		(format->var_type == 'c' ? ft_putchar(va_arg(args, int)) :
									ft_putchar('%'));
	else
		ft_putchar_wchart(va_arg(args, wint_t));
	if (format->width > 1 && format->left_align == 1)
		ft_putcharntimes(' ', format->width - 1);
	return (format->width);
}

int		print_0(char *s)
{
	ft_putstr(s);
	return (ft_strlen(s));
}

int		print_s(t_case *format, va_list args)
{
	format = check_flags(format, args);
	return ((ft_strchr(format->flags, 'l') ? print_swchar(format, args) :
												print_schar(format, args)));
}

int		print_schar(t_case *format, va_list args)
{
	char	*aux;
	int		len;
	int		i;

	aux = va_arg(args, char*);
	if (aux == NULL)
		aux = ft_strdup("(null)");
	len = (int)ft_strlen(aux);
	format = get_wp(format, len);
	if (format->left_align == 0 && format->width > format->precision)
		ft_putcharntimes(' ', format->width - format->precision);
	i = 0;
	write(1, aux, format->precision);
	if (format->left_align == 1 && format->width > format->precision)
		ft_putcharntimes(' ', format->width - format->precision);
	return (format->width);
}

int		print_swchar(t_case *format, va_list args)
{
	wchar_t *aux;
	int		len;
	int		i;

	aux = va_arg(args, wchar_t*);
	if (aux == NULL)
		aux = (wchar_t*)ft_strdup("(null)");
	len = ft_strlen_wchart(aux);
	format = get_wp(format, len);
	if (format->left_align == 0 && format->width > format->precision)
		ft_putcharntimes(' ', format->width - format->precision);
	i = 0;
	write(1, aux, format->precision);
	if (format->left_align == 1 && format->width > format->precision)
		ft_putcharntimes(' ', format->width - format->precision);
	return (format->width);
}
