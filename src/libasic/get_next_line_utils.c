/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:43:52 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/12 09:44:00 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

int	gnl_is_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	gnl_strlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c)
		i++;
	if (c == '\n')
		i++;
	return (i);
}

char	*gnl_strdup(char *s, char c)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (gnl_strlen(s, c) + 1));
	while (s[i] != c)
	{
		cpy[i] = s[i];
		i++;
	}
	if (c == '\n')
	{
		cpy[i] = '\n';
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*gnl_strjoin(char *s1, char *s2, char c)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (gnl_strdup(s2, c));
	cpy = malloc(sizeof(char) * (gnl_strlen(s1, '\0') + gnl_strlen(s2, c) + 1));
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[j] != c)
		cpy[i++] = s2[j++];
	if (c == '\n')
	{
		cpy[i] = '\n';
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	gnl_memmove(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	if (src == dst)
		return ;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
