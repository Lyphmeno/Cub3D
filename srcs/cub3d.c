/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:50:02 by hlevi             #+#    #+#             */
/*   Updated: 2021/05/07 11:37:22 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

int		main(int argc, char **argv)
{
	t_maparam	*maparam;
	// void		*mlx;
	// void		*mlx_win;

	(void)argc;
	maparam = (t_maparam *)ft_calloc(sizeof(t_maparam), 1);
	maparam->fcolor = (int *)ft_calloc(sizeof(int *), 3);
	maparam->ccolor = (int *)ft_calloc(sizeof(int *), 3);
	ft_memset(maparam, 0, sizeof(maparam));
	//check argument
	parsing_all(argv[1], maparam);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1, 1, "Hello world!");
	// mlx_loop(mlx);
	// (void)mlx_win;
	free(maparam->map);
	free(maparam->ccolor);
	free(maparam->fcolor);
	free(maparam->nopath);
	free(maparam->spipath);
	free(maparam->sopath);
	free(maparam->eapath);
	free(maparam->wepath);
	free(maparam);
	return (0);
}
