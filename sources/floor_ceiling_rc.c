/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_rc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:45:43 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/23 03:26:52 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

static void	casting_calculations(t_params *prm, int *y)
{
	prm->camera->ray_dir_x0 = prm->player->dir_x - prm->camera->plane_x;
	prm->camera->ray_dir_y0 = prm->player->dir_y - prm->camera->plane_y;
	prm->camera->ray_dir_x1 = prm->player->dir_x + prm->camera->plane_x;
	prm->camera->ray_dir_y1 = prm->player->dir_y + prm->camera->plane_y;
	prm->camera->y = *y - prm->draw->screen_height / 2;
	prm->camera->pos_z = 0.5 * prm->draw->screen_height;
	prm->camera->row_distance = prm->camera->pos_z / prm->camera->y;
	prm->camera->floor_step_x = prm->camera->row_distance *
(prm->camera->ray_dir_x1 - prm->camera->ray_dir_x0) / prm->draw->screen_width;
	prm->camera->floor_step_y = prm->camera->row_distance *
(prm->camera->ray_dir_y1 - prm->camera->ray_dir_y0) / prm->draw->screen_width;
	prm->camera->floor_x = prm->player->pos_x + prm->camera->row_distance *
														prm->camera->ray_dir_x0;
	prm->camera->floor_y = prm->player->pos_y + prm->camera->row_distance *
														prm->camera->ray_dir_y0;
}

static void	set_data(t_params *prm, int x, int y)
{
	int color;
	int t_width;
	int t_height;

	t_width = TEXTURE_WIDTH;
	t_height = TEXTURE_HEIGHT;
	prm->camera->cell_x = (int)prm->camera->floor_x;
	prm->camera->cell_y = (int)prm->camera->floor_y;
	prm->draw->texture_x_floor = (int)(t_width * (prm->camera->floor_x -
									prm->camera->cell_x)) & (t_width - 1);
	prm->draw->texture_y_floor = (int)(t_height * (prm->camera->floor_y -
								prm->camera->cell_y)) & (t_height - 1);
	prm->camera->floor_x += prm->camera->floor_step_x;
	prm->camera->floor_y += prm->camera->floor_step_y;
	color = prm->draw->texture[FLOOR_TEXT][t_width * prm->draw->texture_y_floor
												+ prm->draw->texture_x_floor];
	*(prm->draw->view_data + (y * prm->draw->screen_width) + x) = color;
	color = prm->draw->texture[CEALING_TEXT][t_width *
					prm->draw->texture_y_floor + prm->draw->texture_x_floor];
	*(prm->draw->view_data + ((prm->draw->screen_height - y - 1) *
										prm->draw->screen_width) + x) = color;
}

void		floor_ceiling_casting(t_params *prm)
{
	int y;
	int x;

	y = prm->draw->screen_height / 2 + 1;
	while (y < prm->draw->screen_height)
	{
		casting_calculations(prm, &y);
		x = 0;
		while (x < prm->draw->screen_width)
		{
			set_data(prm, x, y);
			++x;
		}
		y++;
	}
}
