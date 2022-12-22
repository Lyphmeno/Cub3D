/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:48:43 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/22 14:46:03 by hlevi            ###   ########.fr       */
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

void	draw_cube(t_data *data, int x, int y, int clr)
{
	int	i;
	int	j;
	int	cub;

	cub = WINW / data->map->width;
	x *= cub;
	y *= cub;
	i = (cub / -2);
	while (i != cub / 2)
	{
		j = cub / -2;
		while (j != cub / 2)
		{
			my_mlx_pixel_put(data->img, cub + x + i, cub + y + j, clr);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map->height)
	{
		y = 0;
		while (y < data->map->width)
		{
			if (data->map->arr[x][y] == '1')
				draw_cube(data, y, x, create_rgb(100, 100, 100));
			if (data->map->arr[x][y] == '0')
				draw_cube(data, y, x, create_rgb(200, 200, 200));
			y++;
		}
		x++;
	}
}

void	draw_player(t_data *data)
{
	draw_cube(data, data->player->posx, data->player->posy, data->map->sky);
}

int	image_loop(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, WINW, WINH);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->length, &data->img->endian);
	draw_map(data);
	draw_player(data);
	//render(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img);
	return (0);
}
