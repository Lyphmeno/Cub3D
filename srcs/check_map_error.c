/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:47:43 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/06/10 11:42:15 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

void	free_r(t_maparam *rotate)
{
	free(rotate->map);
	free(rotate->ccolor);
	free(rotate->fcolor);
	free(rotate->nopath);
	free(rotate->spipath);
	free(rotate->sopath);
	free(rotate->eapath);
	free(rotate->wepath);
	free(rotate);
}

int		map_errors(char *error)
{
    if (!(ft_strcmp("space", error)))
		printf("Error\nMap not valid\n");
	return (-1);
}

int		check_horizontal(char **map, int count)
{
	char	*line;
	char	last_case;
	char	last_no_floor;
	
	while (*map && count != 0)
	{
		last_case = ' ';
		last_no_floor = ' ';
		line = *map;
		while (*line)
		{
			if (*line == ' ' && is_charset(last_case, "02NSEW")) // trou basique
				return (map_errors("space"));
			if (is_charset(*line, " 1"))
				last_no_floor = *line;
			else if (last_no_floor == ' ')
				return (map_errors("space"));
			last_case = *line;
			line++;
		}
		if (last_case == '0')
				return (map_errors("space"));
		map++;
		count--;
	}
	return (0);
}

int		init_new_map(t_maparam *param, t_maparam *rotate)
{
	rotate->fcolor = (int *)ft_calloc(sizeof(int *), 3);
	rotate->ccolor = (int *)ft_calloc(sizeof(int *), 3);
	ft_memset(rotate, 0, sizeof(rotate));
	rotate->map = (char **)ft_newarray(param->height + 1, param->width, sizeof(char));
	return (0);
}

int		check_vertical(t_maparam *param)
{
	int			x;
	int			y;
	t_maparam	*rotate;

	if (!(rotate = (t_maparam *)ft_calloc(1, sizeof(t_maparam))))
		return (-1);
	init_new_map(param, rotate);
	y = -1;
	while (++y < param->height)
	{
		x = -1;
		while (++x < param->width)
		{
			if (is_charset(param->map[y][x], "NSEW"))
			{
				param->player_x = x;
				param->player_y = y;
				param->spawn = param->map[y][x];
			}
			rotate->map[param->width - x - 1][y] = param->map[y][x] ;
		}
	}
	if (check_horizontal(rotate->map, rotate->width) == -1)
	{
		free_r(rotate);
		return (map_errors("space"));
	}
	free_r(rotate);
	return (0);
}