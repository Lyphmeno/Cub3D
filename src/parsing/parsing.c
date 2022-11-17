/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:30:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/17 18:30:07 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_fill_info(t_data *data, char **arr)
{
	if (!arr || !arr[0])
		return (0);
	if (!ft_strncmp(arr[0], "NO", ft_strlen(arr[0]))
		|| !ft_strncmp(arr[0], "SO", ft_strlen(arr[0]))
		|| !ft_strncmp(arr[0], "WE", ft_strlen(arr[0]))
		|| !ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
	{
		if (!ft_strncmp(arr[0], "NO", ft_strlen(arr[0])))
			data->txr[NO] = ft_strdup(arr[1]);
		else if (!ft_strncmp(arr[0], "SO", ft_strlen(arr[0])))
			data->txr[SO] = ft_strdup(arr[1]);
		else if (!ft_strncmp(arr[0], "WE", ft_strlen(arr[0])))
			data->txr[WE] = ft_strdup(arr[1]);
		else if (!ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
			data->txr[EA] = ft_strdup(arr[1]);
	}
	return (0);
}

int	parse_info(t_data *data) // Parsing of the text above the map
{
	char	*tmp_line;
	char	**tmp_array;

	tmp_line = get_next_line(data->fd);
	while (tmp_line != NULL)
	{	
		tmp_array = ft_split(tmp_line);
		free(tmp_line);
		if (parse_fill_info(data, tmp_array))
		{
			free(tmp_array);
			return (-1);
		}
		tmp_line = get_next_line(data->fd);
		free(tmp_array);
	}
	printf("data.txr = %s\n", data->txr[0]);
	printf("data.txr = %s\n", data->txr[1]);
	printf("data.txr = %s\n", data->txr[2]);
	printf("data.txr = %s\n", data->txr[3]);
	return (0);
}

int	parsing_base(t_data *data) // Base of the parsing
{
	/* My way to do the parsing :
		Txt :
		- Skip empty lines
		- Check first word to see what it is (NO, SO...)
		- Use spaces as dlmtr to find values if not then comma
		- Check that I got all 6 values before the map is here
		- Send right errors iof values ain't all here
		If text not valid just don't check map !
		Text cannot be in/or after the map
		Map :
		- Check that there is only "10" and only on of "NSEW"
		- Check that the map is well closed
		- Might fill spaces with 1 to avoid issues
		- Check for spaces that are next to 0 (all four directions)
	*/
	if (parse_info(data))
		return (-1);
	return (0);
}
