/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:44:19 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/05 12:45:05 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>

#define SPEED 0.05

static int	check_col(t_data *data, int x, int y)
{
	printf("col = %d,%d\n", x, y);
	if (data->map->arr[y][x] == '1')
		return (1);
	return (0);
}

static void	move_up(t_data *data)
{
	double	posx;
	double	posy;
	double	incx;
	double	incy;
	double	dist;

	posx = data->player->posx;
	posy = data->player->posy;
	incx = cos(data->player->dir) * SPEED;
	incy = sin(data->player->dir) * SPEED;
	dist = sqrt(incx * incx +incy * incy);
	while (dist > 0)
	{
		posx += incx;
		posy += incy;
		if (check_col(data, posx, posy))
		{
			posx -= incx;
			posy -= incy;
			break;
		}
		dist -= SPEED;
	}
	data->player->posx = posx;
	data->player->posy = posy;
}

static void	move_down(t_data *data)
{
	double	posx;
	double	posy;
	double	incx;
	double	incy;
	double	dist;

	posx = data->player->posx;
	posy = data->player->posy;
	incx = cos(data->player->dir) * SPEED;
	incy = sin(data->player->dir) * SPEED;
	dist = sqrt(incx * incx +incy * incy);
	while (dist > 0)
	{
		posx -= incx;
		posy -= incy;
		if (check_col(data, posx, posy))
		{
			posx += incx;
			posy += incy;
			break;
		}
		dist -= SPEED;
	}
	data->player->posx = posx;
	data->player->posy = posy;
}

static void	move_left(t_data *data)
{
	double	posx;
	double	posy;
	double	incx;
	double	incy;
	double	dist;

	posx = data->player->posx;
	posy = data->player->posy;
	incx = cos(data->player->dir + M_PI / 2) * SPEED;
	incy = sin(data->player->dir + M_PI / 2) * SPEED;
	dist = sqrt(incx * incx +incy * incy);
	while (dist > 0)
	{
		posx -= incx;
		posy -= incy;
		if (check_col(data, posx, posy))
		{
			posx += incx;
			posy += incy;
			break;
		}
		dist -= SPEED;
	}
	data->player->posx = posx;
	data->player->posy = posy;
}

static void	move_right(t_data *data)
{
	double	posx;
	double	posy;
	double	incx;
	double	incy;
	double	dist;

	posx = data->player->posx;
	posy = data->player->posy;
	incx = cos(data->player->dir + M_PI / 2) * SPEED;
	incy = sin(data->player->dir + M_PI / 2) * SPEED;
	dist = sqrt(incx * incx +incy * incy);
	while (dist > 0)
	{
		posx += incx;
		posy += incy;
		if (check_col(data, posx, posy))
		{
			posx -= incx;
			posy -= incy;
			break;
		}
		dist -= SPEED;
	}
	data->player->posx = posx;
	data->player->posy = posy;
}

void	move(t_data *data)
{
	if (data->keys->kup)
		move_up(data);
	if (data->keys->kdown)
		move_down(data);
	if (data->keys->kleft)
		move_left(data);
	if (data->keys->kright)
		move_right(data);
	if (data->keys->kdirr)
		data->player->dir -= SPEED;
	if (data->keys->kdirl)
		data->player->dir += SPEED;
}
