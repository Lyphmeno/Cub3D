/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:44:19 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/24 12:17:53 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	move_up(t_data *data)
{
	double	posx;
	double	posy;

	posx = data->player->posx + cos(data->player->dir) * (SPEED * 0.5);
	posy = data->player->posy + sin(data->player->dir) * (SPEED * 0.5);
	check_limit(data, posx, posy);
}

static void	move_down(t_data *data)
{
	double	posx;
	double	posy;

	posx = data->player->posx - cos(data->player->dir) * (SPEED * 0.5);
	posy = data->player->posy - sin(data->player->dir) * (SPEED * 0.5);
	check_limit(data, posx, posy);
}

static void	move_left(t_data *data)
{
	double	posx;
	double	posy;

	posx = data->player->posx - cos(data->player->dir + M_PI / 2)
		* (SPEED * 0.5);
	posy = data->player->posy - sin(data->player->dir + M_PI / 2)
		* (SPEED * 0.5);
	check_limit(data, posx, posy);
}

static void	move_right(t_data *data)
{
	double	posx;
	double	posy;

	posx = data->player->posx + cos(data->player->dir + M_PI / 2)
		* (SPEED * 0.5);
	posy = data->player->posy + sin(data->player->dir + M_PI / 2)
		* (SPEED * 0.5);
	check_limit(data, posx, posy);
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
