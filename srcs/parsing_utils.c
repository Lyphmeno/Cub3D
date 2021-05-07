/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:46:40 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/05/04 13:47:33 by lyphmeno         ###   ########.fr       */
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

int		get_size(char *map, t_maparam *maparam) // Recuperation de la height et width de la map
{
	char	*tmpline;

	if ((maparam->fd = open(map, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(maparam->fd, &tmpline))
	{
		if (is_map(tmpline) == 2 && ft_strlen(tmpline) != 0)
		{
			if (ft_strlen(tmpline) > maparam->width) // Recuperation de la largeur
				maparam->width = ft_strlen(tmpline);
			maparam->height++; // Recuperation de la longueur
		}
		free(tmpline);
		tmpline = NULL;
	}
	maparam->height += 2;
	maparam->width++;
	maparam->tmpheight = 1;
	free(tmpline);
	close(maparam->fd);
	return (0);
}

void	fill_spaces(t_maparam *maparam) // fill map with space
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < maparam->height)
	{
		while (j < maparam->width - 1)
		{
			if (maparam->map[i][j] == '\0')
				maparam->map[i][j] = ' ';
			j++;
		}
		j = 0;
		i++;
	}
}