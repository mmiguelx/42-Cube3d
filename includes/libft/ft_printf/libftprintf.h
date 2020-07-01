/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 23:19:46 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/22 20:12:35 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>
# include "../libft.h"

typedef struct		s_case
{
	char			*flags;
	char			var_type;
	int				width;
	int				left_align;
	int				precision;
	int				hex_pref;
	int				plus_sign;
	int				plus_space;
	int				zero_filler;
	struct s_case	*next;
}					t_case;

int					print_0(char *s);
int					is_specifier(char a);
int					ft_printf(const char *s, ...);
int					ft_strlen_wchart(const wchar_t *s);
int					print_p(t_case *format, va_list args);
int					print_s(t_case *format, va_list args);
int					print_x(t_case *format, va_list args);
int					print_lx(t_case *format, va_list args);
int					print_hex(t_case *format, va_list args);
int					print_schar(t_case *format, va_list args);
int					check_to_print(t_case *aux, va_list args);
int					print_swchar(t_case *format, va_list args);
int					print_numbers(t_case *format, va_list args);
int					print_singlechar(t_case *format, va_list args);
int					print_int_preffix(t_case *format, va_list args);
int					print_lint_preffix(t_case *format, va_list args);
int					find_specifier(const char *s, int i, t_case *aux);
int					print_int(t_case *format, char *nbr, int len, int sign);
int					print_lint(t_case *format, char *nbr, int len, int sign);

t_case				*create_node(void);
t_case				*create_list(const char *s);
t_case				*get_wp(t_case *format, int len);
t_case				*check_flags(t_case *format, va_list args);
t_case				*building_list(const char *s, t_case *head);
t_case				*check_wp(t_case *format, char *aux, va_list args);

void				free_list(t_case **lst);
void				ft_putchar_wchart(wchar_t a);

char				*str_lower(char *s);

#endif
