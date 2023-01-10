/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:45:17 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/10 15:04:36 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_ray(t_data *data)
{
	data->player->rayc = -1 * (FOV / 2);
	while (data->player->rayc <= FOV / 2)
	{
		double cameraX = 2/ FOV - 1; //x-coordinate in camera space
		double rayDirX = (cos(data->player->dir + data->player->rayc)) * cameraX;
		double rayDirY = (sin(data->player->dir + data->player->rayc)) * cameraX;

		//which box of the map we're in
		int mapX = (int)data->player->posx;
		int mapY = (int)data->player->posy;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->player->posx - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->player->posx) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->player->posy - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->player->posy) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (data->map->arr[mapY][mapX] == '1')
				hit = 1;
		}
		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		if (data->map->show)
			draw_player(data, perpWallDist);
		data->player->rayc += 0.01;
	}
}
