/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:40:48 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/23 15:13:41 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_limit(t_data *data, double posx, double posy)
{
	if (posx > 1 && posx < data->map->width - 1)
		data->player->posx = posx;
	if (posy > 1 && posy < data->map->height - 1)
		data->player->posy = posy;
}

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
	draw_dirline(data, x, y, 0xFF0000);
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

void	draw_rays(t_data *data)
{
	int	i;

	i = 0;
	data->map->x = (WINW - data->map->siz * data->map->width) - data->map->siz;
	data->map->y = (WINH - data->map->siz * data->map->height) - data->map->siz;
	data->player->rayc = -1 * (FOV / 2);
	while (i++ < WINW)
	{
		init_rays(data, i);
		get_sidist(data);
		cast_rays(data);
		if (data->map->show)
			draw_dir(data, data->map->x + data->player->x,
				data->map->y + data->player->y,
				data->ray->wdist * data->map->siz);
		data->player->rayc += FOV / WINW;
	}
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
