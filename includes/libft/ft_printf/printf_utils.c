/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:35:53 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/22 19:11:42 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_specifier(char a)
{
	return (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i' ||
			a == 'u' || a == 'x' || a == 'X' || a == '%');
}

int		check_to_print(t_case *aux, va_list args)
{
	if (aux->var_type == 'c' || aux->var_type == '%')
		return (print_singlechar(aux, args));
	else if (aux->var_type == 's')
		return (print_s(aux, args));
	else if (aux->var_type == 'd' || aux->var_type == 'i' ||
				aux->var_type == 'u')
		return (print_int_preffix(aux, args));
	else if (aux->var_type == 'x' || aux->var_type == 'X')
		return (print_x(aux, args));
	else if (aux->var_type == 'p')
		return (print_p(aux, args));
	else
		return (print_0(aux->flags));
}

t_case	*check_wp(t_case *format, char *aux, va_list args)
{
	format->width = (*aux == '*') ? va_arg(args, int) : ft_atoi(aux);
	if (format->width < 0)
	{
		format->width *= -1;
		format->left_align = 1;
		format->zero_filler = 0;
	}
	if ((aux = ft_strchr(format->flags, '.')))
	{
		++aux;
		format->precision = (*aux == '*') ? va_arg(args, int) : ft_atoi(aux);
		format->zero_filler = 0;
	}
	return (format);
}

t_case	*check_flags(t_case *format, va_list args)
{
	int i;

	i = -1;
	while (*(format->flags + ++i))
	{
		if (*(format->flags + i) == '-')
			format->left_align = 1;
		if (*(format->flags + i) == '#')
			format->hex_pref = 1;
		if (*(format->flags + i) == '+')
			format->plus_sign = 1;
		if (*(format->flags + i) == ' ')
			format->plus_space = 1;
		if (*(format->flags + i) == '0')
			format->zero_filler = 1;
		if ((ft_isdigit(*(format->flags + i)) && *(format->flags + i) != '0')
		|| (*(format->flags + i) == '*') || (*(format->flags + i) == '.'))
		{
			check_wp(format, format->flags + i, args);
			break ;
		}
	}
	return (format);
}

t_case	*get_wp(t_case *format, int len)
{
	format->precision = (ft_strchr(format->flags, '.') == 0 ? len :
															format->precision);
	if (format->var_type == 's' && format->precision >= 0)
		format->precision = (format->precision < len) ? format->precision : len;
	else
		format->precision = (format->precision > len) ? format->precision : len;
	format->width = (format->width > format->precision) ? format->width :
															format->precision;
	return (format);
}
