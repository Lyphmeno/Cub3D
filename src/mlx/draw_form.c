/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:39:05 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/04 15:41:02 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_circle(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	siz;

	siz = (WINH / data->map->height * data->map->size) / 5;
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

void	draw_rectangle(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	siz;
	int	offset;

	i = y;
	siz = WINH / data->map->height * data->map->size;
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

void	draw_line(t_data *data, int x, int y, int color)
{
	int	dx;
	int	dy;
	int	err;

	dx = abs(x - data->player->px);
	dy = abs(y - data->player->py);
	err = dx - dy;
	while (data->player->px != x || data->player->py != y)
	{
		my_mlx_pixel_put(data->img, data->player->px, data->player->py, color);
		if ((err * 2) > (-1 * dy))
		{
			err -= dy;
			if (x > data->player->px)
				data->player->px += 2;
			data->player->px += -1;
		}
		if ((err * 2) < dx)
		{
			err += dx;
			if (y > data->player->py)
				data->player->py += 2;
			data->player->py += -1;
		}
	}
}
