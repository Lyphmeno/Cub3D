/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:47:42 by hlevi             #+#    #+#             */
/*   Updated: 2019/11/29 15:09:35 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pass_start(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				minus;
	int				i;
	int				nbr;
	unsigned long	testlong;

	nbr = 0;
	testlong = 0;
	i = ft_pass_start(str);
	minus = (str[i] == '-') ? 1 : 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		testlong = (testlong * 10) + (str[i] - '0');
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (testlong > 9223372036854775807ul && minus == 0)
		return (-1);
	if (testlong > 9223372036854775808ul)
		return (0);
	if (minus == 1)
		return (-nbr);
	return (nbr);
}