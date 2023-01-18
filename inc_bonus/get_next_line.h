/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:21:27 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/12 09:22:08 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		gnl_is_newline(char *s);
int		gnl_strlen(char *s, char c);
char	*gnl_strdup(char *s, char c);
char	*gnl_strjoin(char *s1, char *s2, char c);
void	gnl_memmove(char *dst, char *src, int len);

#endif
