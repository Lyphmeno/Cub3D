/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:33:18 by hlevi             #+#    #+#             */
/*   Updated: 2020/12/16 12:25:04 by hlevi            ###   ########.fr       */
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

char			*ft_itoa(int n)
{
	int		i;
	long	nb;
	int		size;
	char	*str;
	int		neg;

	nb = n;
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	size = ft_get_size(nb);
	i = (neg ? size : size - 1);
	if (!(str = (char *)ft_calloc(sizeof(char), (size + neg + 1))))
		return (NULL);
	while (i >= 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
