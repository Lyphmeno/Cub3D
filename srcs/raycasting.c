/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:26:54 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/06/10 12:09:59 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

void    init_data(t_data *game, t_maparam *param)
{
    game->block = 64;
    game->fov = 60;
    game->player_x = (param->player_x * 64 + 32);
    game->player_y = (param->player_y * 64 + 32);
}