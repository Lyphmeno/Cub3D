/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:14:25 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/20 12:17:25 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>
#include <stdlib.h>

static char	*first_word(char *tmp)
{
	int		start;
	int		len;
	char	*word;

	start = 0;
	if (!tmp)
		return (NULL);
	while (tmp[start] && tmp[start] >= 0 && tmp[start] <= 32)
		start++;
	len = start;
	while (tmp[len] && tmp[len] > 32)
		len++;
	word = ft_calloc(sizeof(char), (len - start + 1));
	if (!word)
		return (0);
	ft_strlcpy(word, &tmp[start], len - start + 1);
	return (word);
}

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

static int	get_len_colors(char *tmp, int i)
{
	int		j;
	int		len;

	len = 0;
	while (tmp[i] && (tmp[i] >= 0 && tmp[i] <= 32))
		i++;
	j = i;
	while (tmp[i])
	{
		if (tmp[i] && (tmp[i] >= '0' && tmp[i] <= '9'))
			while (tmp[i] && (tmp[i] >= '0' && tmp[i] <= '9'))
				i++;
		else
			return (0);
		while (tmp[i] && (tmp[i] >= 0 && tmp[i] <= 32))
		{
			len++;
			i++;
		}
		if (tmp[i] && (tmp[i] >= '0' && tmp[i] <= '9'))
			return (0);
		if (tmp[i] && tmp[i] == ',')
			i++;
		while (tmp[i] && (tmp[i] >= 0 && tmp[i] <= 32))
		{
			len++;
			i++;
		}
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
		*tmp = ft_strdup(first);
	}
	if (first)
		free(first);
	return (0);
}
