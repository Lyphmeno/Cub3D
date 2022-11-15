/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:35:00 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/15 14:00:03 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i--;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*buf_reset(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

static char	*buf_read(int fd, char *buffer)
{
	char	*tmp_buf;
	int		bytes;

	tmp_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	bytes = 1;
	while (!gnl_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp_buf);
			return (NULL);
		}
		tmp_buf[bytes] = '\0';
		buffer = gnl_strjoin(buffer, tmp_buf);
	}
	free(tmp_buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = buf_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = buf_reset(buffer[fd]);
	return (line);
}
