/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:56:38 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/04 00:44:33 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

static void	get_x_y(t_params *prm)
{
	int y;
	int x;
	int i;

	x = 0;
	i = 0;
	while (x < prm->map_height)
	{
		y = 0;
		while (y < prm->map_width)
		{
			if (prm->world_map[x][y] == 2)
			{
				prm->sprites->x[i] = x + 0.6;
				prm->sprites->y[i] = y + 0.6;
				i++;
			}
			++y;
		}
		++x;
	}
}

int			sprites_init(t_params *prm)
{
	if (!(prm->sprites->used = (int*)malloc(sizeof(int) * prm->sprites->num)))
		return (0);
	if (!(prm->sprites->distance = (double*)malloc(sizeof(double) *
															prm->sprites->num)))
		return (0);
	if (!(prm->sprites->x = (double*)malloc(sizeof(double) *
															prm->sprites->num)))
		return (0);
	if (!(prm->sprites->y = (double*)malloc(sizeof(double) *
															prm->sprites->num)))
		return (0);
	if (!(prm->camera->z_buffer = (double*)malloc(sizeof(double) *
													prm->draw->screen_width)))
		return (0);
	get_x_y(prm);
	return (1);
}

void		calculate_distances(t_params *prm)
{
	int i;

	i = 0;
	while (i < prm->sprites->num)
	{
		prm->sprites->distance[i] = ((prm->player->pos_x - prm->sprites->x[i]) *
			(prm->player->pos_x - prm->sprites->x[i]) + (prm->player->pos_y -
			prm->sprites->y[i]) * (prm->player->pos_y - prm->sprites->y[i]));
		++i;
	}
	i = 0;
	while (i < prm->sprites->num)
	{
		prm->sprites->used[i] = 0;
		++i;
	}
}

void		set_start_end(t_params *prm)
{
	prm->sprites->screen_x = (int)((prm->draw->screen_width / 2) * (1 +
						prm->sprites->transform_x / prm->sprites->transform_y));
	prm->sprites->v_move_screen = (int)((prm->draw->screen_height / 4) /
													prm->sprites->transform_y);
	prm->sprites->height = abs((int)(prm->draw->screen_height /
											prm->sprites->transform_y)) / VDIV;
	prm->sprites->draw_start_y = -prm->sprites->height / 2 +
					prm->draw->screen_height / 2 + prm->sprites->v_move_screen;
	prm->sprites->draw_start_y = prm->sprites->draw_start_y < 0 ? 0 :
													prm->sprites->draw_start_y;
	prm->sprites->draw_end_y = prm->sprites->height / 2 +
					prm->draw->screen_height / 2 + prm->sprites->v_move_screen;
	prm->sprites->draw_end_y = (prm->sprites->draw_end_y >=
					prm->draw->screen_height) ? prm->draw->screen_height - 1 :
													prm->sprites->draw_end_y;
	prm->sprites->width = abs((int)(prm->draw->screen_height /
											prm->sprites->transform_y)) / UDIV;
	prm->sprites->draw_start_x = -prm->sprites->width / 2 +
														prm->sprites->screen_x;
	prm->sprites->draw_start_x = (prm->sprites->draw_start_x < 0 ? 0 :
													prm->sprites->draw_start_x);
	prm->sprites->draw_end_x = prm->sprites->width / 2 + prm->sprites->screen_x;
	prm->sprites->draw_end_x = (prm->sprites->draw_end_x >=
						prm->draw->screen_width ? prm->draw->screen_width - 1 :
													prm->sprites->draw_end_x);
}

int			get_index(t_params *prm)
{
	int active_index;
	int i;

	i = 0;
	active_index = 0;
	while (i < prm->sprites->num)
	{
		if (prm->sprites->used[i] == 0)
			break ;
		++i;
	}
	active_index = i;
	i = 0;
	while (i < prm->sprites->num)
	{
		if (prm->sprites->distance[active_index] < prm->sprites->distance[i] &&
													prm->sprites->used[i] == 0)
			active_index = i;
		++i;
	}
	prm->sprites->used[active_index] = 1;
	return (active_index);
}
