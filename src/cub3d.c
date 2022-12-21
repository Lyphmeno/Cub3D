/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:37:24 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/21 10:21:50 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdlib.h>

void	free_data(t_data *data)
{
	free(data->txr[NO]);
	free(data->txr[SO]);
	free(data->txr[WE]);
	free(data->txr[EA]);
	free(data->map.arr);
	free(data);
}

static void	init_data(t_data *data)
{
	data->txr[0] = NULL;
	data->txr[1] = NULL;
	data->txr[2] = NULL;
	data->txr[3] = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.px = -1;
	data->map.py = -1;
	data->map.player = -1;
	data->sky = -1;
	data->flr = -1;
}

int	main(int ac, char **av)
{
	t_data	*data;
	void	*mlx;

	if (ac != 2)
		return (print_err("Invalid number of arguments", -1));
	data = ft_calloc(sizeof(t_data), 1);
	init_data(data);
	if (mapfile_check(data, av[1]))
	{
		free(data);
		return (-1);
	}
	if (parsing_base(data))
	{
		free_data(data);
		return (-1);
	}
	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "CUB3D");
	mlx_loop(mlx);
	free_data(data);
	return (0);
}
