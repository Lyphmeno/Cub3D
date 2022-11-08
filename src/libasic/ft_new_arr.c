/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:50:39 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/08 16:03:20 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasic.h"

void	**ft_new_arr(int row, int col, size_t type)
{
	void	**arr_ptr;
	int		*arr_byte;
	size_t	total_size;
	size_t	i;

	i = 0;
	if (!row || !col|| !type)
		return (NULL);
	total_size = row * sizeof(void *) + (row * col * type);
	if ((total_size - row * sizeof(void*)) != (row * col * type))
		return (NULL);
	arr_ptr = (void**)malloc(total_size);
	if (arr_ptr == NULL)
		return (NULL);
	ft_bzero(arr_ptr, total_size);
	arr_byte = (int *)arr_ptr + col * sizeof(void*);
	while (i < col) 
	{
		arr_ptr[i] = arr_byte + (i * (row * type));
		i++;
	}
	return (arr_ptr);
}
