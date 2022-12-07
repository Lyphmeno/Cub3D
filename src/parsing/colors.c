/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:44:26 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/07 11:10:13 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_red(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}

int	get_green(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

int	get_blue(int rgb)
{
	return (rgb & 0xFF);
}

int	create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	parse_colors(t_data *data, char *str, int x)
{
	char	**color_array;
	int	i;
	
	i = 0;
	color_array = ft_split(str, ",");
	if (!color_array || !color_array[0] || !color_array[1]
		|| !color_array[2] || color_array[3])
		return (-1);
	while (color_array[i] != NULL)
	{
		if (ft_atoi(color_array[i]) < 0 || ft_atoi(color_array[i]) > 255)
			return (print_err("Color value impossible", -1));
		i++;
	}
	if (!x)
		data->sky = -1;
	else
		data->flr = -1;
	free(color_array);
	return (0);
}
