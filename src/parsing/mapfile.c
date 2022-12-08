/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:07:21 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/08 10:47:07 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	mapfile_check(t_data *data, char *path)
{
	int		len;
	char	tmpbuffer[1];

	len = ft_strlen(path);
	data->fd = open(path, O_RDONLY);
	if (data->fd == -1) // Check if exist
		return (print_err("Invalid map file", -1));
	if (read(data->fd, tmpbuffer, 0) == -1) // Check if directory
		return (print_err("Unable to read file", -1));
	if (!(path[len - 1] == 'b' && path[len - 2] == 'u' && path[len - 3] == 'c'
		&& path[len - 4] == '.'))
		return (print_err("Invalid map extension", -1));
	return (0);
}
