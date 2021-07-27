/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:45:24 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/06/10 11:41:28 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3dlib/cub3dlib.h"

int		parsing_map(char *line, t_maparam *param) // putting MAP from line to **map
{
	ft_strlcat(param->map[param->tmpheight], line, param->width);
	param->tmpheight++;
	return (0);
}

int		parsing_base(char *line, t_maparam *param) // Parse les arguments hors map
{
	char	**tmp; // Permet de stocker les valeur et type en attendant les checks
	int		validparam;
	int		fsize;
	int		i;

	tmp = ft_split(line, ' '); // On split pour les espaces
	fsize = nbr_of_words(line, ' ');
	validparam = 1;
	line = check_paramtype(line, tmp[0], param, &validparam);
	if (validparam == 1)
		check_paramvalue(tmp, param);
	i = -1;
	while (i++ < fsize)
		free(tmp[i]);
	free(tmp);
	return (0);
}

int		parsing_all(char *map, t_maparam *param) // Coeur du parsing
{
	char	*line;

	get_size(map, param); // On recup height et width avec un premier passage
	param->map = (char **)ft_newarray(param->width, param->height, sizeof(char)); // creation du tableau map
	if ((param->fd = open(map, O_RDONLY)) == -1) // Ouverture du fd
		return (-1);
	while (get_next_line(param->fd, &line)) // Commencement du parsing avec gnl
	{
		if (ft_strlen(line) != 0 && param->paramcount != 12 && is_map(line) != 2) // on parse les param de base hors map
			parsing_base(line, param);
		if (ft_strlen(line) != 0 && is_map(line) == 2)
		{
			if (param->paramcount != 12) // verification qu'il y a bien tous (et non plus) les params avant la map
			{
				printf("Error !! Invalid number of param !!\n");
				return (-1);
			}
			else
				parsing_map(line, param); // Parsing de la map
		}
		free(line);
		line = NULL;
	}
	fill_spaces(param, '\0', ' ');
	check_horizontal(param->map, param->height);
	check_vertical(param);
	fill_spaces(param, ' ', '1');
	return (0);
}
