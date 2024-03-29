/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:30:19 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/24 15:10:31 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	parse_check_isfull(t_data *data)
{
	if (!data->map->txr[0])
		return (-1);
	if (!data->map->txr[1])
		return (-1);
	if (!data->map->txr[2])
		return (-1);
	if (!data->map->txr[3])
		return (-1);
	if (data->map->sky == -1)
		return (-1);
	if (data->map->flr == -1)
		return (-1);
	return (0);
}

static int	parse_fill_info(t_data *data, char **arr)
{
	if (!arr)
		return (0);
	if (!arr[0] || !arr[1] || arr[2])
		return (print_err("Wrong entry", -1));
	if (!ft_strncmp(arr[0], "NO", ft_strlen(arr[0])))
		return (fill_info(data, NO, arr[1]));
	else if (!ft_strncmp(arr[0], "SO", ft_strlen(arr[0])))
		return (fill_info(data, SO, arr[1]));
	else if (!ft_strncmp(arr[0], "WE", ft_strlen(arr[0])))
		return (fill_info(data, WE, arr[1]));
	else if (!ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
		return (fill_info(data, EA, arr[1]));
	else if (!ft_strncmp(arr[0], "C", ft_strlen(arr[0])))
		return (fill_info(data, SKY, arr[1]));
	else if (!ft_strncmp(arr[0], "F", ft_strlen(arr[0])))
		return (fill_info(data, FLR, arr[1]));
	else
		return (print_err("Wrong param", -1));
	return (0);
}

static int	get_map(t_data *data, char *tmp_line)
{
	char	*tmp_map;

	tmp_map = ft_strdup("");
	while (!ft_strncmp("\n", tmp_line, 1) || !tmp_line)
	{
		free(tmp_line);
		tmp_line = get_next_line(data->fd);
	}
	while (tmp_line != NULL)
	{
		if (!ft_strncmp("\n", tmp_line, 1))
		{
			free(tmp_line);
			free(tmp_map);
			close(data->fd);
			return (print_err("Empty line or wrong line after info", -1));
		}
		tmp_map = ft_strfjoin(tmp_map, tmp_line, 0);
		tmp_line = get_next_line(data->fd);
	}
	data->map->arr = ft_split(tmp_map, "\n");
	free(tmp_line);
	free(tmp_map);
	close(data->fd);
	return (parse_info_miss(data));
}

static int	parse_info(t_data *data)
{
	int		ret;
	char	*tmp_line;
	char	**tmp_array;

	ret = 0;
	tmp_line = get_next_line(data->fd);
	while (tmp_line != NULL && parse_check_isfull(data))
	{
		if (ft_strncmp("\n", tmp_line, 1))
			if (parse_split_info(&tmp_line))
				return (print_err("Wrong entry", -1));
		tmp_array = ft_split_whitespaces(tmp_line);
		free(tmp_line);
		if (parse_fill_info(data, tmp_array))
		{
			free(tmp_array);
			return (-1);
		}
		tmp_line = get_next_line(data->fd);
		free(tmp_array);
		ret++;
	}
	if ((parse_check_isfull(data)) || get_map(data, tmp_line))
		return (-1);
	return (parse_info_miss(data));
}

int	parsing_base(t_data *data)
{
	int	x;
	int	y;

	if (parse_info(data))
		return (-1);
	if (parse_map(data))
		return (-1);
	x = 0;
	while (x < data->map->height)
	{
		y = 0;
		while (y < data->map->width)
		{
			if (!is_charset(data->map->arr[x][y], "NSEW10"))
				data->map->arr[x][y]= '1';
			y++;
		}
		x++;
	}
	return (0);
}
