/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:45:24 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/05/04 13:47:09 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

int		check_map_error(char **map)
{
	char	*line;
	char	last_case;
	char	last_no_floor;

	while (**map && ft_strlen(*map))
	{
		last_case = ' ';
		last_no_floor = ' ';
		line = *map;
		while (*line)
		{
			if (*line == ' ' && is_charset(last_case, "02NSEW")) // trou basique
				(printf("erreur de map avec line |%s| sur %c et %c\n", line, *line, last_case));
			if (is_charset(*line, " 1"))
				last_no_floor = *line;
			else if (last_no_floor == ' ')
				(printf("erreur de map avec line (%s) sur %c et %c\n", line, *line, last_case));
			last_case = *line;
			line++;
		}
		if (last_case == '0')
			(printf("erreur de map avec line {%s} sur %c et %c\n", line, *line, last_case));
		map++;
	}
	return (0);
}

int		parsing_map(char *line, t_maparam *maparam) // putting MAP from line to **map
{
	ft_strlcat(maparam->map[maparam->tmpheight], line, maparam->width);
	maparam->tmpheight++;
	return (0);
}

int		parsing_base(char *line, t_maparam *maparam) // Parse les arguments hors map
{
	char	**tmp; // Permet de stocker les valeur et type en attendant les checks
	int		validparam;
	int		fsize;
	int		i;

	tmp = ft_split(line, ' '); // On split pour les espaces
	fsize = nbr_of_words(line, ' ');
	validparam = 1;
	line = check_paramtype(line, tmp[0], maparam, &validparam);
	if (validparam == 1)
		check_paramvalue(tmp, maparam);
	i = -1;
	while (i++ < fsize)
		free(tmp[i]);
	free(tmp);
	return (0);
}

int		parsing_all(char *map, t_maparam *maparam) // Coeur du parsing
{
	char	*line;

	get_size(map, maparam); // On recup height et width avec un premier passage
	maparam->map = (char **)ft_newarray(maparam->width, maparam->height, sizeof(char)); // creation du tableau map
	if ((maparam->fd = open(map, O_RDONLY)) == -1) // Ouverture du fd
		return (-1);
	while (get_next_line(maparam->fd, &line)) // Commencement du parsing avec gnl
	{
		if (ft_strlen(line) != 0 && maparam->paramcount != 12 && is_map(line) != 2) // on parse les param de base hors map
			parsing_base(line, maparam);
		if (ft_strlen(line) != 0 && is_map(line) == 2)
		{
			if (maparam->paramcount != 12) // verification qu'il y a bien tous (et non plus) les params avant la map
			{
				printf("Error !! Invalid number of param !!\n");
				return (-1);
			}
			else
				parsing_map(line, maparam); // Parsing de la map
		}
		free(line);
		line = NULL;
	}
	fill_spaces(maparam);
	maparam->tmpheight = 0;
	while (maparam->tmpheight < maparam->height)
	{
	 	printf("map%d = |%s|\n", maparam->tmpheight, maparam->map[maparam->tmpheight]);
	 	maparam->tmpheight++;
	}
	//check_map_error(maparam->map);
	// maparam->tmpheight = 0;
	// while (maparam->tmpheight < maparam->height)
	// {
	//  	printf("map%d = |%s|\n", maparam->tmpheight, maparam->map[maparam->tmpheight]);
	//  	maparam->tmpheight++;
	// }
	// printf("lores * lares = %d * %d\nnopath = %s\nsopath = %s\nwepath = %s\neapath = %s\nopath = %s\n", maparam->lores, maparam->lares, maparam->nopath, maparam->sopath, maparam->wepath, maparam->eapath, maparam->spipath);
	// printf("fcolor = %d,%d,%d\n", maparam->fcolor[0], maparam->fcolor[1], maparam->fcolor[2]);
	// printf("ccolor = %d,%d,%d\n", maparam->ccolor[0], maparam->ccolor[1], maparam->ccolor[2]);
	// printf("COUNT = %d\n", maparam->paramcount);
	printf("Height = %d\nWidth = %d\n", maparam->height, maparam->width);
	return (0);
}
