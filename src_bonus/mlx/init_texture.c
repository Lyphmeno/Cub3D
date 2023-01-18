/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:56:39 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/18 16:43:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

void	free_txr(t_data *data)
{
	if (data->cub->notx && data->cub->notx->img != NULL)
		mlx_destroy_image(data->mlx, data->cub->notx->img);
	if (data->cub->sotx && data->cub->sotx->img != NULL)
		mlx_destroy_image(data->mlx, data->cub->sotx->img);
	if (data->cub->eatx && data->cub->eatx->img != NULL)
		mlx_destroy_image(data->mlx, data->cub->eatx->img);
	if (data->cub->wetx && data->cub->wetx->img != NULL)
		mlx_destroy_image(data->mlx, data->cub->wetx->img);
}

static int	init_txr_file(t_data *data)
{
	data->cub->notx->img = mlx_xpm_file_to_image(data->mlx, data->map->txr[NO],
			&data->cub->notx->width, &data->cub->notx->height);
	data->cub->sotx->img = mlx_xpm_file_to_image(data->mlx, data->map->txr[SO],
			&data->cub->sotx->width, &data->cub->sotx->height);
	data->cub->eatx->img = mlx_xpm_file_to_image(data->mlx, data->map->txr[EA],
			&data->cub->eatx->width, &data->cub->eatx->height);
	data->cub->wetx->img = mlx_xpm_file_to_image(data->mlx, data->map->txr[WE],
			&data->cub->wetx->width, &data->cub->wetx->height);
	if (!data->cub->notx->img || !data->cub->sotx->img
		|| !data->cub->eatx->img || !data->cub->wetx->img)
		return (-1);
	return (0);
}

static int	init_txr_addr(t_data *data)
{
	data->cub->notx->addr = mlx_get_data_addr(data->cub->notx->img,
			&data->cub->notx->bpp, &data->cub->notx->length,
			&data->cub->notx->endian);
	data->cub->sotx->addr = mlx_get_data_addr(data->cub->sotx->img,
			&data->cub->sotx->bpp, &data->cub->sotx->length,
			&data->cub->sotx->endian);
	data->cub->eatx->addr = mlx_get_data_addr(data->cub->eatx->img,
			&data->cub->eatx->bpp, &data->cub->eatx->length,
			&data->cub->eatx->endian);
	data->cub->wetx->addr = mlx_get_data_addr(data->cub->wetx->img,
			&data->cub->wetx->bpp, &data->cub->wetx->length,
			&data->cub->wetx->endian);
	return (0);
}

int	init_txr(t_data *data)
{
	if (init_txr_file(data))
	{
		free_txr(data);
		return (-1);
	}
	if (init_txr_addr(data))
		return (-1);
	return (0);
}
