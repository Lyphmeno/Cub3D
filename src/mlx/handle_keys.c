/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:18:54 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/22 11:29:32 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		escape(data);
	if (keycode == KUP)
		data->player->posy -= 5;
	if (keycode == KDOWN)
		data->player->posy += 5;
	if (keycode == KLEFT)
		data->player->posx -= 5;
	if (keycode == KRIGHT)
		data->player->posx += 5;
	return (0);
}
