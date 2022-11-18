/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:18 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/18 16:30:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasic.h"

static int	get_nb_words(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && str[i] >= 0 && str[i] <= 32)
			i++;
		if (str[i] && str[i] > 32)
		{
			while (str[i] && str[i] > 32)
				i++;
			res++;
		}
	}
	return (res);
}

static int	get_word_len(char *str)
{
	int	i;
	int	tmp;
	int	res;

	i = 0;
	tmp = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && str[i] >= 0 && str[i] <= 32)
			i++;
		if (str[i] && str[i] > 32)
		{
			tmp = 0;
			while (str[i] && str[i] > 32)
			{
				i++;
				tmp++;
			}
			if (tmp > res)
				res = tmp;
		}
	}
	return (res);
}

static void	fill_array(char **new_arr, char *str)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (str[i])
	{
		while (str[i] && str[i] >= 0 && str[i] <= 32)
			i++;
		if (str[i] && str[i] > 32)
		{
			y = 0;
			while (str[i] && str[i] > 32)
			{
				new_arr[x][y] = str[i];
				i++;
				y++;
			}
			new_arr[x][y] = '\0';
			x++;
		}
	}
}

char	**ft_split(char *str)
{
	int		nb_words;
	int		words_len;
	char	**new_arr;

	nb_words = 0;
	words_len = 0;
	if (!str)
		return (NULL);
	nb_words = get_nb_words(str);
	words_len = get_word_len(str);
	if (!nb_words || !words_len)
		return (NULL);
	new_arr = (char **)ft_new_arr(words_len + 1, nb_words + 1, sizeof(char));
	if (!new_arr)
		return (NULL);
	fill_array(new_arr, str);
	new_arr[nb_words] = NULL;
	ft_printab_chars(new_arr, nb_words);
	return (new_arr);
}
