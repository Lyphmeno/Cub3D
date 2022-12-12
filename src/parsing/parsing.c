/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:30:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/12 09:20:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	parse_check_isfull(t_data *data)
{
	if (!data->txr[0])
		return (-1);
	if (!data->txr[1])
		return (-1);
	if (!data->txr[2])
		return (-1);
	if (!data->txr[3])
		return (-1);
	if (data->sky == -1)
		return (-1);
	if (data->flr == -1)
		return (-1);
	return (0);
}

static int	parse_fill_info(t_data *data, char **arr)
{
	if (!arr)
		return (0);
	if (!arr[0] || !arr[1] || arr[2]) // I might want to make a function that check weather a tab as n number of row ??
		return (print_err("Wrong entry", -1)); // Need to add specific error msg (Wrong entry ??)
	if (!ft_strncmp(arr[0], "NO", ft_strlen(arr[0])))
		return (fill_info(data, NO, arr[1]));	
	else if (!ft_strncmp(arr[0], "SO", ft_strlen(arr[0])))
		return (fill_info(data, SO, arr[1]));
	else if (!ft_strncmp(arr[0], "WE", ft_strlen(arr[0])))
		return (fill_info(data, WE, arr[1]));
	else if (!ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
		return (fill_info(data, EA, arr[1]));
	else if (!ft_strncmp(arr[0], "C", ft_strlen(arr[0])))
		return (fill_info(data, SKY, arr[1]));
	else if (!ft_strncmp(arr[0], "F", ft_strlen(arr[0])))
		return (fill_info(data, FLR, arr[1]));
	else
		return (print_err("Wrong entry", -1));
	return (0);
}

static int	parse_info(t_data *data) // Parsing of the text above the map
{
	char	*tmp_line;
	char	*tmp_linecpy;
	char	**tmp_array;

	tmp_line = get_next_line(data->fd);
	/* Not so sure about parse_check_isfulll, might cause some issues 
	if the map is full but still contains double params or some stuff*/
	while (tmp_line != NULL && parse_check_isfull(data))
	{	
		tmp_array = ft_split_whitespaces(tmp_line);
		free(tmp_line);
		if (parse_fill_info(data, tmp_array))
		{
			free(tmp_array);
			return (-1);
		}
		tmp_line = get_next_line(data->fd);
		free(tmp_array);
	}
	tmp_linecpy = ft_strdup("");
	printf("data.txr[0] = %s\n", data->txr[0]);
	printf("data.txr[1] = %s\n", data->txr[1]);
	printf("data.txr[2] = %s\n", data->txr[2]);
	printf("data.txr[3] = %s\n", data->txr[3]);
	printf("data.sky = %d\n", data->sky);
	printf("data.flr = %d\n", data->flr);
	free(tmp_line);
	free(tmp_linecpy);
	close(data->fd);
	return (parse_info_miss(data));
}

int	parsing_base(t_data *data) // Base of the parsing
{
	/* My way to do the parsing :
		Txt and Colors : 
		- Skip empty lines ✅ 
		- Check first word to see what it is (NO, SO...) ✅ 
		- Check that I got all 6 values before the map is here ✅ 
		- Send right errors if values ain't all here ✅ 
		- I just need to make a new gnl 
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
