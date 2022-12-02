/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:33:23 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/15 14:06:46 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libasic.h"

void	ft_printab_char(char *new_arr, int nb_row)
{
	int	i;

	i = 0;
	while (i < nb_row)
	{
		printf("arr[%d] = |%c|\n", i, new_arr[i]);
		i++;
	}
}

void	ft_printab_chars(char **new_arr, int nb_row)
{
	int	i;

	i = 0;
	while (i < nb_row)
	{
		printf("arr[%d] = |%s|\n", i, new_arr[i]);
		i++;
	}
}

void	ft_printab_int(int *new_arr, int nb_row)
{
	int	i;

	i = 0;
	while (i < nb_row)
	{
		printf("arr[%d] = |%d|\n", i, new_arr[i]);
		i++;
	}
}

void	ft_printab_ints(int **new_arr, int nb_row)
{
	int	i;

	i = 0;
	while (i < nb_row)
	{
		printf("arr[%d] = |%ls|\n", i, new_arr[i]);
		i++;
	}
}
