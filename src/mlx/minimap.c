/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:40:48 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/02 16:59:30 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	draw_circle(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	siz;

	siz = (WINH / data->map->height * MINIMAP) / 5;
	i = x - siz;
	while (i <= x + siz)
	{
		j = y - siz;
		while (j <= y + siz)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= siz * siz)
				my_mlx_pixel_put(data->img, i, j, color);
			j++;
		}
		i++;
	}
}

static void	draw_rectangle(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	siz;
	int	offset;

	i = y;
	siz = WINH / data->map->height * MINIMAP;
	while (i < y + siz)
	{
		j = x;
		while (j < x + siz)
		{
			offset = i * data->img->length + j * (data->img->bpp / 8);
			if (i < y + siz - 1 && j < x + siz - 1)
				*(int *)(data->img->addr + offset) = color;
			else
				*(int *)(data->img->addr + offset) = color >> 16;
			j++;
		}
		i++;
	}
}

static void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	siz;

	i = 0;
	j = 0;
	siz = WINH / data->map->height * MINIMAP;
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

static void	draw_player(t_data *data)
{
	double	px;
	double	py;
	int		x;
	int		y;
	int		siz;

	siz = WINH / data->map->height * MINIMAP;
	x = (WINW - siz * data->map->width) - siz;
	y = (WINH - siz * data->map->height) - siz;
	px = x + data->player->posx * siz + siz / (double)2;
	py = y + data->player->posy * siz + siz / (double)2;
	draw_circle(data, px, py, 0x0000FF);
}

void	draw_minimap(t_data *data)
{
	draw_map(data);
	draw_player(data);
}
