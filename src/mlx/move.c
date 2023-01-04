/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:44:19 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/04 15:12:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>

#define SPEED 0.05

static void	move_up(t_data *data)
{
	double	posx;
	double	posy;

	posx = data->player->posx + cos(data->player->dir) * SPEED;
	posy = data->player->posy + sin(data->player->dir) * SPEED;
	if (data->keys->kup)
	{
		if (posx > 0 && posx < data->map->width)
			data->player->posx += cos(data->player->dir) * SPEED;
		if (posy > 0 && posy < data->map->height)
			data->player->posy += sin(data->player->dir) * SPEED;
	}
}

static void	move_down(t_data *data)
{
	double	posx;
	double	posy;

	posx = data->player->posx - cos(data->player->dir) * SPEED;
	posy = data->player->posy - sin(data->player->dir) * SPEED;
	if (data->keys->kdown)
	{
		if (posx > 0 && posx < data->map->width)
			data->player->posx -= cos(data->player->dir) * SPEED;
		if (posy > 0 && posy < data->map->height)
			data->player->posy -= sin(data->player->dir) * SPEED;
	}
}

static void	move_left(t_data *data)
{
	double	posx;
	double	posy;

	posx = data->player->posx - cos(data->player->dir + M_PI / 2) * SPEED;
	posy = data->player->posy - sin(data->player->dir + M_PI / 2) * SPEED;
	if (data->keys->kleft)
	{
		if (posx > 0 && posx < data->map->width)
			data->player->posx -= cos(data->player->dir + M_PI / 2) * SPEED;
		if (posy > 0 && posy < data->map->height)
			data->player->posy -= sin(data->player->dir + M_PI / 2) * SPEED;
	}
}

static void	move_right(t_data *data)
{
	double	posx;
	double	posy;

	posx = data->player->posx + cos(data->player->dir + M_PI / 2) * SPEED;
	posy = data->player->posy + sin(data->player->dir + M_PI / 2) * SPEED;
	if (data->keys->kright)
	{
		if (posx > 0 && posx < data->map->width)
			data->player->posx += cos(data->player->dir + M_PI / 2) * SPEED;
		if (posy > 0 && posy < data->map->height)
			data->player->posy += sin(data->player->dir + M_PI / 2) * SPEED;
	}
}

void	move(t_data *data)
{
	move_up(data);
	move_down(data);
	move_left(data);
	move_right(data);
	if (data->keys->kdirr)
		data->player->dir -= SPEED;
	if (data->keys->kdirl)
		data->player->dir += SPEED;
}
