/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:14:25 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/20 15:26:32 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>
#include <stdlib.h>

static char	*get_spaceless_color(char *tmp, int len, int i)
{
	int		j;
	char	*cpy;

	j = 0;
	cpy = ft_calloc(sizeof(char), len + 1);
	if (!cpy)
		return (NULL);
	while (tmp[i])
	{
		while (tmp[i] && !(tmp[i] >= 0 && tmp[i] <= 32))
			cpy[j++] = tmp[i++];
		i++;
	}
	return (cpy);
}

static int	is_whitespace(char *tmp, int i)
{
	int	j;

	j = i;
	while (tmp[i] && (tmp[i] >= 0 && tmp[i] <= 32))
		i++;
	return (i - j);
}

static int	get_len_colors(char *tmp, int i)
{
	int		j;
	int		len;

	len = 0;
	i += is_whitespace(tmp, i);
	j = i;
	while (tmp[i])
	{
		if (tmp[i] >= '0' && tmp[i] <= '9')
			while (tmp[i] && (tmp[i] >= '0' && tmp[i] <= '9'))
				i++;
		else
			return (0);
		len += is_whitespace(tmp, i);
		i += is_whitespace(tmp, i);
		if (tmp[i] >= '0' && tmp[i] <= '9')
			return (0);
		if (tmp[i] == ',')
			i++;
		len += is_whitespace(tmp, i);
		i += is_whitespace(tmp, i);
	}
	len = i - j - len;
	return (len);
}

static char	*colorsplit(char *tmp, int i)
{
	int		len;
	char	*new_line;

	len = get_len_colors(tmp, i);
	if (len <= 0)
		return (NULL);
	new_line = get_spaceless_color(tmp, len, i);
	return (new_line);
}

int	parse_split_info(char	**tmp)
{
	char	*first;

	first = first_word(*tmp);
	if (!first)
		return (0);
	if (!ft_strncmp(first, "C", ft_strlen(first))
		|| !ft_strncmp(first, "F", ft_strlen(first)))
	{
		first = ft_strfjoin(first, " ", 1);
		first = ft_strfjoin(first, colorsplit(*tmp, ft_strlen(first)), 0);
		free(*tmp);
		*tmp = ft_strdup(first);
	}
	free(first);
	return (0);
}
