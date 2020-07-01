/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:32:26 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/23 03:40:21 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

static void	draw_sprite(t_params *prm, int stripe)
{
	int y;
	int d;
	int color;

	prm->sprites->texture_x = (int)(256 * (stripe - (-prm->sprites->width / 2 +
		prm->sprites->screen_x)) * TEXTURE_WIDTH / prm->sprites->width) / 256;
	if (prm->sprites->transform_y > 0 && stripe > 0 && stripe <
						prm->draw->screen_width && prm->sprites->transform_y <
												prm->camera->z_buffer[stripe])
	{
		y = prm->sprites->draw_start_y;
		while (y < prm->sprites->draw_end_y)
		{
			d = (y - prm->sprites->v_move_screen) * 256 -
					prm->draw->screen_height * 128 + prm->sprites->height * 128;
			prm->sprites->texture_y = ((d * TEXTURE_HEIGHT) /
													prm->sprites->height) / 256;
			color = prm->draw->texture[SPRITE_TEXT][TEXTURE_WIDTH *
							prm->sprites->texture_y + prm->sprites->texture_x];
			if (color != prm->draw->texture[SPRITE_TEXT][0])
				*(prm->draw->view_data + (y * prm->draw->screen_width) +
																stripe) = color;
			++y;
		}
	}
}

void		sprites_casting(t_params *prm)
{
	int i;
	int k;
	int stripe;

	calculate_distances(prm);
	i = -1;
	while (++i < prm->sprites->num)
	{
		k = get_index(prm);
		prm->sprites->pos_x = prm->sprites->x[k] - prm->player->pos_x;
		prm->sprites->pos_y = prm->sprites->y[k] - prm->player->pos_y;
		prm->sprites->inv_det = 1.0 / (prm->camera->plane_x * prm->player->dir_y
								- prm->player->dir_x * prm->camera->plane_y);
		prm->sprites->transform_x = prm->sprites->inv_det * (prm->player->dir_y
			* prm->sprites->pos_x - prm->player->dir_x * prm->sprites->pos_y);
		prm->sprites->transform_y = prm->sprites->inv_det *
		(-prm->camera->plane_y * prm->sprites->pos_x + prm->camera->plane_x *
														prm->sprites->pos_y);
		set_start_end(prm);
		stripe = prm->sprites->draw_start_x - 1;
		while (++stripe < prm->sprites->draw_end_x)
			draw_sprite(prm, stripe);
	}
}
