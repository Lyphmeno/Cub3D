/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:55:58 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/05/03 18:34:15 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_newarray(size_t w, size_t h, size_t size)
{
	void	**array_ptr;
	char	*array_byte;
	size_t	total_size;
	size_t	y;

	if (w == 0 || h == 0 || size == 0)
		return NULL;
	total_size = (h * sizeof(void*)) + (w * h * size);
	if ((total_size - h * sizeof(void*)) != (w * h * size))
		return NULL;
	array_ptr = (void**)malloc(total_size);
	if (array_ptr == NULL)
		return NULL;
	ft_memset(array_ptr, 0, total_size);
	array_byte = (char *)array_ptr + h * sizeof(void*);
	y = 0;
	while (y < h)
    {
		array_ptr[y] = array_byte + (y * (w * size));
		y++;
	}
	return (array_ptr);
}
