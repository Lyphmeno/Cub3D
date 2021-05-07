/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:08:55 by hlevi             #+#    #+#             */
/*   Updated: 2021/05/07 11:38:27 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_of_words(const char *str, char c)
{
	int count;
	int	word;
	int i;

	count = 0;
	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && word == 0)
			word = 1;
		else if (str[i] == c)
		{
			if (word)
				count++;
			word = 0;
		}
		i++;
	}
	if (word)
		count++;
	return (count);
}

static int	word_size(const char *str, char c)
{
	int size;

	size = 0;
	while (*str != c && *str)
	{
		str++;
		size++;
	}
	return (size);
}

char		**ft_split(const char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		nb_words;
	int		word_len;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	nb_words = nbr_of_words(str, c);
	if (!(tab = (char **)ft_calloc(sizeof(char *), nb_words + 1)))
		return (NULL);
	while (i < nb_words)
	{
		while (str[j] == c && str[j])
			j++;
		word_len = word_size(&str[j], c);
		if (!(tab[i] = (char *)ft_calloc(sizeof(char), word_len + 1)))
			return (NULL);
		ft_strlcpy(&tab[i++][0], (char *)&str[j], word_len + 1);
		j += word_len;
	}
	tab[i] = NULL;
	return (tab);
}