/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tresde.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:09:29 by mpernia-          #+#    #+#             */
/*   Updated: 2020/01/22 21:03:27 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tresde.h"

int exit_game()
{
	exit(0);
}

//Creo cuadrado con un size pasado por parámetro
void set_square(mlx_t *tresde)
{
	int i;

	tresde->square.ptr = mlx_new_image(tresde->mlx_ptr, 250, 250); //Puntero de imagen
	tresde->square.colora = (int*)mlx_get_data_addr(tresde->square.ptr,
		&tresde->square.bpp, &tresde->square.size, &tresde->square.endian); //Array de imagen data
	tresde->square.x = 375;
	tresde->square.y = 375;
	tresde->square.size = 250;
	i = 0;
	tresde->square.bpp = 4;
	while(i < (pow(tresde->square.size, 2)))
	{
		*(tresde->square.colora + i++) = 0xFFFFFF;
	}
	mlx_put_image_to_window(tresde->mlx_ptr, tresde->win_ptr,
						tresde->square.ptr, tresde->square.x, tresde->square.y);
}

void new_square(mlx_t *tresde, int x, int y, int size_modifier)
{
	int i;

	i = 0;
	while(i < (pow(tresde->square.size, 2)))
		*(tresde->square.colora + i++) = 0x00000;
	mlx_put_image_to_window(tresde->mlx_ptr, tresde->win_ptr,
						tresde->square.ptr, tresde->square.x, tresde->square.y);
	if (size_modifier != 0)
	{
		tresde->square.size += size_modifier;
		tresde->square.ptr = mlx_new_image(tresde->mlx_ptr, tresde->square.size,
									tresde->square.size); //Puntero de imagen
		tresde->square.colora = (int*)mlx_get_data_addr(tresde->square.ptr,
			&i, &i, &tresde->square.endian);
	}
	i = 0;
	while(i < (pow(tresde->square.size, 2)))
		*(tresde->square.colora + i++) = 0xFFFFFF;
	tresde->square.x += x;
	tresde->square.y += y;
	mlx_put_image_to_window(tresde->mlx_ptr, tresde->win_ptr,
				tresde->square.ptr, tresde->square.x, tresde->square.y);
}

int key_pressed(int key, mlx_t *tresde) // Trigger key press
{
	if (key == 126) // up
		tresde->keys.up = 1;
	if (key == 125) // down
		tresde->keys.down = 1;
	if (key == 123) // left
		tresde->keys.left = 1;
	if (key == 124) // right
		tresde->keys.right = 1;
	if (key == 69) // +
		tresde->keys.plus = 1;
	if (key == 78) // -
		tresde->keys.minus = 1;
	return(0);
}

int key_release(int key, mlx_t *tresde) // Trigger key release
{
	if (key == 126) // up
		tresde->keys.up = 0;
	if (key == 125) // down
		tresde->keys.down = 0;
	if (key == 123) // left
		tresde->keys.left = 0;
	if (key == 124) // right
		tresde->keys.right = 0;
	if (key == 69) // +
		tresde->keys.plus = 0;
	if (key == 78) // -
		tresde->keys.minus = 0;
	return(0);
}

int test_key(mlx_t *tresde)
{
	if (tresde->keys.up) // up
		new_square(&*tresde, 0, -3, 0);
	if (tresde->keys.down) // down
		new_square(&*tresde, 0, +3, 0);
	if (tresde->keys.left) // left
		new_square(&*tresde, -3, 0, 0);
	if (tresde->keys.right) // right
		new_square(&*tresde, +3, 0, 0);
	if (tresde->keys.plus) // +
		new_square(&*tresde, -3, -3, 6);
	if (tresde->keys.minus) // -
		new_square(&*tresde, 3, 3, -6);
	return(0);
}

void print_key(int key)
{
	printf("%d\n", key);
}

/*
Key Numbers
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
*/
