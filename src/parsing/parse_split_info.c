/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:14:25 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/12 15:35:06 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static char	*first_word(char *tmp_line)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	if (!tmp_line)
		return (NULL);
	while (tmp_line[i] && tmp_line[i] >= 0 && tmp_line[i] <= 32)
		i++;
	while (tmp_line[i] && tmp_line[i] > 32)
		word[j++] = tmp_line[i++];
	while (tmp_line[i] && tmp_line[i] >= 0 && tmp_line[i] <= 32)
		word[j++] = tmp_line[i++];
	return (word);
}

int	parse_split_info(char	*tmp_line)
{
	int		i;
	int		len;
	int		cnum;
	int		ccom;

	i = 0;
	len = 0;
	cnum = 0;
	ccom = 0;
	if (!tmp_line)
		return (-1);
	else
	{
		while (tmp_line[i])
		{
			if (tmp_line[i] && tmp_line[i] >= '0' && tmp_line[i] <= '9')
				cnum++;
			while (tmp_line[i] && tmp_line[i] >= '0' && tmp_line[i] <= '9')
				new_line[j++] = tmp_line[i++];
			while (tmp_line[i] && tmp_line[i] >= 0 && tmp_line[i] <= 32)
				i++;
			if (tmp_line[i] == ',')
			{
				ccom++;
				new_line[j++] = tmp_line[i++];
			}
		}
		if (cnum > 3 || ccom != 2)
		{
			free(tmp_line);
			return (-1);
		}
	}
	free(tmp_line);
	return (0);
}
