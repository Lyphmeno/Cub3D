/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:59:09 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/20 15:20:16 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
