/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:48:43 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/02 14:55:29 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>

int	escape(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free_data(data);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	siz;
	int	offset;

	i = y;
	siz = WINH / data->map->height / MINIMAP;
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

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	siz;
	int	x;
	int	y;

	i = 0;
	j = 0;
	siz = WINH / data->map->height / MINIMAP;
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

int	image_loop(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, WINW, WINH);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->length, &data->img->endian);
	draw_map(data);
	//draw_player(data);
	//render(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img);
	return (0);
}
