/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:04:43 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/07 11:08:44 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libasic.h"

int	ft_atoi(const char *str)
{
	int	i;
	long	res;
	int minus;

	i = 0;
	res = 0;
	minus = 1;
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)res * minus);
}
