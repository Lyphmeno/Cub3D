/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:22:03 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/07 12:47:14 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libasic.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	char	**map; // Map Array
	char	(*txr)[4]; // Texture Fixed Array
	int		sky; // int for skt color trgb
	int		flr; // int for floor color trgb
	int		fd; // int for fd
}			t_data;

//	MAP FILE CHECK
int		mapfile_check(t_data *data, char *path);
//	PARSING MAP
int	parsing_base(t_data *data);

#endif
