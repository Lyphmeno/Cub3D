/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:50:02 by hlevi             #+#    #+#             */
/*   Updated: 2021/06/10 12:09:57 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

void    init_maparam(t_maparam *param)
{
    param = (t_maparam *)ft_calloc(sizeof(t_maparam), 1);
	param->fcolor = (int *)ft_calloc(sizeof(int *), 3);
	param->ccolor = (int *)ft_calloc(sizeof(int *), 3);
	ft_memset(param, 0, sizeof(param));
}

void	print_info(t_maparam *param, t_data *game)
{
	printf("Resolution = %d * %d\nnopath = %s\nsopath = %s\nwepath = %s\neapath = %s\nopath = %s\n", param->lores, param->lares, param->nopath, param->sopath, param->wepath, param->eapath, param->spipath);
	printf("fcolor = %d,%d,%d\n", param->fcolor[0], param->fcolor[1], param->fcolor[2]);
	printf("ccolor = %d,%d,%d\n", param->ccolor[0], param->ccolor[1], param->ccolor[2]);
	printf("Height = %d\nWidth = %d\n", param->height, param->width);
	printf("ANGLE = %c \n", param->spawn);
	param->tmpheight = 0;
	while (param->tmpheight < param->height)
	{
	 	printf("map = |%s|\n", param->map[param->tmpheight]);
	 	param->tmpheight++;
	}
	printf("block = %d \n", game->block);
	printf("FOV = %d \n", game->fov);
	printf("POS.x = %d \n", game->player_x);
	printf("POS.y = %d \n", game->player_y);
}

void	free_m(t_maparam *param)
{
	free(param->map);
	free(param->ccolor);
	free(param->fcolor);
	free(param->nopath);
	free(param->spipath);
	free(param->sopath);
	free(param->eapath);
	free(param->wepath);
	free(param);
}

int		main(int argc, char **argv)
{
	t_maparam	*param;
	t_data		*game;
	void		*mlx;
	void		*mlx_win;

	(void)argc;
	game = NULL;
	//init_maparam(param);
	param = (t_maparam *)ft_calloc(sizeof(t_maparam), 1);
	param->fcolor = (int *)ft_calloc(sizeof(int *), 3);
	param->ccolor = (int *)ft_calloc(sizeof(int *), 3);
	ft_memset(param, 0, sizeof(param));
	// initparam
	parsing_all(argv[1], param);
	game = (t_data *)ft_calloc(sizeof(t_data), 1);
	ft_memset(game, 0, sizeof(game));
	init_data(game, param);
	print_info(param, game);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, param->lores, param->lares, "Cub3D");
	mlx_loop(mlx);
	(void)mlx_win;
	free_m(param);
	return (0);
}
