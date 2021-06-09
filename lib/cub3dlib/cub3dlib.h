/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:12:05 by hlevi             #+#    #+#             */
/*   Updated: 2021/06/09 11:50:27 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DLIB_H
# define CUB3DLIB_H
# include "../libft/libft.h"
# include "../get_next_line.h"
# include "../minilibx_opengl_20191021/mlx.h"

typedef struct	s_maparam
{
	int			paramtype;
	int			paramcount;
	int			fd;
	int			lores;
	int			lares;
	char		*nopath;
	char		*sopath;
	char		*wepath;
	char		*eapath;
	char		*spipath;
	int			*fcolor;
	int			*ccolor;
	char		**map;
	int			height;
	int			tmpheight;
	int			width;
}				t_maparam;

int		is_map(char *line);
int		get_size(char *map, t_maparam *maparam);
void	fill_spaces(t_maparam *maparam);

int		parsing_base(char *line, t_maparam *maparam);
int		parsing_all(char *map, t_maparam *maparam);

int		check_color(char **tmp, t_maparam *maparam);
int		check_path(char **tmp, t_maparam *maparam);
int		check_res(char **tmp, t_maparam *maparam);
int		check_paramvalue(char **tmp, t_maparam *maparam);
char	*check_paramtype(char *line, char *tmp, t_maparam *maparam, int *validparam);

int		check_horizontal(char **map, int count);
int		init_new_map(t_maparam *map_file, t_maparam *new_file);
int		check_vertical(t_maparam *map_file);

#endif