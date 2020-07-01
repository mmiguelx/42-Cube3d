/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:59:30 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/23 03:32:50 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	set_values_and_ray_x(t_params *prm)
{
	prm->camera->ray_dir_x = prm->player->dir_x +
						prm->camera->plane_x * prm->camera->x;
	prm->camera->ray_dir_y = prm->player->dir_y +
						prm->camera->plane_y * prm->camera->x;
	prm->camera->map_x = (int)prm->player->pos_x;
	prm->camera->map_y = (int)prm->player->pos_y;
	prm->camera->delta_dist_x = fabs(1 / prm->camera->ray_dir_x);
	prm->camera->delta_dist_y = fabs(1 / prm->camera->ray_dir_y);
	prm->camera->hit = 0;
	if (prm->camera->ray_dir_x < 0)
	{
		prm->player->step_x = -1;
		prm->camera->side_dist_x = (prm->player->pos_x - prm->camera->map_x) *
													prm->camera->delta_dist_x;
	}
	else
	{
		prm->player->step_x = 1;
		prm->camera->side_dist_x = (prm->camera->map_x + 1.0 -
								prm->player->pos_x) * prm->camera->delta_dist_x;
	}
}

void	ray_y(t_params *prm)
{
	if (prm->camera->ray_dir_y < 0)
	{
		prm->player->step_y = -1;
		prm->camera->side_dist_y = (prm->player->pos_y - prm->camera->map_y) *
													prm->camera->delta_dist_y;
	}
	else
	{
		prm->player->step_y = 1;
		prm->camera->side_dist_y = (prm->camera->map_y + 1.0 -
								prm->player->pos_y) * prm->camera->delta_dist_y;
	}
}

void	camera_hit(t_params *prm)
{
	while (prm->camera->hit == 0)
	{
		if (prm->camera->side_dist_x < prm->camera->side_dist_y)
		{
			prm->camera->side_dist_x += prm->camera->delta_dist_x;
			prm->camera->map_x += prm->player->step_x;
			prm->player->side = 0;
		}
		else
		{
			prm->camera->side_dist_y += prm->camera->delta_dist_y;
			prm->camera->map_y += prm->player->step_y;
			prm->player->side = 1;
		}
		if (prm->world_map[prm->camera->map_x][prm->camera->map_y] == 1)
			prm->camera->hit = 1;
	}
}

void	get_wall_height(t_params *prm)
{
	if (prm->player->side == 0)
	{
		prm->camera->perp_wall_dist = (prm->camera->map_x - prm->player->pos_x +
					(1 - prm->player->step_x) / 2) / prm->camera->ray_dir_x;
	}
	else
	{
		prm->camera->perp_wall_dist = (prm->camera->map_y - prm->player->pos_y +
						(1 - prm->player->step_y) / 2) / prm->camera->ray_dir_y;
	}
	prm->draw->line_h = (int)(prm->draw->screen_height /
												prm->camera->perp_wall_dist);
	prm->draw->start = -prm->draw->line_h / 2 + prm->draw->screen_height / 2;
	if (prm->draw->start < 0)
		prm->draw->start = 0;
	prm->draw->end = prm->draw->line_h / 2 + prm->draw->screen_height / 2;
	if (prm->draw->end >= prm->draw->screen_height)
		prm->draw->end = prm->draw->screen_height - 1;
}

void	pick_texture(t_params *prm)
{
	double dx;
	double dy;

	dx = prm->camera->map_x - prm->player->pos_x;
	dy = prm->camera->map_y - prm->player->pos_y;
	if (prm->player->side == 1)
	{
		if (dy > 0)
			prm->draw->tex_num = WEST_TEXT;
		else
			prm->draw->tex_num = EAST_TEXT;
	}
	else
	{
		if (dx > 0)
			prm->draw->tex_num = NORTH_TEXT;
		else
			prm->draw->tex_num = SOUTH_TEXT;
	}
}
