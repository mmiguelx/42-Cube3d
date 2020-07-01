/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubeutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:08:59 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/05 02:29:00 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

static void	init_prm(t_params *prm)
{
	if (!(prm->camera = ft_calloc(1, sizeof(t_camera))))
		error_handler(MALLOC_ERR);
	if (!(prm->player = ft_calloc(1, sizeof(t_player))))
		error_handler(MALLOC_ERR);
	if (!(prm->draw = ft_calloc(1, sizeof(t_draw))))
		error_handler(MALLOC_ERR);
	if (!(prm->keys = ft_calloc(1, sizeof(t_keys))))
		error_handler(MALLOC_ERR);
	if (!(prm->sprites = ft_calloc(1, sizeof(t_sprites))))
		error_handler(MALLOC_ERR);
	prm->save_bmp = 0;
	prm->draw->cealing_red = -1;
	prm->draw->cealing_green = -1;
	prm->draw->cealing_blue = -1;
	prm->draw->floor_red = -1;
	prm->draw->floor_green = -1;
	prm->draw->floor_blue = -1;
	prm->map_str = ft_strdup("");
	prm->map_height = 0;
}

int			exit_game(t_params *prm)
{
	free(prm->draw);
	free(prm->keys);
	free(prm->camera->z_buffer);
	free(prm->camera);
	free(prm->player);
	free(prm->sprites->used);
	free(prm->sprites->distance);
	free(prm->sprites->x);
	free(prm->sprites->y);
	free(prm->sprites);
	free(prm->world_map);
	prm = 0;
	exit(0);
}

void		error_handler(int i)
{
	if (i == MALLOC_ERR)
		ft_printf("ERROR:\n\nMemory could not be allocated.\n");
	if (i == TOO_FEW_ARG_ERR)
		ft_printf("ERROR:\n\nToo few arguments.\n");
	if (i == TOO_MANY_ARG_ERR)
		ft_printf("ERROR:\n\nToo many arguments.\n");
	if (i == BAD_ARG_ERR)
		ft_printf("ERROR:\n\nBad argument.\n");
	if (i == CREATE_ERR)
		ft_printf("ERROR:\n\nCould not create the bmp file.\n");
	if (i == INVALID_FILE_ERR)
		ft_printf("ERROR:\n\nCould not read the cub file.\n");
	if (i == RESOLUTION_DUP_ERR)
		ft_printf("ERROR:\n\nResolution values were set too many times.");
	if (i == TEXTURE_ERR)
		ft_printf("ERROR:\n\nThe textures could not be loaded correctly.");
	if (i == COLOR_FC_ERR)
		ft_printf("ERROR:\n\nIncorrect format RGB in cealing or floor.");
	if (i == FORMAT_ERR)
		ft_printf("ERROR:\n\nFile format error.");
	if (i == BAD_MAP_ERR)
		ft_printf("ERROR:\n\nInvalid map.");
	exit(0);
}

void		argument_checker(int argc, char **argv, t_params *prm)
{
	int fd;

	init_prm(prm);
	if (argc == 3 && ft_memcmp(argv[2], "--save", 6) != 0)
		error_handler(BAD_ARG_ERR);
	else if (argc < 2)
		error_handler(TOO_FEW_ARG_ERR);
	else if (argc > 3)
		error_handler(TOO_MANY_ARG_ERR);
	else if (argc == 3 && ft_memcmp(argv[2], "--save", 6) == 0)
		prm->save_bmp = 1;
	if (ft_memcmp(ft_strrchr(argv[1], '.'), ".cub", 4) != 0)
		error_handler(INVALID_FILE_ERR);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error_handler(INVALID_FILE_ERR);
	read_file(prm, fd);
	close(fd);
}

void		player_init(t_params *prm)
{
	if (prm->player->dir == 'N')
	{
		prm->player->dir_x = -1;
		prm->camera->plane_y = 0.66;
	}
	if (prm->player->dir == 'S')
	{
		prm->player->dir_x = 1;
		prm->camera->plane_y = -0.66;
	}
	if (prm->player->dir == 'E')
	{
		prm->player->dir_y = 1;
		prm->camera->plane_x = 0.66;
	}
	if (prm->player->dir == 'W')
	{
		prm->player->dir_y = -1;
		prm->camera->plane_x = -0.66;
	}
	prm->draw->fc_textures = 1;
	if (sprites_init(prm) == 0)
		error_handler(MALLOC_ERR);
	load_extra_textures(prm);
}
