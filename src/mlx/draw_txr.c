/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:32:46 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/18 14:38:56 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	get_texture_color(t_img *texture, int x, int y)
{
	int	offset;

	offset = (y * texture->length) + x * (texture->bpp / 8);
	return (*((int *)(texture->addr + offset)));
}

static void	draw_txr(t_data *data, t_img *txr, int y, int x)
{
	double	step;
	double	wallx;
	double	texpos;

	wallx = data->player->posx + data->ray->wdist
		* cos(data->player->dir + data->player->rayc);
	if (data->ray->side == 0)
		wallx = data->player->posy + data->ray->wdist
			* sin(data->player->dir + data->player->rayc);
	wallx -= floor((wallx));
	data->cub->tx = wallx * (double)(txr->width);
	if ((data->ray->side == 0 && data->ray->dirx > 0)
		|| (data->ray->side == 1 && data->ray->diry < 0))
		data->cub->tx = txr->width - data->cub->tx - 1;
	step = (1.0 * txr->height / data->cub->lheight);
	texpos = (data->cub->sdraw - WINH / 2 + data->cub->lheight / 2) * step;
	while (x < data->cub->edraw)
	{
		data->cub->ty = (int)texpos & (txr->height - 1);
		data->cub->clr = get_texture_color(txr, data->cub->tx, data->cub->ty);
		my_mlx_pixel_put(data->img, y, x, data->cub->clr);
		texpos += step;
		x++;
	}
}

void	draw_wall(t_data *data, int y, int x)
{
	if (data->ray->side)
	{
		if (data->ray->diry < 0)
			draw_txr(data, data->cub->sotx, y, x);
		else
			draw_txr(data, data->cub->notx, y, x);
	}
	else
	{
		if (data->ray->dirx > 0)
			draw_txr(data, data->cub->wetx, y, x);
		else
			draw_txr(data, data->cub->eatx, y, x);
	}
}
