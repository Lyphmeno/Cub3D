/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:30:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/20 12:22:37 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	parse_check_isfull(t_data *data)
{
	if (!data->txr[0])
		return (-1);
	if (!data->txr[1])
		return (-1);
	if (!data->txr[2])
		return (-1);
	if (!data->txr[3])
		return (-1);
	if (data->sky == -1)
		return (-1);
	if (data->flr == -1)
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
	while (tmp_line != NULL)
	{
		tmp_map = ft_strfjoin(tmp_map, tmp_line, 0);
		tmp_line = get_next_line(data->fd);
	}
	printf("data.txr[0] = %s\n", data->txr[0]);
	printf("data.txr[1] = %s\n", data->txr[1]);
	printf("data.txr[2] = %s\n", data->txr[2]);
	printf("data.txr[3] = %s\n", data->txr[3]);
	printf("data.sky = %d\n", data->sky);
	printf("data.flr = %d\n", data->flr);
	data->map.arr = ft_split(tmp_map, "\n");
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
	if (get_map(data, tmp_line))
		return (print_err("Impossible to get the map", -1));
	return (parse_info_miss(data));
}

int	parsing_base(t_data *data) // Base of the parsing
{
	/* My way to do the parsing :
		Txt and Colors : 
		- Skip empty lines ✅ 
		- Check first word to see what it is (NO, SO...) ✅ 
		- Check that I got all 6 values before the map is here ✅ 
		- Send right errors if values ain't all here ✅ 
		If text not valid just don't check map !
		Text cannot be in/or after the map
		Map :
		- Check that there is only MAPSYM
		- Check that the map is well closed
		- Might fill spaces with 1 to avoid issues
		- Check for spaces that are next to 0 (all four directions)
	*/
	if (parse_info(data))
		return (-1);
	if (parse_map(data))
		return (-1);
	return (0);
}
