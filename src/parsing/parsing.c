/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:30:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/15 14:05:56 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_info(t_data *data) // Parsing of the text above the map
{
	char	**tmp_array;

	tmp_array = ft_split(ft_readline(data->fd));
	free(tmp_array);
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
