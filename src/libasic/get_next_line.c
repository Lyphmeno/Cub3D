/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:26:17 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/07 15:59:08 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t gnl_read_file(int fd, char **buffer, char **buff_read, char **line)
{
	char *temp;
	ssize_t n;

	n = 1;
	while (!gnl_ft_strchr(*buff_read, '\n') && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[n] = '\0';
		temp = *buff_read;
		*buff_read = gnl_ft_strjoin(temp, *buffer);
		free(temp);
	}
	free(*buffer);
	*buffer = NULL;
	*buff_read = gnl_get_line(buff_read, line);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (n);
}

char *gnl_get_line(char **buff_read, char **line)
{
	size_t i;
	char *new_buff;

	i = 0;
	new_buff = NULL;
	while ((*(*buff_read + i) != '\n') && (*(*buff_read + i) != '\0'))
		i++;
	if (*(*buff_read + i) == '\n')
	{
		i++;
		*line = gnl_ft_substr(*buff_read, 0, i);
		new_buff = gnl_ft_strdup(*buff_read + i);
	}
	else
		*line = gnl_ft_strdup(*buff_read);
	free(*buff_read);
	*buff_read = NULL;
	return (new_buff);
}

char *get_next_line(int fd)
{
	static char *buff_read[FOPEN_MAX];
	char *buffer;
	char *line;
	ssize_t n;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buff_read[fd])
		buff_read[fd] = gnl_ft_strdup("");
	n = gnl_read_file(fd, &buffer, &buff_read[fd], &line);
	if (n == 0 && !line)
		return (NULL);
	return (line);
}
