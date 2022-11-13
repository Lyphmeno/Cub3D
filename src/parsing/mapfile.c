/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:07:21 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/13 14:55:53 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mapfile_info_check(t_data *data)
{
	if (!data->txr[0])
		return (print_err("Missing NORTH texture", -1));
	if (!data->txr[1])
		return (print_err("Missing SOUTH texture", -1));
	if (!data->txr[2])
		return (print_err("Missing WEST texture", -1));
	if (!data->txr[3])
		return (print_err("Missing EAST texture", -1));
	if (!data->sky)
		return (print_err("Missing SKY texture", -1));
	if (!data->flr)
		return (print_err("Missing FLOOR texture", -1));
	return (0);
}

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
