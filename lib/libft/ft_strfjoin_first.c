/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:24 by hlevi             #+#    #+#             */
/*   Updated: 2020/12/16 12:24:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin_first(char *s1, char *s2, int slen, int nlen)
{
	char	*str;

	str = ft_strnjoin(s1, s2, slen, nlen);
	if (s1)
		free(s1);
	return (str);
}
