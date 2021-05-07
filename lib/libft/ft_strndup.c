/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:20:42 by hlevi             #+#    #+#             */
/*   Updated: 2021/02/02 14:49:17 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!(res = malloc(sizeof(char) * (n + 1))))
		return (0);
	while (src[i] && i < n && n > 0)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
