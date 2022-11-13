/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:09:51 by hlevi             #+#    #+#             */
/*   Updated: 2022/11/12 12:37:52 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

void	ft_bzero(void *s, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void	*pointer, int value, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
void	**ft_new_arr(size_t row, size_t col, size_t type);
void	ft_printab_char(char *new_arr, int nb_row);
void	ft_printab_chars(char **new_arr, int nb_row);
void	ft_printab_int(int *new_arr, int nb_row);
void	ft_printab_ints(int **new_arr, int nb_row);
char	**ft_split(char *str);

#endif