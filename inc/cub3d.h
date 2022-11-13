/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:22:03 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/13 14:54:43 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libasic.h"
# include "../MLX42/mlx.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_data
{
	char	**map; // Map Array
	char	(*txr)[4]; // Texture Fixed Array
	int		sky; // int for skt color trgb
	int		flr; // int for floor color trgb
	int		fd; // int for fd
}			t_data;

//	PASRING
//		Mapfile
int	mapfile_info_check(t_data *data);
int	mapfile_check(t_data *data, char *path);
//		Parsing
int	parse_info(t_data *data);
int	parsing_base(t_data *data);
//		Parsing_utils
int	print_err(char *str, int exit_code);

#endif
