/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:37:24 by hlevi             #+#    #+#             */
/*   Updated: 2022/07/17 15:54:58 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

// DONT FORGET THAT ERROR MUST BE PRECEDED BY ERROR\n  !!!!

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		printf("Invalid number of arguments\n");
		return (-1);
	}
	data = malloc(sizeof(t_data) * 1);
	ft_memset(data, 0, sizeof(data));
	if (mapfile_check(data, av[1]))
	{
		printf("Map file isn't valid, left program\n");
		free(data);
		return (-1);
	}
	if (parsing_base(data))
	{
		printf("Parsing has foudn errors in the param, left program\n");
		free(data);
		return (-1);
	}
	return (0);
}
