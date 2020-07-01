/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 05:01:51 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/22 19:11:32 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_numbers(t_case *format, va_list args)
{
	format = check_flags(format, args);
	return ((ft_strchr(format->flags, 'l') ? print_lint_preffix(format, args) :
											print_int_preffix(format, args)));
}

int		print_lint_preffix(t_case *format, va_list args)
{
	char		*nbr;
	int			len;
	int			sign;
	int			i;

	format = check_flags(format, args);
	nbr = (format->var_type == 'u' ? ft_ltoa(va_arg(args, long unsigned int)) :
										ft_ltoa(va_arg(args, long int)));
	sign = 0;
	if (*nbr == '0' && format->precision == 0 && ft_strchr(format->flags, '.'))
		nbr = ft_strdup("");
	if (ft_strchr(nbr, '-'))
		sign = 1;
	len = ft_strlen(nbr) - sign;
	sign = (format->plus_sign == 1 || format->plus_space == 1) ? 1 :
																sign;
	format = get_wp(format, len);
	i = 0;
	if (format->left_align == 0 && format->zero_filler == 0)
		i += ft_putcharntimes(' ', format->width - format->precision - sign);
	free(nbr);
	return (i + sign + print_lint(format, nbr, len, sign));
}

int		print_lint(t_case *format, char *nbr, int len, int sign)
{
	int i;

	if (ft_strchr(nbr, '-'))
	{
		ft_putchar('-');
		++nbr;
	}
	else if (format->plus_sign == 1 || format->plus_space == 1)
		(format->plus_sign == 1) ? ft_putchar('+') : ft_putchar(' ');
	i = 0;
	if (ft_strchr(format->flags, '.'))
		i += ft_putcharntimes('0', format->precision - len);
	else if (format->zero_filler == 1)
		i += ft_putcharntimes('0', format->width - len - sign);
	if (nbr)
		i += ft_putstr(nbr);
	if (format->left_align == 1)
		i += ft_putcharntimes(' ', format->width - format->precision - sign);
	return (i);
}

int		print_int_preffix(t_case *format, va_list args)
{
	char		*nbr;
	int			len;
	int			sign;
	int			i;

	format = check_flags(format, args);
	nbr = (format->var_type == 'u' ? ft_ltoa(va_arg(args, unsigned int)) :
										ft_itoa(va_arg(args, int)));
	sign = 0;
	if (*nbr == '0' && format->precision == 0 && ft_strchr(format->flags, '.'))
		nbr = ft_strdup("");
	if (ft_strchr(nbr, '-'))
		sign = 1;
	len = ft_strlen(nbr) - sign;
	sign = (format->plus_sign == 1 || format->plus_space == 1) ? 1 :
																sign;
	format = get_wp(format, len);
	i = 0;
	if (format->left_align == 0 && format->zero_filler == 0)
		i += ft_putcharntimes(' ', format->width - format->precision - sign);
	free(nbr);
	return (i + sign + print_int(format, nbr, len, sign));
}

int		print_int(t_case *format, char *nbr, int len, int sign)
{
	int i;

	if (ft_strchr(nbr, '-'))
	{
		ft_putchar('-');
		++nbr;
	}
	else if (format->plus_sign == 1 || format->plus_space == 1)
		(format->plus_sign == 1) ? ft_putchar('+') : ft_putchar(' ');
	i = 0;
	if (ft_strchr(format->flags, '.'))
		i += ft_putcharntimes('0', format->precision - len);
	else if (format->zero_filler == 1)
		i += ft_putcharntimes('0', format->width - len - sign);
	if (nbr)
		i += ft_putstr(nbr);
	if (format->left_align == 1)
		i += ft_putcharntimes(' ', format->width - format->precision - sign);
	return (i);
}
