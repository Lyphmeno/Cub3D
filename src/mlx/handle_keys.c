/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:18:54 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/03 12:21:20 by hlevi            ###   ########.fr       */
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

static void	handle_pos(int keycode, t_data *data)
{
	double	speed;

	speed = 0.1;
	if (keycode == KUP)
	{
		data->player->posx += cos(data->player->dir) * speed;
		data->player->posy += sin(data->player->dir) * speed;
	}
	if (keycode == KDOWN)
	{
		data->player->posx -= cos(data->player->dir) * speed;
		data->player->posy -= sin(data->player->dir) * speed;
	}
	if (keycode == KLEFT)
	{
		data->player->posx -= cos(data->player->dir + M_PI / 2) * speed;
		data->player->posy -= sin(data->player->dir + M_PI / 2) * speed;
	}
	if (keycode == KRIGHT)
	{
		data->player->posx += cos(data->player->dir + M_PI / 2) * speed;
		data->player->posy += sin(data->player->dir + M_PI / 2) * speed;
	}
}

static void	handle_dir(int keycode, t_data *data)
{
	double	speed;

	speed = 0.1;
	if (keycode == RRIGHT)
		data->player->dir -= speed;
	if (keycode == RLEFT)
		data->player->dir += speed;
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		escape(data);
	handle_pos(keycode, data);
	handle_dir(keycode, data);
	return (0);
}
