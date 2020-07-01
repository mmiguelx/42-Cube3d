/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:35:45 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/05 15:50:34 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

static void	check_map(t_params *prm)
{
	int i;
	int j;

	i = 0;
	while (i < prm->map_height)
	{
		j = 0;
		while (j < prm->map_width)
		{
			if (prm->world_map[i][j] < 0 && ((i != 0 &&
prm->world_map[i - 1][j] == 0) || (j != 0 && (prm->world_map[i][j - 1] == 0))))
				error_handler(BAD_MAP_ERR);
			if (prm->world_map[i][j] < 0 && ((i != 0 &&
prm->world_map[i - 1][j] == 2) || (j != 0 && (prm->world_map[i][j - 1] == 2))))
				error_handler(BAD_MAP_ERR);
			if ((prm->world_map[i][j] == 0 || prm->world_map[i][j] == 2) &&
			(i == 0 || j == 0 || i == prm->map_height || j == prm->map_width ||
				prm->world_map[i - 1][j] < 0 || prm->world_map[i][j - 1] < 0))
				error_handler(BAD_MAP_ERR);
			j++;
		}
		++i;
	}
}

static void	check_and_set_values(t_params *prm, int i, int j)
{
	if (*prm->map_str == 'N' || *prm->map_str == 'S' ||
								*prm->map_str == 'E' || *prm->map_str == 'W')
	{
		if (prm->player->pos_y == 0)
		{
			prm->player->pos_x = i + 0.5;
			prm->player->pos_y = j + 0.5;
			prm->player->dir = *prm->map_str;
		}
		else
			error_handler(BAD_MAP_ERR);
	}
	else
	{
		if (*prm->map_str == '0' || *prm->map_str == '1' || *prm->map_str == ' '
														|| *prm->map_str == '2')
			prm->world_map[i][j] = *prm->map_str - '0';
		else
			error_handler(BAD_MAP_ERR);
	}
	if (prm->world_map[i][j] == 2)
		prm->sprites->num++;
	prm->map_str++;
}

static void	set_map(t_params *prm)
{
	int i;
	int j;

	if (!(prm->world_map = (int**)ft_calloc(prm->map_height, sizeof(int*))))
		error_handler(MALLOC_ERR);
	i = -1;
	while (++i < prm->map_height)
	{
		if (!(prm->world_map[i] = (int*)ft_calloc(prm->map_width, sizeof(int))))
			error_handler(MALLOC_ERR);
		j = -1;
		while (++j < prm->map_width)
		{
			if (*prm->map_str == '\n')
			{
				while (j < prm->map_width)
					prm->world_map[i][j++] = -1;
				prm->map_str++;
				break ;
			}
			check_and_set_values(prm, i, j);
		}
		if (*prm->map_str == '\n')
			prm->map_str++;
	}
}

static void	check_and_set(t_params *prm, char *line)
{
	if (*line == 'R')
		check_and_set_resolution(prm, line);
	else if (*line == 'S' || *line == 'N' || *line == 'W' || *line == 'E')
		check_and_set_textures(prm, line);
	else if (*line == 'C')
		check_and_set_cealing_color(prm, line);
	else if (*line == 'F')
		check_and_set_floor_color(prm, line);
	else if (ft_isdigit(*line) || *line == ' ')
		read_map(prm, line);
	else if (*line != '\0')
		error_handler(FORMAT_ERR);
}

void		read_file(t_params *prm, int fd)
{
	char	*line;
	int		i;

	while ((i = get_next_line(fd, &line)) >= 0)
	{
		check_and_set(prm, line);
		free(line);
		if (i == 0)
		{
			while (prm->draw->texture[i] && i < 4)
				i++;
			if (i != 4)
				error_handler(TEXTURE_ERR);
			if (prm->map_height < 3 || prm->map_width < 3)
				error_handler(BAD_MAP_ERR);
			set_map(prm);
			check_map(prm);
			if (prm->player->pos_x == 0)
				error_handler(BAD_MAP_ERR);
			break ;
		}
	}
	if (i < 0)
		error_handler(INVALID_FILE_ERR);
}
