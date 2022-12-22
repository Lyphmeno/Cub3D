/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:18:54 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/22 14:40:15 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#define KUP 119
#define KDOWN	115
#define KLEFT	97
#define KRIGHT	100

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		escape(data);
	if (keycode == KUP)
		data->player->posy -= 1;
	if (keycode == KDOWN)
		data->player->posy += 1;
	if (keycode == KLEFT)
		data->player->posx -= 1;
	if (keycode == KRIGHT)
		data->player->posx += 1;
	return (0);
}
