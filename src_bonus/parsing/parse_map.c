/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:37:27 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/18 16:34:27 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

static int	parse_map_char(t_data *data, int i, int j)
{
	while (data->map->arr[i])
	{
		j = 0;
		while (data->map->arr[i][j])
		{
			if (!is_charset(data->map->arr[i][j], MAPSYM))
				return (print_err("Inavlid char on map", -1));
			if (is_charset(data->map->arr[i][j], MAPP))
			{
				data->player->posx = j + 0.5;
				data->player->posy = i + 0.5;
				data->player->player++;
				data->player->dir = data->map->arr[i][j];
			}
			j++;
		}
		if (data->map->width < j)
			data->map->width = j;
		i++;
	}
	data->map->height = i;
	return (0);
}

static int	parse_map_zero(t_data *data, int i, int j)
{
	if (j == 0 || !data->map->arr[i][j + 1])
		return (-1);
	if (data->map->arr[i][j - 1] == ' '
		|| data->map->arr[i][j + 1] == ' ')
		return (-1);
	if (!data->map->arr[i + 1] || data->map->arr[i + 1][j] == ' ')
		return (-1);
	if (i > 0 && data->map->arr[i - 1][j] == ' ')
		return (-1);
	if (!data->map->arr[i - 1][j - 1] || data->map->arr[i - 1][j - 1] == ' ')
		return (-1);
	if (!data->map->arr[i - 1][j + 1] || data->map->arr[i - 1][j + 1] == ' ')
		return (-1);
	if (!data->map->arr[i + 1][j - 1] || data->map->arr[i + 1][j - 1] == ' ')
		return (-1);
	if (!data->map->arr[i + 1][j + 1] || data->map->arr[i + 1][j + 1] == ' ')
		return (-1);
	return (0);
}

static int	parse_map_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->arr[i])
	{
		j = 0;
		while (data->map->arr[i][j])
		{
			if (is_charset(data->map->arr[i][j], "NSEW0"))
				if (parse_map_zero(data, i, j))
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	get_dir(t_data *data)
{
	if (data->player->dir == 'N')
		data->player->dir = -M_PI / 2;
	if (data->player->dir == 'S')
		data->player->dir = M_PI / 2;
	if (data->player->dir == 'E')
		data->player->dir = 0;
	if (data->player->dir == 'W')
		data->player->dir = M_PI;
}

int	parse_map(t_data *data)
{
	if (parse_map_char(data, 0, 0))
		return (-1);
	if (data->map->width < 3 || data->map->height < 3)
		return (print_err("Map too small", -1));
	if (data->player->posx < 0 || data->player->posy < 0)
		return (print_err("Map has no player spawn", -1));
	if (data->player->player)
		return (print_err("Map can only have a single player spawn", -1));
	if (parse_map_close(data))
		return (print_err("Map not closed", -1));
	get_dir(data);
	data->map->siz = (double)WINH
		/ data->map->height * data->map->size;
	data->player->x = data->player->posx
		* data->map->siz + data->map->siz / (double)2;
	data->player->y = data->player->posy
		* data->map->siz + data->map->siz / (double)2;
	return (0);
}
