/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:34:30 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/05 14:31:30 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	read_map(t_params *prm, char *line)
{
	char	*temp;
	char	*temp2;
	size_t	len;

	len = ft_strlen(line);
	prm->map_width = prm->map_width < (int)len ? len : prm->map_width;
	if (len < 3)
		error_handler(BAD_MAP_ERR);
	temp = ft_strjoin(prm->map_str, line);
	temp2 = ft_strjoin(temp, "\n");
	free(prm->map_str);
	free(temp);
	prm->map_str = temp2;
	prm->map_height++;
}

void	check_and_set_floor_color(t_params *prm, char *line)
{
	if (prm->draw->floor_red == -1)
	{
		while (ft_isspace(*line) || *line == 'F')
			line++;
		if ((prm->draw->floor_red = ft_atoi(line)) < 0 ||
												prm->draw->floor_red > 255)
			error_handler(COLOR_FC_ERR);
		while (ft_isdigit(*line))
			line++;
		while (ft_isspace(*line) || *line == ',')
			line++;
		if ((prm->draw->floor_green = ft_atoi(line)) < 0 ||
												prm->draw->floor_green > 255)
			error_handler(COLOR_FC_ERR);
		while (ft_isdigit(*line))
			line++;
		while (ft_isspace(*line) || *line == ',')
			line++;
		if ((prm->draw->floor_blue = ft_atoi(line)) < 0 ||
												prm->draw->floor_blue > 255)
			error_handler(COLOR_FC_ERR);
	}
	else
		error_handler(COLOR_FC_ERR);
}

void	check_and_set_cealing_color(t_params *prm, char *line)
{
	if (prm->draw->cealing_red == -1)
	{
		while (ft_isspace(*line) || *line == 'C')
			line++;
		if ((prm->draw->cealing_red = ft_atoi(line)) < 0 ||
												prm->draw->cealing_red > 255)
			error_handler(COLOR_FC_ERR);
		while (ft_isdigit(*line))
			line++;
		while (ft_isspace(*line) || *line == ',')
			line++;
		if ((prm->draw->cealing_green = ft_atoi(line)) < 0 ||
												prm->draw->cealing_green > 255)
			error_handler(COLOR_FC_ERR);
		while (ft_isdigit(*line))
			line++;
		while (ft_isspace(*line) || *line == ',')
			line++;
		if ((prm->draw->cealing_blue = ft_atoi(line)) < 0 ||
												prm->draw->cealing_blue > 255)
			error_handler(COLOR_FC_ERR);
	}
	else
		error_handler(COLOR_FC_ERR);
}

void	check_and_set_textures(t_params *prm, char *file)
{
	int h;
	int w;
	int i;

	if (*file == 'N' && *(file + 1) == 'O')
		i = NORTH_TEXT;
	else if (*file == 'S' && *(file + 1) == 'O')
		i = SOUTH_TEXT;
	else if (*file == 'W' && *(file + 1) == 'E')
		i = WEST_TEXT;
	else if (*file == 'E' && *(file + 1) == 'A')
		i = EAST_TEXT;
	else if (*file == 'S')
		i = SPRITE_TEXT;
	else
		error_handler(TEXTURE_ERR);
	file = file + 2;
	while (ft_isspace(*file))
		++file;
	if (open(file, O_RDONLY) < 0 || (prm->draw->texture[i]))
		error_handler(TEXTURE_ERR);
	prm->draw->texture_ptr = mlx_xpm_file_to_image(prm->mlx_ptr, file, &h, &w);
	prm->draw->texture[i] = (int*)mlx_get_data_addr(prm->draw->texture_ptr,
						&prm->draw->bbp, &prm->draw->sl, &prm->draw->endian);
}

void	check_and_set_resolution(t_params *prm, char *line)
{
	if (prm->draw->screen_width >= MIN_SCREEN_RESOLUTION)
		error_handler(RESOLUTION_DUP_ERR);
	else
	{
		if ((prm->draw->screen_width = ft_atoi(++line)) < MIN_SCREEN_RESOLUTION)
			prm->draw->screen_width = MIN_SCREEN_RESOLUTION;
		else if (prm->draw->screen_width > MAX_SCREEN_WIDTH)
			prm->draw->screen_width = MAX_SCREEN_WIDTH;
		while (ft_isspace(*line))
			++line;
		while (ft_isdigit(*line))
			++line;
		if ((prm->draw->screen_height = ft_atoi(line)) < MIN_SCREEN_RESOLUTION)
			prm->draw->screen_height = MIN_SCREEN_RESOLUTION;
		else if (prm->draw->screen_height > MAX_SCREEN_HEIGHT)
			prm->draw->screen_height = MAX_SCREEN_HEIGHT;
	}
}
