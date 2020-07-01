/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:00:46 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/04 00:45:16 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

static void	set_wall_texture(t_params *prm)
{
	pick_texture(prm);
	if (prm->player->side == 0)
	{
		prm->camera->wall_x = prm->player->pos_y + prm->camera->perp_wall_dist *
														prm->camera->ray_dir_y;
	}
	else
	{
		prm->camera->wall_x = prm->player->pos_x + prm->camera->perp_wall_dist *
														prm->camera->ray_dir_x;
	}
	prm->camera->wall_x -= floor((prm->camera->wall_x));
	prm->draw->texture_x = (int)(prm->camera->wall_x * (double)TEXTURE_WIDTH);
	if (prm->player->side == 0 && prm->camera->ray_dir_x > 0)
		prm->draw->texture_x = TEXTURE_WIDTH - prm->draw->texture_x - 1;
	if (prm->player->side == 1 && prm->camera->ray_dir_y < 0)
		prm->draw->texture_x = TEXTURE_WIDTH - prm->draw->texture_x - 1;
	prm->player->step = 1.0 * TEXTURE_HEIGHT / prm->draw->line_h;
	prm->draw->tex_pos = (prm->draw->start - prm->draw->screen_height / 2 +
									prm->draw->line_h / 2) * prm->player->step;
}

static void	set_wall(int x, t_params *prm)
{
	int count;
	int color;

	count = -1;
	while (++count < prm->draw->start)
	{
		if (prm->draw->fc_textures == 0)
			*(prm->draw->view_data + (count * prm->draw->screen_width) + x) =
					get_color(prm->draw->cealing_red, prm->draw->cealing_green,
													prm->draw->cealing_blue);
	}
	while (count <= prm->draw->end)
	{
		prm->draw->texture_y = (int)prm->draw->tex_pos & (TEXTURE_HEIGHT - 1);
		prm->draw->tex_pos += prm->player->step;
		color = prm->draw->texture[prm->draw->tex_num][TEXTURE_HEIGHT *
								prm->draw->texture_y + prm->draw->texture_x];
		*(prm->draw->view_data + (count * prm->draw->screen_width) + x) = color;
		count++;
	}
	while (count++ < prm->draw->screen_height && prm->draw->fc_textures == 0)
		*(prm->draw->view_data + (count * prm->draw->screen_width) + x) =
					get_color(prm->draw->floor_red, prm->draw->floor_green,
													prm->draw->floor_blue);
}

void		wall_casting(t_params *prm)
{
	int x;

	x = 0;
	while (x < prm->draw->screen_width)
	{
		prm->camera->x = 2 * x / (double)prm->draw->screen_width - 1;
		set_values_and_ray_x(prm);
		ray_y(prm);
		camera_hit(prm);
		get_wall_height(prm);
		set_wall_texture(prm);
		set_wall(x, prm);
		prm->camera->z_buffer[x] = prm->camera->perp_wall_dist;
		x++;
	}
}
