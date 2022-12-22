/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:48:43 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/22 11:55:33 by hlevi            ###   ########.fr       */
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

void	draw_player(t_data *data, int size)
{
	int	i;
	int	j;

	i = size / -2;
	while (i != size / 2)
	{
		j = size / -2;
		while (j != size / 2)
		{
			my_mlx_pixel_put(data->img, data->player->posx + i,
			  data->player->posy + j, data->map->sky);
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
	draw_player(data, 15);
	//render(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img);
	return (0);
}
