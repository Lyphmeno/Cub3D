/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:40:48 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/13 12:11:16 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>
#include <stdio.h>

void	draw_dir(t_data *data, int px, int py, double len)
{
	int		x;
	int		y;

	data->player->py = py;
	data->player->px = px;
	x = px + cos(data->player->dir + data->player->rayc) * len;
	y = py + sin(data->player->dir + data->player->rayc) * len;
	if (data->player->px - x > 0)
		x += data->map->size * 2;
	else
		x -= data->map->size * 2;
	if (data->player->py - y > 0)
		y += data->map->size * 2;
	else
		y -= data->map->size * 2;
	draw_line(data, x, y, 0xFF0000);
}

void	draw_player(t_data *data)
{
	double	px;
	double	py;
	int		x;
	int		y;

	x = (WINW - data->map->siz * data->map->width) - data->map->siz;
	y = (WINH - data->map->siz * data->map->height) - data->map->siz;
	px = x + data->player->x;
	py = y + data->player->y;
	draw_circle(data, px, py, 0x00FF00);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = (WINW - data->map->siz * data->map->width) - data->map->siz;
	y = (WINH - data->map->siz * data->map->height) - data->map->siz;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->arr[i][j] == '1')
				draw_rectangle(data, x + j * data->map->siz,
					y + i * data->map->siz, 0xFFFFFF);
			else if (is_charset(data->map->arr[i][j], "NSEW0"))
				draw_rectangle(data, x + j * data->map->siz,
					y + i * data->map->siz, 0x7D7D7D);
			j++;
		}
		i++;
	}
}
