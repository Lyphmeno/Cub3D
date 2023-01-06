/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:18:54 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/05 12:47:01 by hlevi            ###   ########.fr       */
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
	int		delta_x;
    double	speed;

    (void)y;
    speed = 0.02;
    delta_x = x - data->mousex;
    data->player->dir += delta_x * speed;
    data->mousex = x;
    return 0;

}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		escape(data);
	if (keycode == 65365)
		if (data->map->size <= 0.5)
			data->map->size += 0.05;
	if (keycode == 65366)
		if (data->map->size >= 0.2)
			data->map->size -= 0.05;
	handle_press(keycode, data);
	return (0);
}
