/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:20:36 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/06/10 11:35:58 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

int		check_color(char **tmp, t_maparam *param)
{
	int	i;
	char	**tmpcolor;

	i = -1;
	if (!tmp[1]) // Check pas assez de param
		return (-1);
	tmpcolor = ft_split(tmp[1], ',');
	if (tmp[2]) // Check param en trop
		param->paramcount += 1;
	if (!tmpcolor[0] || !tmpcolor[1] || !tmpcolor[2] || tmpcolor[3]) // Check si 3 couleurs ou plus
		return (-1);
	while (i++ < 2)
	{
		if (ft_atoi(tmpcolor[i]) >= 0 && ft_atoi(tmpcolor[i]) <= 255)
			param->paramcount += 1;
		else
			tmpcolor[i] = ft_strdup("0");
	}
	i = -1;
	if (param->paramtype == 'F')
		while (i++ < 2)
			param->fcolor[i] = ft_atoi(tmpcolor[i]);
	else
		while (i++ < 2)
			param->ccolor[i] = ft_atoi(tmpcolor[i]);
	i = -1;
	while (i++ < 2)
		free(tmpcolor[i]);
	free(tmpcolor);
	return (0);
}

int		check_path(char **tmp, t_maparam *param)
{
	char	*str;

	if (tmp[1])
	{
		str = ft_strdup(tmp[1]);
		param->paramcount += 1;
	}
	else
		str = ft_strdup("");
	if (param->paramtype == 'N')
		param->nopath = ft_strdup(str);
	if (param->paramtype == 'S')
		param->sopath = ft_strdup(str);
	if (param->paramtype == 'W')
		param->wepath = ft_strdup(str);
	if (param->paramtype == 'E')
		param->eapath = ft_strdup(str);
	if (param->paramtype == 'O')
		param->spipath = ft_strdup(str);
	if (tmp[2]) // Check si trop de trucs
		param->paramcount += 1;
	free(str);
	return (0);
}

int		check_res(char **tmp, t_maparam *param)
{
	if (tmp[1])
		param->lores = ft_atoi(tmp[1]);
	else
		param->lores = 0;
	if (tmp[2])
		param->lares = ft_atoi(tmp[2]);
	else
		param->lares = 0;
	if (param->lares > 0 && param->lores > 0)
		param->paramcount += 1;
	if (tmp[3]) // Check si trop de trucs
		param->paramcount += 1;
	return (0);
}

int		check_paramvalue(char **tmp, t_maparam *param)
{
	if (param->paramtype == 'R')
		check_res(tmp, param);
	if (is_charset(param->paramtype, "NSWEO"))
		check_path(tmp, param);
	if (is_charset(param->paramtype, "FC"))
		check_color(tmp, param);
	return (0);
}

char	*check_paramtype(char *line, char *tmp, t_maparam *param, int *validparam)
{
	*validparam = 1;
	if (ft_strncmp(tmp, "R", 1) == 0)
		param->paramtype = 'R';
	else if (ft_strncmp(tmp, "NO", 2) == 0)
		param->paramtype = 'N';
	else if (ft_strncmp(tmp, "SO", 2) == 0)
		param->paramtype = 'S';
	else if (ft_strncmp(tmp, "WE", 2) == 0)
		param->paramtype = 'W';
	else if (ft_strncmp(tmp, "EA", 2) == 0)
		param->paramtype = 'E';
	else if (ft_strncmp(tmp, "S", 1) == 0)
		param->paramtype = 'O';
	else if (ft_strncmp(tmp, "F", 1) == 0)
		param->paramtype = 'F';
	else if (ft_strncmp(tmp, "C", 1) == 0)
		param->paramtype = 'C';
	else
	{
		printf("Error !! Map param not valid !!\n");
		*validparam = 0;
	}
	return (line);
}