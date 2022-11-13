/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:37:24 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/13 14:55:27 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2) // Testing number of argument send to the program
		return (print_err("Invalid number of arguments", -1));
	data = malloc(sizeof(t_data) * 1); // Creating the struct
	ft_memset(data, 0, sizeof(data)); // Setting all to 0
	if (mapfile_check(data, av[1])) // Checking the file send in
	{
		free(data);
		return (-1);
	}
	if (parsing_base(data)) // All the parsing of the map
	{
		free(data);
		return (print_err("Inavlid map", -1));
	}
	free(data);
	return (0);
}
