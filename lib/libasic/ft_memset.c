/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:44:17 by hlevi             #+#    #+#             */
/*   Updated: 2022/07/16 16:36:08 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libasic.h"

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
