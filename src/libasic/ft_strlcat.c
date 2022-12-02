/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:37:55 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/13 15:38:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libasic.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	size_src;
	size_t	size_dest;
	size_t	i;
	char	*tmp;

	size_src = ft_strlen(src);
	size_dest = ft_strlen(dst);
	i = 0;
	tmp = (char *)src;
	while (size_dest + i < dstsize - 1 && src[i] && dstsize > 0)
	{
		dst[size_dest + i] = tmp[i];
		i++;
	}
	if (i != 0)
		dst[size_dest + i] = '\0';
	if (dstsize < size_dest)
		return (dstsize + size_src);
	return (size_dest + size_src);
}
