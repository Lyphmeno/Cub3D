/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:44:17 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/04 16:11:14 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libasic.h"

void	*ft_memset(void	*pointer, int value, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)pointer;
	while (len)
	{
		*str = (unsigned char)value;
		str++;
		len--;
	}
	return (pointer);
}
