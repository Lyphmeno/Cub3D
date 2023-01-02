/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:59:09 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/02 14:53:40 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_charset(char c, char *str)
{
	while (*str)
		if (c == *str++)
			return (1);
	return (0);
}

char	*first_word(char *tmp)
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

int	print_err(char *str, int exit_code)
{
	printf("Error : %s\n", str);
	return (exit_code);
}
