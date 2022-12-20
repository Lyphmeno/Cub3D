/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:37:27 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/20 13:07:53 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_charset(char c, char *str)
{
	while (*str)
		if (c == *str++)
			return (1);
	return (0);
}

static int	parse_map_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.arr[i])
	{
		j = 0;
		while (data->map.arr[i][j])
		{
			if (!is_charset(data->map.arr[i][j], MAPSYM))
				return (print_err("Inavlid char on map", -1));
			if (is_charset(data->map.arr[i][j], MAPP))
			{
				data->map.px = i;
				data->map.py = j;
				data->map.player++;
			}
			j++;
		}
		if (data->map.width < j)
			data->map.width = j;
		i++;
	}
	data->map.height = i;
	return (0);
}

static int	parse_map_zero(t_data *data, int i, int j)
{
	if (j == 0 || !data->map.arr[i][j + 1])
		return (-1);
	if (data->map.arr[i][j - 1] == ' '
		|| data->map.arr[i][j + 1] == ' ')
		return (-1);
	if (!data->map.arr[i + 1] || data->map.arr[i + 1][j] == ' ')
		return (-1);
	if (i > 0 && data->map.arr[i - 1][j] == ' ')
		return (-1);
	if (!data->map.arr[i - 1][j - 1] || data->map.arr[i - 1][j - 1] == ' ')
		return (-1);
	if (!data->map.arr[i - 1][j + 1] || data->map.arr[i - 1][j + 1] == ' ')
		return (-1);
	if (!data->map.arr[i + 1][j - 1] || data->map.arr[i + 1][j - 1] == ' ')
		return (-1);
	if (!data->map.arr[i + 1][j + 1] || data->map.arr[i + 1][j + 1] == ' ')
		return (-1);
	return (0);
}

static int	parse_map_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.arr[i])
	{
		j = 0;
		while (data->map.arr[i][j])
		{
			if (is_charset(data->map.arr[i][j], "NSEW0"))
				if (parse_map_zero(data, i, j))
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_map(t_data *data)
{
	if (parse_map_char(data))
		return (-1);
	if (data->map.width < 3 || data->map.height < 3)
		return (print_err("Map too small", -1));
	if (data->map.px < 0 || data->map.py < 0)
		return (print_err("Map has no player spawn", -1));
	if (data->map.player)
		return (print_err("Map can only have a single player spawn", -1));
	if (parse_map_close(data))
		return (print_err("Map not closed", -1));
	printf("h = %d\nw = %d\n", data->map.height, data->map.width);
	printf("px = %d\npy = %d\n", data->map.px, data->map.py);
	return (0);
}
