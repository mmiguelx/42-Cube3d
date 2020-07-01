/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tresde.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:07:55 by mpernia-          #+#    #+#             */
/*   Updated: 2020/01/22 19:00:48 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRESDE_H
# define TRESDE_H

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "includes/libft/libft.h"

typedef struct square_s
{
	int		x;
	int		y;
	int		size;
	int		bpp;
	int		endian;
	int		*colora;
	void	*ptr;
}				square_t;

typedef struct key_s
{
	int up;
	int down;
	int left;
	int right;
	int plus;
	int minus;
}				key_t;

typedef struct mlx_s
{
	square_t	square;
	key_t		keys;
	void*		mlx_ptr;
	void*		win_ptr;
}				mlx_t;

int exit_game();
int test_key(mlx_t *tresde);
int key_release(int key, mlx_t *tresde);
int key_pressed(int key, mlx_t *tresde);

void print_key(int key);
void set_square(mlx_t *tresde);
void new_square(mlx_t *tresde, int x, int y, int size_modifier);

#endif
