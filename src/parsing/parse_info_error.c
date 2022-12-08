/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:13:41 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/08 10:34:44 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	parse_info_double(t_data *data, int x)
{
	if (x == NO && data->txr[x])
		return (print_err("NORTH texture already exist", -1));
	if (x == SO && data->txr[x])
		return (print_err("SOUTH texture already exist", -1));
	if (x == WE && data->txr[x])
		return (print_err("WEST texture already exist", -1));
	if (x == EA && data->txr[x])
		return (print_err("EAST texture already exist", -1));
	if (x == SKY && data->sky != -1)
		return (print_err("SKY texture already exist", -1));
	if (x == FLR && data->flr != -1)
		return (print_err("FLOOR texture already exist", -1));
	return (0);
}

// Check if info doesn't already exist before filling (doubles not allowed) 
int fill_info(t_data *data, int x, char *info)
{
	if (parse_info_double(data, x))
		return (-1);
	if (x <= EA)
		data->txr[x] = ft_strdup(info);
	if (x == SKY)
		return (parse_colors(data, info, 0));
	if (x == FLR)
		return (parse_colors(data, info, 1));
	return (0);
}

int	parse_info_miss(t_data *data)
{
	if (!data->txr[0])
		return (print_err("Missing NORTH texture", -1));
	if (!data->txr[1])
		return (print_err("Missing SOUTH texture", -1));
	if (!data->txr[2])
		return (print_err("Missing WEST texture", -1));
	if (!data->txr[3])
		return (print_err("Missing EAST texture", -1));
	if (data->sky == -1)
		return (print_err("Missing SKY texture", -1));
	if (data->flr == -1)
		return (print_err("Missing FLOOR texture", -1));
	return (0);
}

