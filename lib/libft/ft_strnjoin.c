/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:06 by hlevi             #+#    #+#             */
/*   Updated: 2021/02/02 14:52:36 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int slen, int elen)
{
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	if (!(str = ft_calloc(sizeof(char), slen + elen + 1)))
		return (0);
	ft_strcatnp(str, s1, 0, slen);
	ft_strcatnp(str, s2, slen, elen);
	return (str);
}
