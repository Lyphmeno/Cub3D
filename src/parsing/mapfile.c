/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:07:21 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/18 16:13:57 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	mapfile_check(t_data *data, char *path)
{
	char	tmpbuffer[1];

	data->fd = open(path, O_RDONLY);
	if (data->fd == -1) // Check if exist
		return (print_err("Invalid map file", -1));
	if (read(data->fd, tmpbuffer, 0) == -1) // Check if directory
		return (print_err("Unable to read file", -1));
	return (0);
}
