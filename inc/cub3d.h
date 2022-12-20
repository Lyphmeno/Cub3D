/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:22:03 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/20 15:21:41 by hlevi            ###   ########.fr       */
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
# define MAPP "NSEW"
# define MAPSYM "NSEW10 "

typedef struct s_map
{
	char	**arr;
	int		player;
	int		px;
	int		py;
	int		height;
	int		width;
}			t_map;

typedef struct s_data
{
	t_map	map;
	char	*txr[4];
	int		sky;
	int		flr;
	int		fd;
}			t_data;

//	PASRING
//		Mapfile
int		mapfile_check(t_data *data, char *path);
//		Parsing
int		parsing_base(t_data *data);
//		Parsing_utils
char	*first_word(char *tmp);
int		print_err(char *str, int exit_code);
//		Parsing_info_errors
int		fill_info(t_data *data, int x, char *info);
int		parse_info_miss(t_data *data);
//		Colors
int		get_red(int rgb);
int		get_green(int rgb);
int		get_blue(int rgb);
int		create_rgb(int red, int green, int blue);
//		Parse_colors 
int		fill_colors(char **color_arr);
int		parse_colors(t_data *data, char *str, int x);
//		Pasre_split_info
int		parse_split_info(char	**tmp_line);
//		Parse_map
int		parse_map(t_data *data);
#endif
