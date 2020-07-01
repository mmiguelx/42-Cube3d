/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:10:09 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/04 00:43:10 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

static void	bmp_dib_header(int fd, int file_size)
{
	int aux;

	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	aux = 0;
	write(fd, &aux, 4);
	aux = OFFSET + DIB_HEADER;
	write(fd, &aux, 4);
}

static void	bmp_header(t_params *prm, int fd)
{
	int file_size;
	int aux;

	aux = prm->draw->screen_width * prm->draw->screen_height;
	file_size = (4 + BITMAP_SIZE) * aux;
	bmp_dib_header(fd, file_size);
	aux = DIB_HEADER;
	write(fd, &aux, 4);
	write(fd, &prm->draw->screen_width, 4);
	write(fd, &prm->draw->screen_height, 4);
	aux = 1;
	write(fd, &aux, 2);
	aux = 32;
	write(fd, &aux, 2);
	aux = 0;
	write(fd, &aux, 4);
	write(fd, &file_size, 4);
	aux = DPI;
	write(fd, &aux, 4);
	write(fd, &aux, 4);
	aux = 0;
	write(fd, &aux, 8);
}

void		create_bmp(t_params *prm)
{
	int fd;
	int h;
	int w;
	int aux;

	if ((fd = open("Cube3d.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
		error_handler(CREATE_ERR);
	else
	{
		bmp_header(prm, fd);
		h = -1;
		while (++h < prm->draw->screen_height)
		{
			w = -1;
			while (++w < prm->draw->screen_width)
			{
				aux = *(prm->draw->view_data + (prm->draw->screen_width *
									(prm->draw->screen_height - 1 - h) + w));
				write(fd, &aux, 4);
			}
		}
	}
	close(fd);
	exit_game(prm);
}
