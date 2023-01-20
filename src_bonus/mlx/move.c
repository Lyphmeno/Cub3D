/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:44:19 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/20 12:15:46 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

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
	dist = sqrt(incx * incx + incy * incy);
	while (dist > 0)
	{
		posx += incx;
		posy += incy;
		if (data->map->arr[(int)posy][(int)posx] == '1')
		{
			posx -= incx;
			posy -= incy;
			break ;
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
	dist = sqrt(incx * incx + incy * incy);
	while (dist > 0)
	{
		posx -= incx;
		posy -= incy;
		if (data->map->arr[(int)posy][(int)posx] == '1')
		{
			posx += incx;
			posy += incy;
			break ;
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
	incx = cos(data->player->dir + M_PI / 2) * (SPEED * 0.5);
	incy = sin(data->player->dir + M_PI / 2) * (SPEED * 0.5);
	dist = sqrt(incx * incx + incy * incy);
	while (dist > 0)
	{
		posx -= incx;
		posy -= incy;
		if (data->map->arr[(int)posy][(int)posx] == '1')
		{
			posx += incx;
			posy += incy;
			break ;
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
	incx = cos(data->player->dir + M_PI / 2) * (SPEED * 0.5);
	incy = sin(data->player->dir + M_PI / 2) * (SPEED * 0.5);
	dist = sqrt(incx * incx + incy * incy);
	while (dist > 0)
	{
		posx += incx;
		posy += incy;
		if (data->map->arr[(int)posy][(int)posx] == '1')
		{
			posx -= incx;
			posy -= incy;
			break ;
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
		data->player->dir -= (SPEED * 0.5);
	if (data->keys->kdirl)
		data->player->dir += (SPEED * 0.5);
}
