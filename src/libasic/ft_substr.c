/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:03:33 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/13 18:03:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasic.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sstr;
	size_t strlen;

	if (s == NULL)
		return (NULL);
	strlen = 0;
	while (s[strlen] != '\0')
		strlen++;
	if (start > strlen)
		return (ft_strdup(""));
	if (strlen - start >= len)
		sstr = (char *)malloc((len + 1) * sizeof(char));
	else
		sstr = (char *)malloc((strlen - start + 1) * sizeof(char));
	if (sstr == NULL)
		return (NULL);
	ft_strlcpy(sstr, (s + start), (len + 1));
	return (sstr);
}