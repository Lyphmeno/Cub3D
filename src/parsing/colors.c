/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:44:26 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/07 11:31:13 by hlevi            ###   ########.fr       */
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
