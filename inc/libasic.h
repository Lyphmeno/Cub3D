/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:09:51 by hlevi             #+#    #+#             */
/*   Updated: 2022/12/13 17:26:18 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASIC_H
# define LIBASIC_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void	*pointer, int value, size_t len);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	**ft_new_arr(size_t row, size_t col, size_t type);
void	ft_printab_char(char *new_arr, int nb_row);
void	ft_printab_chars(char **new_arr, int nb_row);
void	ft_printab_int(int *new_arr, int nb_row);
void	ft_printab_ints(int **new_arr, int nb_row);
char	**ft_split(char *str, char *charset);
char	**ft_split_whitespaces(char *str);
char	*ft_readline(int fd);

#endif
