/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:18 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/18 16:43:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/libasic.h"

static int	is_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_nb_words(char *str, char *charset)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
		{
			while (str[i] && !is_charset(charset, str[i]))
				i++;
			res++;
		}
	}
	return (res);
}

static int	get_word_len(char *str, char *charset)
{
	int	i;
	int	tmp;
	int	res;

	i = 0;
	tmp = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
		{
			tmp = 0;
			while (str[i] && !is_charset(charset, str[i]))
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

static void	fill_array(char **new_arr, char *str, char *charset)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
		{
			y = 0;
			while (str[i] && !is_charset(charset, str[i]))
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

char	**ft_split(char *str, char *charset)
{
	int		nb_words;
	int		words_len;
	char	**new_arr;

	nb_words = 0;
	words_len = 0;
	if (!str)
		return (NULL);
	nb_words = get_nb_words(str, charset);
	words_len = get_word_len(str, charset);
	if (!nb_words || !words_len)
		return (NULL);
	new_arr = (char **)ft_new_arr(words_len + 1, nb_words + 1, sizeof(char));
	if (!new_arr)
		return (NULL);
	fill_array(new_arr, str, charset);
	new_arr[nb_words] = NULL;
	return (new_arr);
}
