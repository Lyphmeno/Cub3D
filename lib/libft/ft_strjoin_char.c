/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:02:25 by hlevi             #+#    #+#             */
/*   Updated: 2020/12/16 12:24:11 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *s1, const char c, int blen)
{
	char	*str;
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	str = ft_strnjoin(s1, tmp, blen, 2);
	if (s1)
		free(s1);
	return (str);
}
