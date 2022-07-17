/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:07:21 by hlevi             #+#    #+#             */
/*   Updated: 2022/07/17 15:59:34 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	mapfile_check(t_data *data, char *path)
{
	char	tmpbuffer[1];

	data->fd = open(path, O_RDONLY);
	if (data->fd == -1)
	{
		printf("Invalid map file\n");
		return (-1);
	}
	if (read(data->fd, tmpbuffer, 0) == -1)
	{
		printf("Can't use a directory as a map ???\n");
		return (-1);
	}
	return (0);
}
