/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:59:10 by hlevi             #+#    #+#             */
/*   Updated: 2020/12/16 12:24:42 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (res == 0 && s1[i] && s2[i] && i < n)
	{
		if (s1[i] > s2[i])
			res = 1;
		else if (s1[i] < s2[i])
			res = -1;
		i++;
	}
	if (s1[i] && !s2[i] && i < n)
		res = 1;
	else if (!s1[i] && s2[i] && i < n)
		res = -1;
	return (res);
}
