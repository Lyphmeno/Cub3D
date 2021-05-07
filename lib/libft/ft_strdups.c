/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:28:33 by hlevi             #+#    #+#             */
/*   Updated: 2021/02/02 14:49:11 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdups(char *src)
{
	size_t	slen;
	size_t	i;
	char	*res;

	if (src == NULL)
	{
		res = ft_strdup("(null)");
		return (res);
	}
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
