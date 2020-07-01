/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:53:42 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/23 19:59:59 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"

int		main(int argc, char **argv)
{
	t_params	prm;

	prm.mlx_ptr = mlx_init();
	argument_checker(argc, argv, &prm);
	player_init(&prm);
	prm.win_ptr = mlx_new_window(prm.mlx_ptr, prm.draw->screen_width,
											prm.draw->screen_height, "Cube3D");
	prm.draw->view_ptr = mlx_new_image(prm.mlx_ptr, prm.draw->screen_width,
													prm.draw->screen_height);
	prm.draw->view_data = (int*)mlx_get_data_addr(prm.draw->view_ptr,
							&prm.draw->bbp, &prm.draw->sl, &prm.draw->endian);
	draw_on_screen(&prm);
	mlx_do_key_autorepeatoff(prm.mlx_ptr);
	mlx_hook(prm.win_ptr, 2, 1, key_pressed, &prm);
	mlx_hook(prm.win_ptr, 3, 1, key_released, &prm);
	mlx_loop_hook(prm.mlx_ptr, move_and_draw, &prm);
	mlx_hook(prm.win_ptr, 17, 1, exit_game, &prm);
	mlx_loop(prm.mlx_ptr);
}

/*
**Tasks:
**--save
**bonus?
*/
