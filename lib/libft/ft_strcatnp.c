/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatnp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:18 by hlevi             #+#    #+#             */
/*   Updated: 2021/02/02 14:52:11 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcatnp(char *dst, char *src, int slen, int elen)
{
	int		i;
	int		j;

	i = 0;
	j = slen;
	while (i < elen)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
}