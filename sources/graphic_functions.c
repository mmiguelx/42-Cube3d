/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:02:26 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/04 05:54:39 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	load_extra_textures(t_params *prm)
{
	int h;
	int w;

	prm->draw->texture_ptr = mlx_xpm_file_to_image(prm->mlx_ptr,
												"images/tile025.xpm", &h, &w);
	prm->draw->texture[FLOOR_TEXT] = (int*)mlx_get_data_addr
(prm->draw->texture_ptr, &prm->draw->bbp, &prm->draw->sl, &prm->draw->endian);
	prm->draw->texture_ptr = mlx_xpm_file_to_image(prm->mlx_ptr,
												"images/tile182.xpm", &h, &w);
	prm->draw->texture[CEALING_TEXT] = (int*)mlx_get_data_addr
(prm->draw->texture_ptr, &prm->draw->bbp, &prm->draw->sl, &prm->draw->endian);
}

int		get_color(int red, int green, int blue)
{
	return ((red * 256 * 256) + (green * 256) + blue);
}

void	draw_on_screen(t_params *prm)
{
	if (prm->draw->fc_textures == 1)
		floor_ceiling_casting(prm);
	wall_casting(prm);
	sprites_casting(prm);
	if (prm->save_bmp == 0)
	{
		mlx_put_image_to_window(prm->mlx_ptr, prm->win_ptr,
													prm->draw->view_ptr, 0, 0);
	}
	else
		create_bmp(prm);
}

int		move_and_draw(t_params *prm)
{
	double speed;
	double rot_speed;

	speed = 0.25;
	rot_speed = speed / 3;
	move_up_down(prm, speed);
	move_left_right(prm, speed);
	rotate_left_right(prm, rot_speed);
	if (prm->keys->a || prm->keys->s || prm->keys->d || prm->keys->w ||
											prm->keys->left || prm->keys->right)
		draw_on_screen(prm);
	return (0);
}
