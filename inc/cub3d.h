/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:22:03 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/05 11:42:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libasic.h"
# include "get_next_line.h"
# include "../MLX42/mlx.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define SKY 4
# define FLR 5

typedef struct s_data
{
	char	**map;
	char	*txr[4];
	int		sky;
	int		flr;
	int		fd;
}			t_data;

//	PASRING
//		Mapfile
int	mapfile_check(t_data *data, char *path);
//		Parsing
int	parsing_base(t_data *data);
//		Parsing_utils
int	print_err(char *str, int exit_code);
//		Parsing info errors
int fill_info(t_data *data, int x, char *info);
int parse_info_miss(t_data *data);

#endif
