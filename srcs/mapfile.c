/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:07:21 by hlevi             #+#    #+#             */
/*   Updated: 2022/07/16 18:13:08 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	mapfile_check(t_data *data, char *path)
{
	if ((data->fd = open(path, O_RDONLY)) == -1)
	{
		printf("Invalid map file\n");
		return (-1);
	}
	return (0);
}
