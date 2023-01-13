/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:37:24 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/13 11:39:42 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_data(t_data *data)
{
	free(data->map->txr[NO]);
	free(data->map->txr[SO]);
	free(data->map->txr[WE]);
	free(data->map->txr[EA]);
	free(data->player);
	free(data->map->arr);
	free(data->map);
	free(data->mlx);
	free(data->img);
	free(data->keys);
	free(data->ray);
	free(data->cub);
	free(data);
}

static int	parse_all(t_data *data, int ac, char *path)
{
	if (ac != 2)
		return (print_err("Invalid number of arguments", -1));
	if (mapfile_check(data, path))
	{
		free_data(data);
		return (-1);
	}
	if (parsing_base(data))
	{
		free_data(data);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (print_err("Data init failed", -1));
	if (init_data(data))
	{
		free_data(data);
		return (print_err("Data init failed", -1));
	}
	if (parse_all(data, ac, av[1]))
		return (-1);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WINW, WINH, "CUB3D");
	data->img = ft_calloc(sizeof(t_img), 1);
	image_loop(data);
	mlx_hook(data->mlx_win, 3, 1L << 1, release_key, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key, data);
	mlx_hook(data->mlx_win, 33, 1L << 17, escape, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse, data);
	mlx_loop_hook(data->mlx, image_loop, data);
	mlx_loop(data->mlx);
	return (0);
}
