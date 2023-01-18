/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:50:39 by hlevi             #+#    #+#             */
/*   Updated: 2023/01/18 16:43:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/libasic.h"

void	**ft_new_arr(size_t row, size_t col, size_t size)
{
	void	**arr_ptr;
	char	*arr_byte;
	size_t	total_size;
	size_t	y;

	if (row == 0 || col == 0 || size == 0)
		return (NULL);
	total_size = (col * sizeof(void *)) + (row * col * size);
	if ((total_size - col * sizeof(void *)) != (row * col * size))
		return (NULL);
	arr_ptr = (void **)malloc(total_size);
	if (arr_ptr == NULL)
		return (NULL);
	ft_bzero(arr_ptr, total_size);
	arr_byte = (char *)arr_ptr + col * sizeof(void *);
	y = 0;
	while (y < col)
	{
		arr_ptr[y] = arr_byte + (y * (row * size));
		y++;
	}
	return (arr_ptr);
}
