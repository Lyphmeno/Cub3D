/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:30:38 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/12 13:01:49 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>

int	fill_colors(char **color_arr)
{
	int red;
	int green;
	int blue;
	int	rgb;

	red = ft_atoi(color_arr[0]);
	green = ft_atoi(color_arr[1]);
	blue = ft_atoi(color_arr[2]);
	rgb = create_rgb(red, green, blue);
	return (rgb);
}

int	parse_colors(t_data *data, char *str, int x)
{
	char	**color_array;
	int	i;
	
	i = 0;
	color_array = ft_split(str, ",");
	if (!color_array || !color_array[0] || !color_array[1]
		|| !color_array[2] || color_array[3])
	{
		free(color_array);
		return (print_err("Wrong color entry", -1));
	}
	while (color_array[i] != NULL)
	{
		if (ft_atoi(color_array[i]) < 0 || ft_atoi(color_array[i]) > 255)
		{
			free(color_array);
			return (print_err("Color value impossible", -1));
		}
		i++;
	}
	if (!x)
		data->sky = fill_colors(color_array);
	else
		data->flr = fill_colors(color_array);
	free(color_array);
	return (0);
}
