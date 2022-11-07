/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:26:08 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/07 15:58:30 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

ssize_t	gnl_read_file(int fd, char **buffer, char **buff_read, char **line);
char	*gnl_get_line(char **buff_read, char **line);
char	*get_next_line(int fd);

char	*gnl_ft_strchr(const char *s, int c);
size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
char	*gnl_ft_strdup(const char *s1);
char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);

#endif