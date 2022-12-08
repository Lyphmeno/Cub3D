/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21+:28 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/08 14:12:14 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libasic.h"

static int	get_word_len(char *str)
{
	int	i;
	int	j;
	int	tmp;
	int	res;

	i = 0;
	tmp = 0;
	res = 0;
	while (str[i] && ((str[i] >= 0 && str[i] <= 32)))
		i++;
	j = i;
	if (!str[i])
		return (0);
	if (str[i] && str[i] > 32)
		while (str[i] && str[i] > 32)
			i++;
	res = i - j;
	while (str[i] && ((str[i] >= 0 && str[i] <= 32)))
		i++;
	if (!str[i])
		return (0);
	j = i - res;
	if (str[i] && str[i] > 32)
		while (str[i] && str[i] > 32)
			i++;
	tmp = i - res - j;
	printf("res=%d\ntmp=%d\n", res, tmp);
	if (tmp >= res)
		res = tmp + 1;
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
		while (str[i] && ((str[i] >= 0 && str[i] <= 32)))
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

char	**ft_splitwo(char *str)
{
	int		words_len;
	char	**new_arr;

	words_len = 0;
	if (!str)
		return (NULL);
	words_len = get_word_len(str);
	printf("wlen=%d\n", words_len);
	if (!words_len)
		return (NULL);
	new_arr = (char **)ft_new_arr(words_len + 1, 3, sizeof(char));
	if (!new_arr)
		return (NULL);
	fill_array(new_arr, str);
	new_arr[2] = NULL;
	ft_printab_chars(new_arr, 2);
	return (new_arr);
}
