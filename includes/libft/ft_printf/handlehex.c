/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:35:55 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/22 19:11:27 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_hex(t_case *format, va_list args)
{
	format = check_flags(format, args);
	return ((ft_strchr(format->flags, 'l') ? print_lx(format, args) :
											print_x(format, args)));
}

int		print_x(t_case *format, va_list args)
{
	char	*hex;
	int		i;
	int		len;

	format = check_flags(format, args);
	hex = ft_dechex(va_arg(args, unsigned int));
	if (format->hex_pref == 1 && *hex != '0')
		hex = ft_strjoin("0X", hex);
	hex = (format->var_type == 'x' ? str_lower(hex) : hex);
	if (*hex == '0' && format->precision == 0 && ft_strchr(format->flags, '.'))
		hex = ft_strdup("");
	len = ft_strlen(hex);
	format = get_wp(format, len);
	i = 0;
	if (format->left_align == 0 && format->zero_filler == 0)
		i += ft_putcharntimes(' ', format->width - format->precision);
	if (ft_strchr(format->flags, '.'))
		i += ft_putcharntimes('0', format->precision - len);
	else if (format->zero_filler == 1)
		i += ft_putcharntimes('0', format->width - len);
	i = (hex != 0 ? i + ft_putstr(hex) : i);
	free(hex);
	if (format->left_align == 1)
		i += ft_putcharntimes(' ', format->width - format->precision);
	return (i);
}

int		print_lx(t_case *format, va_list args)
{
	char	*hex;
	int		i;
	int		len;

	format = check_flags(format, args);
	hex = ft_dechex(va_arg(args, unsigned long int));
	if (format->hex_pref == 1)
		hex = ft_strjoin("0X", hex);
	hex = (format->var_type == 'x' ? str_lower(hex) : hex);
	if (*hex == '0' && format->precision == 0 && ft_strchr(format->flags, '.'))
		hex = ft_strdup("");
	len = ft_strlen(hex);
	format = get_wp(format, len);
	i = 0;
	if (format->left_align == 0 && format->zero_filler == 0)
		i += ft_putcharntimes(' ', format->width - format->precision);
	if (ft_strchr(format->flags, '.'))
		i += ft_putcharntimes('0', format->precision - len);
	else if (format->zero_filler == 1)
		i += ft_putcharntimes('0', format->width - len);
	i = (hex != 0 ? i + ft_putstr(hex) : i);
	free(hex);
	if (format->left_align == 1)
		i += ft_putcharntimes(' ', format->width - format->precision);
	return (i);
}

int		print_p(t_case *format, va_list args)
{
	char	*p;
	int		i;
	int		len;

	format = check_flags(format, args);
	p = str_lower(ft_strjoin("0x", ft_dechex(va_arg(args, unsigned long int))));
	if (*(p + 2) == '0' && ft_strchr(format->flags, '.'))
		p = ft_strdup("0x");
	len = ft_strlen(p);
	i = 0;
	if (format->left_align == 0)
		i += ft_putcharntimes(' ', format->width - len);
	if (p)
		i += ft_putstr(p);
	if (format->left_align == 1)
		i += ft_putcharntimes(' ', format->width - len);
	free(p);
	return (i);
}
