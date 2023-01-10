/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:40:48 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/10 16:44:50 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>

static void	draw_dir(t_data *data, int px, int py, double len)
{
	int		x;
	int		y;

	data->player->py = py;
	data->player->px = px;
	x = px + cos(data->player->dir + data->player->rayc) * len;
	y = py + sin(data->player->dir + data->player->rayc) * len;
	draw_line(data, x, y, 0xFF0000);
}

void	draw_player(t_data *data, double dist)
{
	double	px;
	double	py;
	int		x;
	int		y;
	int		siz;

	siz = (double)WINH / data->map->height * data->map->size;
	x = (WINW - siz * data->map->width) - siz;
	y = (WINH - siz * data->map->height) - siz;
	px = x + data->player->posx * siz + siz / (double)2;
	py = y + data->player->posy * siz + siz / (double)2;
	draw_dir(data, px, py, dist * siz);
	draw_circle(data, px, py, 0x00FF00);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	siz;

	i = 0;
	j = 0;
	siz = (double)WINH / data->map->height * data->map->size;
	x = (WINW - siz * data->map->width) - siz;
	y = (WINH - siz * data->map->height) - siz;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->arr[i][j] == '1')
				draw_rectangle(data, x + j * siz, y + i * siz, 0xFFFFFF);
			else if (is_charset(data->map->arr[i][j], "NSEW0"))
				draw_rectangle(data, x + j * siz, y + i * siz, 0x7D7D7D);
			j++;
		}
		i++;
	}
}
