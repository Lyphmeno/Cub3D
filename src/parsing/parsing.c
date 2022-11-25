/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:30:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/18 17:50:55 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_check_info(t_data *data)
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

/*
I should replace parse_check_isfull function with a var that will tell me if
one of my param is in double in my file, then the program will return and print an error msg
*/

int	parse_check_isfull(t_data *data)
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

/*
int	parse_colors(t_data *data, char *str, int x) x will tell me if i need to fill sky or floor in struct
{
	char	**color_array:
	int	i;
	
	i = 0;
	color_array = ft_split(str, ",");
	// Still don't know if I should convert before or after make the double array one might be better than the other 
	if (!color_array OR !color_array[0] OR !color_array[1] OR !the color_array[2] OR color_array[3])
		return (-1);
	while (color_array[i] != NULL)
	{
		if (ft_atoi(color[i]) < 0 OR ft_atoi(color[i]) > 255)
			return (print_err("Color value impossible", -1));
		i++;
	}
	if (!x)
		data->sky = fillcolorfunction(color_array);
	else
		data->flr = fillcolorfunction(color_array);
	free(color_array);
	return (0);
}
*/

int	parse_fill_info(t_data *data, char **arr)
{
	if (!arr)
		return (0);
	if (!arr[0] || !arr[1] || arr[2]) // I might want to make a function that check weather a tab as n number of row ??
		return (-1); // Need to add specific error msg (Wrong entry ??)
	if (!ft_strncmp(arr[0], "NO", ft_strlen(arr[0])))
		data->txr[NO] = ft_strdup(arr[1]); // Need to check if data is empty or else need to return an error ??
	else if (!ft_strncmp(arr[0], "SO", ft_strlen(arr[0])))
		data->txr[SO] = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "WE", ft_strlen(arr[0])))
		data->txr[WE] = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "EA", ft_strlen(arr[0])))
		data->txr[EA] = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "C", ft_strlen(arr[0]))) // Need to take care of colors and try not to forget about T in TRGB
		data->sky = 1;
	else if (!ft_strncmp(arr[0], "F", ft_strlen(arr[0])))
		data->flr = 1;
	else
		return (-1); // Need to add specific error msg (Wrong entry ??)
	return (0);
}

int	parse_info(t_data *data) // Parsing of the text above the map
{
	char	*tmp_line;
	char	**tmp_array;

	tmp_line = get_next_line(data->fd);
	/* Not so sure about parse_check_isfulll, might cause some issues 
	if the map is full but still contains double params or some stuff*/
	while (tmp_line != NULL && parse_check_isfull(data))
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
	printf("data.txr[0] = %s\n", data->txr[0]);
	printf("data.txr[1] = %s\n", data->txr[1]);
	printf("data.txr[2] = %s\n", data->txr[2]);
	printf("data.txr[3] = %s\n", data->txr[3]);
	printf("data.sky = %d\n", data->sky);
	printf("data.flr = %d\n", data->flr);
	return (parse_check_info(data));
}

int	parsing_base(t_data *data) // Base of the parsing
{
	/* My way to do the parsing :  Need not to forget to put function as static as much as possbile
		Txt and Colors : 
		- Skip empty lines ✅ 
		- Check first word to see what it is (NO, SO...) ✅ 
		- NEED to change the split into charset separator !!!!!
		- Use spaces as dlmtr to find values if not then comma 
		- Check that I got all 6 values before the map is here ✅ 
		- Send right errors if values ain't all here ✅ 
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
