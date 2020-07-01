/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:05:29 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/03 13:48:39 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(char **file, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while (*(*file + i) != '\0' && *(*file + i) != '\n')
		i++;
	if (*(*file + i) == '\n')
	{
		*line = ft_substr(*file, 0, i);
		temp = ft_strdup(*file + i + 1);
		free(*file);
		*file = temp;
	}
	else
	{
		*line = ft_strdup(*file);
		free(*file);
		*file = 0;
		return (0);
	}
	return (1);
}

static int	read_to_buffer(int ret, char **file, char **buffer, int fd)
{
	char *aux;

	while (ret == BUFFER_SIZE)
	{
		if (ft_strchr(*file, '\n'))
			break ;
		ret = read(fd, *buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(*buffer);
			free(*file);
			return (-1);
		}
		*(*buffer + ret) = '\0';
		aux = ft_strjoin(*file, *buffer);
		free(*file);
		*file = aux;
	}
	free(*buffer);
	return (0);
}

static int	empty_line(int ret, char **line, char **buffer)
{
	if (ret == 0)
	{
		*line = ft_strdup("");
		free(*buffer);
		return (0);
	}
	else
	{
		free(*buffer);
		return (-1);
	}
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		*buffer;
	static char *file;

	ret = BUFFER_SIZE;
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))) || !line)
		return (-1);
	if (!file)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0 || ret == -1)
			return (empty_line(ret, &*line, &buffer));
		buffer[ret] = '\0';
		file = ft_strdup(buffer);
		free(buffer);
		if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	if (read_to_buffer(ret, &file, &buffer, fd) < 0)
		return (-1);
	return (get_line(&file, &*line));
}
