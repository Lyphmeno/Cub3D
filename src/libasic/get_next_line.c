/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:42:58 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/12 09:44:00 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

static char	*getline_from_buffer(char *buffer, char **line)
{
	*line = gnl_strdup(buffer, '\n');
	gnl_memmove(buffer, buffer + gnl_strlen(buffer, '\n'),
		gnl_strlen(buffer, '\0') - gnl_strlen(buffer, '\n') + 1);
	return (*line);
}

static char	*getline_from_read(char *buffer, char **line)
{
	char	*tmp;

	tmp = *line;
	*line = gnl_strjoin(*line, buffer, '\n');
	gnl_memmove(buffer, buffer + gnl_strlen(buffer, '\n'),
		gnl_strlen(buffer, '\0') - gnl_strlen(buffer, '\n') + 1);
	if (tmp != NULL)
		free(tmp);
	return (*line);
}

static void	clear_buffer(char *buffer, char **line)
{
	char	*tmp;

	tmp = *line;
	*line = gnl_strjoin(*line, buffer, '\0');
	if (tmp != NULL)
		free(tmp);
	buffer[0] = '\0';
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	line = NULL;
	if (buffer[0] != '\0')
	{
		if (gnl_is_newline(buffer) == 1)
			return (getline_from_buffer(buffer, &line));
		line = gnl_strdup(buffer, '\0');
		buffer[0] = '\0';
	}
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (gnl_is_newline(buffer) == 1)
			return (getline_from_read(buffer, &line));
		clear_buffer(buffer, &line);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if ((ret == 0 && buffer[0] == '\0' && line == NULL) || ret == -1)
		return (NULL);
	return (line);
}
