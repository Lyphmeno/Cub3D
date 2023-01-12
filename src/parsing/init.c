/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:08:00 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/12 16:17:00 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	init_ray(t_data *data)
{
	data->ray = ft_calloc(sizeof(t_ray), 1);
	if (!data->ray)
		return (-1);
	data->ray->camera = 0;
	data->ray->hit = 0;
	data->ray->stepx = 0;
	data->ray->stepy = 0;
	data->ray->mapx = 0;
	data->ray->mapy = 0;
	data->ray->dirx = 0;
	data->ray->diry = 0;
	data->ray->sidistx = 0;
	data->ray->sidisty = 0;
	data->ray->deltax = 0;
	data->ray->deltay = 0;
	data->ray->wdist = 0;
	return (0);
}

static int	init_keys(t_data *data)
{
	data->keys = ft_calloc(sizeof(t_keys), 1);
	if (!data->keys)
		return (-1);
	data->keys->kup = 0;
	data->keys->kdown = 0;
	data->keys->kright = 0;
	data->keys->kleft = 0;
	data->keys->kdirr = 0;
	data->keys->kdirl = 0;
	data->keys->km = 0;
	return (0);
}

static int	init_player(t_data *data)
{
	data->player = ft_calloc(sizeof(t_pr), 1);
	if (!data->player)
		return (print_err("Player init failed", -1));
	data->player->player = -1;
	data->player->posx = -1;
	data->player->posy = -1;
	data->player->dir = -1;
	data->player->px = -1;
	data->player->py = -1;
	data->player->x = 0;
	data->player->y = 0;
	data->mousex = -1;
	return (0);
}

static int	init_map(t_data *data)
{
	data->map = ft_calloc(sizeof(t_map), 1);
	if (!data->map)
		return (print_err("Map init failed", -1));
	data->map->width = 0;
	data->map->height = 0;
	data->map->txr[0] = NULL;
	data->map->txr[1] = NULL;
	data->map->txr[2] = NULL;
	data->map->txr[3] = NULL;
	data->map->sky = -1;
	data->map->flr = -1;
	data->map->show = 1;
	data->map->size = 0.3;
	data->map->siz = 0;
	return (0);
}

int	init_data(t_data *data)
{
	if (init_player(data) || init_map(data)
		|| init_keys(data) || init_ray(data))
		return (-1);
	data->cub = ft_calloc(sizeof(t_cub), 1);
	if (!data->cub)
		return (-1);
	data->cub->lheight = 0;
	data->cub->sdraw = 0;
	data->cub->edraw = 0;
	return (0);
}
