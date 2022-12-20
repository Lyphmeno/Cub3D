/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:30:38 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/20 15:00:37 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>

int	fill_colors(char **color_arr)
{
	int	red;
	int	green;
	int	blue;
	int	rgb;

	red = ft_atoi(color_arr[0]);
	green = ft_atoi(color_arr[1]);
	blue = ft_atoi(color_arr[2]);
	rgb = create_rgb(red, green, blue);
	return (rgb);
}

int	parse_colors(t_data *data, char *str, int x)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(str, ",");
	if (!arr || !arr[0] || !arr[1] || !arr[2] || arr[3])
	{
		free(arr);
		return (print_err("Wrong color entry", -1));
	}
	while (arr[i] != NULL)
	{
		if (ft_atoi(arr[i]) < 0 || ft_atoi(arr[i]) > 255)
		{
			free(arr);
			return (print_err("Color value impossible", -1));
		}
		i++;
	}
	if (!x)
		data->sky = fill_colors(arr);
	else
		data->flr = fill_colors(arr);
	free(arr);
	return (0);
}
