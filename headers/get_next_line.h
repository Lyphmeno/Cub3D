/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:23:23 by hlevi             #+#    #+#             */
/*   Updated: 2022/07/16 11:23:38 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "lib.h"

static size_t	ft_strlen_nl(char *s);
static char		*ft_strjoin_gnl(char *s1, char *s2);
static char		*ft_strdup_gnl(char *s);
int				get_next_line(int fd, char **line);

#endif
