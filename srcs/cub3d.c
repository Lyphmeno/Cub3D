/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:37:24 by hlevi             #+#    #+#             */
/*   Updated: 2022/07/16 18:18:00 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	mapfile_check(data, av[1]);
	return (0);
}
