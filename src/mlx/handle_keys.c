/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:18:54 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/04 13:02:37 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <math.h>

#define KUP 119
#define KDOWN 115
#define KLEFT 97
#define KRIGHT 100
#define RLEFT 65363
#define RRIGHT 65361
#define SPEED 0.05

static void	handle_press(int keycode, t_data *data)
{
	if (keycode == KUP)
		data->keys->kup = 1;
	if (keycode == KDOWN)
		data->keys->kdown = 1;
	if (keycode == KLEFT)
		data->keys->kleft = 1;
	if (keycode == KRIGHT)
		data->keys->kright = 1;
	if (keycode == RRIGHT)
		data->keys->kdirr = 1;
	if (keycode == RLEFT)
		data->keys->kdirl = 1;
}

void	move(t_data *data)
{
	if (data->keys->kup)
	{
		data->player->posx += cos(data->player->dir) * SPEED;
		data->player->posy += sin(data->player->dir) * SPEED;
	}
	if (data->keys->kdown)
	{
		data->player->posx -= cos(data->player->dir) * SPEED;
		data->player->posy -= sin(data->player->dir) * SPEED;
	}
	if (data->keys->kleft)
	{
		data->player->posx -= cos(data->player->dir + M_PI / 2) * SPEED;
		data->player->posy -= sin(data->player->dir + M_PI / 2) * SPEED;
	}
	if (data->keys->kright)
	{
		data->player->posx += cos(data->player->dir + M_PI / 2) * SPEED;
		data->player->posy += sin(data->player->dir + M_PI / 2) * SPEED;
	}
	if (data->keys->kdirr)
		data->player->dir -= SPEED;
	if (data->keys->kdirl)
		data->player->dir += SPEED;
}

int	release_key(int keycode, t_data *data)
{
	if (keycode == KUP)
		data->keys->kup = 0;
	if (keycode == KDOWN)
		data->keys->kdown = 0;
	if (keycode == KLEFT)
		data->keys->kleft = 0;
	if (keycode == KRIGHT)
		data->keys->kright = 0;
	if (keycode == RRIGHT)
		data->keys->kdirr = 0;
	if (keycode == RLEFT)
		data->keys->kdirl = 0;
	return (0);
}

int	handle_mouse(int x, int y, t_data *data)
{
	int		oldx;
	double	speed;

	(void)y;
	speed = 0.02;
	oldx = data->mousex;
	if (data->mousex == -1)
	{
		data->mousex = x;
		return (0);
	}
	data->mousex = x;
	if (data->mousex == oldx)
		return (0);
	if (data->mousex > oldx)
		data->player->dir += speed;
	if (data->mousex < oldx)
		data->player->dir -= speed;
	data->mousex = x;
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		escape(data);
	handle_press(keycode, data);
	return (0);
}
