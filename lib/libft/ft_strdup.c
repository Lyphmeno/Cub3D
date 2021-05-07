/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:20:42 by hlevi             #+#    #+#             */
/*   Updated: 2021/02/02 14:48:45 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	size_t	slen;
	size_t	i;
	char	*res;

	slen = ft_strlen(src);
	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * slen + 1)))
		return (0);
	while (i < slen)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
