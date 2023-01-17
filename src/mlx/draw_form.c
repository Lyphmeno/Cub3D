/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:39:05 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/17 18:30:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_circle(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	siz;

	siz = ((double)WINH / data->map->height * data->map->size) / 5;
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

	siz = (double)WINH / data->map->height * data->map->size;
	x += siz / 2;
	y += siz / 2;
	i = y;
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

void	draw_dirline(t_data *data, int x, int y, int color)
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

int get_texture_color(t_img *texture, int x, int y)
{
    int offset = (y * texture->length) + (x * texture->bpp / 8);
    return *((int*)(texture->addr + offset));
}

void	draw_notxr(t_data *data, int y, int x)
{
	int		texX;
	int		color;
	double	step;
	double	wallX;
	double	texPos;

	if (data->ray->side == 0)
		wallX = data->player->posy + data->ray->wdist * data->ray->diry;
	else
		wallX = data->player->posx + data->ray->wdist * data->ray->dirx;
	wallX -= floor((wallX));
	texX = (int)wallX * (double)data->cub->notx->width;
	if(data->ray->side == 0 && data->ray->dirx > 0)
		texX = data->cub->notx->width - texX - 1;
	if(data->ray->side == 1 && data->ray->diry < 0)
		texX = data->cub->notx->width - texX - 1;
	step = (1.0 * data->cub->notx->height / data->cub->lheight);
	texPos = (data->cub->sdraw - WINH / 2 + data->cub->lheight / 2) * step;
	while (x < data->cub->edraw)
	{
		texPos += step;
		if (texPos >= data->cub->notx->height)
			texPos = data->cub->notx->height - 1;
		color = get_texture_color(data->cub->notx, texX, texPos);
		my_mlx_pixel_put(data->img, y, x, color);
		x++;
	}
}

static void	draw_wall(t_data *data, int y, int x)
{
	if (data->ray->side)
	{
		if (data->ray->diry < 0) // SOUTH
			draw_notxr(data, y, x);
		else // NORTH
			my_mlx_pixel_put(data->img, y, x, 0xFF0000);
	}
	else
	{
		if (data->ray->dirx > 0) // WEST
			my_mlx_pixel_put(data->img, y, x, 0x0000FF);
		else // EAST
			my_mlx_pixel_put(data->img, y, x, 0x00FF00);
	}
}

void	draw_truline(t_data *data, int i)
{
	int	x;

	x = 0;
	while (x <= data->cub->sdraw)
	{
		my_mlx_pixel_put(data->img, i, x, data->map->sky);
		x++;
	}
	draw_wall(data, i, data->cub->sdraw);
	x = WINH - data->cub->sdraw;
	while (x < WINH)
	{
		my_mlx_pixel_put(data->img, i, x, data->map->flr);
		x++;
	}
}
