/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:23:13 by hlevi             #+#    #+#             */
/*   Updated: 2020/12/16 12:25:12 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chartostring(int c)
{
	char *str;

	if (!(str = ft_calloc(sizeof(char), 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
