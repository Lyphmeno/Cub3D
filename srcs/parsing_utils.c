/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:46:40 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/06/10 11:35:41 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

int		is_map(char *line) // Fonction qui check si map ou non
{
	while (*line)
		if (!(is_charset(*line++, " 012NSEW")))
			return (-1);
	return (2);
}

int		get_size(char *map, t_maparam *param) // Recuperation de la height et width de la map
{
	char	*tmpline;

	if ((param->fd = open(map, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(param->fd, &tmpline))
	{
		if (is_map(tmpline) == 2 && ft_strlen(tmpline) != 0)
		{
			if (ft_strlen(tmpline) > param->width) // Recuperation de la largeur
				param->width = ft_strlen(tmpline);
			param->height++; // Recuperation de la longueur
		}
		free(tmpline);
		tmpline = NULL;
	}
	param->height += 2;
	param->width += 2;
	param->tmpheight = 1;
	free(tmpline);
	close(param->fd);
	return (0);
}

void	fill_spaces(t_maparam *param, char c, char d) // fill map with space
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < param->height)
	{
		while (j < param->width - 1)
		{
			if (param->map[i][j] == c)
				param->map[i][j] = d;
			j++;
		}
		j = 0;
		i++;
	}
}