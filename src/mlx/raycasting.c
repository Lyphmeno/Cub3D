/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:45:17 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/12 16:38:08 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	get_sidist(t_data *data)
{
	if (data->ray->dirx < 0)
	{
		data->ray->stepx = -1;
		data->ray->sidistx = (data->player->posx - data->ray->mapx)
			* data->ray->deltax;
	}
	else
	{
		data->ray->stepx = 1;
		data->ray->sidistx = (data->ray->mapx + 1.0 - data->player->posx)
			* data->ray->deltax;
	}
	if (data->ray->diry < 0)
	{
		data->ray->stepy = -1;
		data->ray->sidisty = (data->player->posy - data->ray->mapy)
			* data->ray->deltay;
	}
	else
	{
		data->ray->stepy = 1;
		data->ray->sidisty = (data->ray->mapy + 1.0 - data->player->posy)
			* data->ray->deltay;
	}
}

static void	cast_ray(t_data *data)
{
	while (data->ray->hit == 0)
	{
		if (data->ray->sidistx < data->ray->sidisty)
		{
			data->ray->sidistx += data->ray->deltax;
			data->ray->mapx += data->ray->stepx;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sidisty += data->ray->deltay;
			data->ray->mapy += data->ray->stepy;
			data->ray->side = 1;
		}
		if (data->map->arr[data->ray->mapy][data->ray->mapx] == '1')
			data->ray->hit = 1;
	}
	if (data->ray->side == 0)
		data->ray->wdist = (data->ray->sidistx - data->ray->deltax);
	else
		data->ray->wdist = (data->ray->sidisty - data->ray->deltay);
}

static void	init_ray(t_data *data, int i)
{
	data->ray->hit = 0;
	data->ray->camera = 2 * i / FOV - 1;
	data->ray->mapx = (int)data->player->posx;
	data->ray->mapy = (int)data->player->posy;
	data->ray->dirx = (cos(data->player->dir + data->player->rayc))
		* data->ray->camera;
	data->ray->diry = (sin(data->player->dir + data->player->rayc))
		* data->ray->camera;
	data->ray->deltax = sqrt(1 + (data->ray->diry * data->ray->diry)
			/ (data->ray->dirx * data->ray->dirx));
	data->ray->deltay = sqrt(1 + (data->ray->dirx * data->ray->dirx)
			/ (data->ray->diry * data->ray->diry));
	data->player->x = data->player->posx
		* data->map->siz + data->map->siz / (double)2;
	data->player->y = data->player->posy
		* data->map->siz + data->map->siz / (double)2;
}

void	raycasting(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = (WINW - data->map->siz * data->map->width) - data->map->siz;
	y = (WINH - data->map->siz * data->map->height) - data->map->siz;
	data->player->rayc = -1 * (FOV / 2);
	while (i++ < WINW)
	{
		init_ray(data, i);
		get_sidist(data);
		cast_ray(data);
		if (data->map->show)
			draw_dir(data, x + data->player->x, y + data->player->y,
				data->ray->wdist * data->map->siz);
		// Beginning of drawing
		data->cub->lheight = (int)(WINH / data->ray->wdist);
		data->cub->sdraw = -data->cub->lheight / 2 + WINH / 2;
		data->cub->edraw = data->cub->lheight / 2 + WINH / 2;
		if (data->cub->sdraw < 0)
			data->cub->sdraw = 0;
		if (data->cub->edraw >= WINH)
			data->cub->edraw = WINH - 1;
		// End of drawing
		data->player->rayc += FOV / WINW;
	}
	if (data->map->show)
		draw_player(data);
}