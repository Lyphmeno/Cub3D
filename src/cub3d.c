/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:37:24 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/08 11:37:58 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdlib.h>

void	free_data(t_data *data)
{
	free(data->txr[NO]);
	free(data->txr[SO]);
	free(data->txr[WE]);
	free(data->txr[EA]);
	free(data->map);
	free(data);
}

static void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(data)); // Setting all to 0	
	ft_memset(data->txr, 0, sizeof(char *)); // Setting txr to zero
	data->txr[0] = NULL;
	data->txr[1] = NULL;
	data->txr[2] = NULL;
	data->txr[3] = NULL;
	data->sky = -1;
	data->flr = -1;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2) // Testing number of argument send to the program
		return (print_err("Invalid number of arguments", -1));
	data = malloc(sizeof(t_data) * 1); // Creating the struct
	init_data(data);
	if (mapfile_check(data, av[1])) // Checking the file send in
	{
		free(data);
		return (-1);
	}
	if (parsing_base(data)) // All the parsing of the map
	{
		free_data(data);
		return (-1);
	}
	free_data(data);
	return (0);
}
