/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:24 by hlevi             #+#    #+#             */
/*   Updated: 2020/12/16 12:24:06 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char *s2, int slen, int nlen)
{
	char	*str;

	str = ft_strnjoin(s1, s2, slen, nlen);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}
