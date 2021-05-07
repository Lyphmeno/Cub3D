/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:20:36 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/05/07 11:42:37 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

int		check_color(char **tmp, t_maparam *maparam)
{
	int	i;
	char	**tmpcolor;

	i = -1;
	if (!tmp[1]) // Check pas assez de param
		return (-1);
	tmpcolor = ft_split(tmp[1], ',');
	if (tmp[2]) // Check param en trop
		maparam->paramcount += 1;
	if (!tmpcolor[0] || !tmpcolor[1] || !tmpcolor[2] || tmpcolor[3]) // Check si 3 couleurs ou plus
		return (-1);
	while (i++ < 2)
	{
		if (ft_atoi(tmpcolor[i]) >= 0 && ft_atoi(tmpcolor[i]) <= 255)
			maparam->paramcount += 1;
		else
			tmpcolor[i] = ft_strdup("0");
	}
	i = -1;
	if (maparam->paramtype == 'F')
		while (i++ < 2)
			maparam->fcolor[i] = ft_atoi(tmpcolor[i]);
	else
		while (i++ < 2)
			maparam->ccolor[i] = ft_atoi(tmpcolor[i]);
	i = -1;
	while (i++ < 2)
		free(tmpcolor[i]);
	free(tmpcolor);
	return (0);
}

int		check_path(char **tmp, t_maparam *maparam)
{
	char	*str;

	if (tmp[1])
	{
		str = ft_strdup(tmp[1]);
		maparam->paramcount += 1;
	}
	else
		str = ft_strdup("");
	if (maparam->paramtype == 'N')
		maparam->nopath = ft_strdup(str);
	if (maparam->paramtype == 'S')
		maparam->sopath = ft_strdup(str);
	if (maparam->paramtype == 'W')
		maparam->wepath = ft_strdup(str);
	if (maparam->paramtype == 'E')
		maparam->eapath = ft_strdup(str);
	if (maparam->paramtype == 'O')
		maparam->spipath = ft_strdup(str);
	if (tmp[2]) // Check si trop de trucs
		maparam->paramcount += 1;
	free(str);
	return (0);
}

int		check_res(char **tmp, t_maparam *maparam)
{
	if (tmp[1])
		maparam->lores = ft_atoi(tmp[1]);
	else
		maparam->lores = 0;
	if (tmp[2])
		maparam->lares = ft_atoi(tmp[2]);
	else
		maparam->lares = 0;
	if (maparam->lares > 0 && maparam->lores > 0)
		maparam->paramcount += 1;
	if (tmp[3]) // Check si trop de trucs
		maparam->paramcount += 1;
	return (0);
}

int		check_paramvalue(char **tmp, t_maparam *maparam)
{
	if (maparam->paramtype == 'R')
		check_res(tmp, maparam);
	if (is_charset(maparam->paramtype, "NSWEO"))
		check_path(tmp, maparam);
	if (is_charset(maparam->paramtype, "FC"))
		check_color(tmp, maparam);
	return (0);
}

char	*check_paramtype(char *line, char *tmp, t_maparam *maparam, int *validparam)
{
	*validparam = 1;
	if (ft_strncmp(tmp, "R", 1) == 0)
		maparam->paramtype = 'R';
	else if (ft_strncmp(tmp, "NO", 2) == 0)
		maparam->paramtype = 'N';
	else if (ft_strncmp(tmp, "SO", 2) == 0)
		maparam->paramtype = 'S';
	else if (ft_strncmp(tmp, "WE", 2) == 0)
		maparam->paramtype = 'W';
	else if (ft_strncmp(tmp, "EA", 2) == 0)
		maparam->paramtype = 'E';
	else if (ft_strncmp(tmp, "S", 1) == 0)
		maparam->paramtype = 'O';
	else if (ft_strncmp(tmp, "F", 1) == 0)
		maparam->paramtype = 'F';
	else if (ft_strncmp(tmp, "C", 1) == 0)
		maparam->paramtype = 'C';
	else
	{
		printf("Error !! Map param not valid !!\n");
		*validparam = 0;
	}
	return (line);
}