/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:55:17 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/23 19:44:22 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

int		key_pressed(int key, t_params *prm)
{
	if (key == 13)
		prm->keys->w = 1;
	if (key == 0)
		prm->keys->a = 1;
	if (key == 1)
		prm->keys->s = 1;
	if (key == 2)
		prm->keys->d = 1;
	if (key == 123)
		prm->keys->left = 1;
	if (key == 124)
		prm->keys->right = 1;
	if (key == 53)
		exit_game(prm);
	if (key == 3)
	{
		prm->draw->fc_textures = (prm->draw->fc_textures == 1 ? 0 : 1);
		draw_on_screen(prm);
	}
	return (0);
}

int		key_released(int key, t_params *prm)
{
	if (key == 13)
		prm->keys->w = 0;
	if (key == 0)
		prm->keys->a = 0;
	if (key == 1)
		prm->keys->s = 0;
	if (key == 2)
		prm->keys->d = 0;
	if (key == 123)
		prm->keys->left = 0;
	if (key == 124)
		prm->keys->right = 0;
	return (0);
}

void	move_up_down(t_params *prm, double speed)
{
	if (prm->keys->w == 1 || prm->keys->s == 1)
	{
		if (prm->keys->s == 1 && speed > 0)
			speed *= -1;
		if (prm->keys->w == 1 && speed < 0)
			speed *= -1;
		if (prm->world_map[(int)(prm->player->pos_x + prm->player->dir_x *
							speed)][(int)(prm->player->pos_y)] == 0)
			prm->player->pos_x += prm->player->dir_x * speed;
		if (prm->world_map[(int)(prm->player->pos_x)][(int)(prm->player->pos_y +
										prm->player->dir_y * speed)] == 0)
			prm->player->pos_y += prm->player->dir_y * speed;
	}
}

void	rotate_left_right(t_params *prm, double rot_speed)
{
	if (prm->keys->left == 1 || prm->keys->right == 1)
	{
		if (prm->keys->right == 1 && rot_speed > 0)
			rot_speed *= -1;
		if (prm->keys->left == 1 && rot_speed < 0)
			rot_speed *= -1;
		prm->player->old_dir_x = prm->player->dir_x;
		prm->player->dir_x = prm->player->dir_x * cos(rot_speed) -
											prm->player->dir_y * sin(rot_speed);
		prm->player->dir_y = prm->player->old_dir_x * sin(rot_speed) +
											prm->player->dir_y * cos(rot_speed);
		prm->camera->old_plane_x = prm->camera->plane_x;
		prm->camera->plane_x = prm->camera->plane_x * cos(rot_speed) -
										prm->camera->plane_y * sin(rot_speed);
		prm->camera->plane_y = prm->camera->old_plane_x * sin(rot_speed) +
										prm->camera->plane_y * cos(rot_speed);
	}
}

void	move_left_right(t_params *prm, double speed)
{
	if (prm->keys->a == 1 || prm->keys->d == 1)
	{
		if (prm->keys->a == 1 && speed > 0)
			speed *= -1;
		if (prm->keys->d == 1 && speed < 0)
			speed *= -1;
		if (prm->world_map[(int)(prm->player->pos_x + prm->camera->plane_x *
							speed)][(int)(prm->player->pos_y)] == 0)
			prm->player->pos_x += prm->camera->plane_x * speed;
		if (prm->world_map[(int)(prm->player->pos_x)][(int)(prm->player->pos_y +
										prm->camera->plane_y * speed)] == 0)
			prm->player->pos_y += prm->camera->plane_y * speed;
	}
}
