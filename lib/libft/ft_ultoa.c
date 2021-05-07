/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:33:18 by hlevi             #+#    #+#             */
/*   Updated: 2020/12/16 12:24:59 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_size(long n)
{
	long i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_ultoa(int n)
{
	int				i;
	unsigned int	nb;
	int				size;
	char			*str;

	if (n < 0)
		nb = 4294967296 + n;
	else
		nb = n;
	i = ft_get_size(nb) - 1;
	size = ft_get_size(nb);
	if (!(str = (char *)ft_calloc(sizeof(char), (size + 1))))
		return (NULL);
	while (i >= 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
