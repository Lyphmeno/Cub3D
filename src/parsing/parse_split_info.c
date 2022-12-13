/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:14:25 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/13 17:26:18 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>
#include <stdlib.h>

static char	*first_word(char *tmp_line)
{
	int		start;
	int		len;
	char	*word;

	start = 0;
	if (!tmp_line)
		return (NULL);
	while (tmp_line[start] && tmp_line[start] >= 0 && tmp_line[start] <= 32)
		start++;
	len = start;
	while (tmp_line[len] && tmp_line[len] > 32)
		len++;
	word = ft_calloc(sizeof(char), (len - start + 1));
	if (!word)
		return (0);
	ft_strlcpy(word, &tmp_line[start], len - start + 1);
	printf("word =|%s|\n", word);
	return (word);
}

static char *parse_split_colors(char *tmp_line, int i)
{
	int		j;
	char	*new_line;

	j = 0;
	if (!tmp_line)
		return (NULL);
	while (tmp_line[i] && tmp_line[i] >= 0 && tmp_line[i] <= 32)
		i++;
	while (tmp_line[i])
	{
		while (tmp_line[i] && tmp_line[i] > 32)
			new_line[j++] = tmp_line[i++];
		while (tmp_line[i] && tmp_line[i] >= 0 && tmp_line[i] <= 32)
			i++;
		if (tmp_line[i] != ',' && !(tmp_line[i] >= '0' && tmp_line[i] <= '9'))
	}
	return (new_line);
}

int	parse_split_info(char	**tmp_line)
{
	char	*first;
	char	*new_line;
	char	*tmp;
	
	first = first_word(*tmp_line);
	printf("first = %s\n", first);
	printf("line = %s\n", *tmp_line);
	if (!ft_strncmp(first, "C", ft_strlen(first))
		|| !ft_strncmp(first, "F", ft_strlen(first)))
		new_line = parse_split_colors(tmp_line, ft_strlen(first) + 1);
	free(first);
	return (0);
}
