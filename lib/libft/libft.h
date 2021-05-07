/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:36:58 by hlevi             #+#    #+#             */
/*   Updated: 2021/05/07 11:39:14 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "../get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# define LOWHEXA "0123456789abcdef"
# define UPHEXA "0123456789ABCDEF"
# define FLAG "-0"
# define TYPE "cspdiuxX%"
# define BUFFER_SIZE 10

typedef struct	s_flags
{
	int			minus;
	int			zero;
}				t_flags;

typedef	struct	s_param
{
	t_flags		flags;
	int			width;
	int			precision;
	int			prec;
	int			size;
	int			type;
	int			neg;
	int			isneg;
	int			len;
	int			tmplen;
	int			space;
}				t_param;

char			*copy_til(char *format, char **res, t_param *param);
void			handle(t_param *param, char *format, va_list arg, char **res);
int				ft_printf(char *format, ...);
char			*get_value(int *value, char *format, va_list arg);
char			*get_flags(t_param *param, char *format);
char			*get_width(t_param *param, char *format, va_list arg);
char			*get_all_specifiers(t_param *param, char *format, va_list arg);
char			*handle_others(t_param *param, va_list arg);
char			*handle_digit(t_param *param, va_list arg);
char			*handle_precision_digit(t_param *param, char *tmp);
char			*handle_precision_all(t_param *param, char *tmp);
char			*handle_width_minus(t_param *param, char *tmp_pre);
char			*handle_width_zero(t_param *param, char *tmp_pre);
char			*handle_width(t_param *param, char *tmp_pre);
char			*handle_width_all(t_param *param, char *tmp_pre);
char			*handle_last(t_param *param, char *tmp_width);
void			handle_all(t_param *param, va_list arg, char **res);
int				check_neg(t_param *param, int number);
char			*convert_p_hexa(void *nb, t_param *param);
char			*convert_hexa(unsigned long nb, char *base);
char			*ft_itoa(int n);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t count, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strfjoin(char *s1, char *s2, int slen, int elen);
char			*ft_strjoin_char(char *s1, const char c, int blen);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strnjoin(char *s1, char *s2, int slen, int elen);
char			*ft_strfjoin_first(char *s1, char *s2, int slen, int nlen);
char			*ft_strdup(char *src);
char			*ft_strdupn(char *src, int len);
char			*ft_strdups(char *src);
char			*ft_strndup(char *src, size_t n);
void			ft_strcpy(char *dst, char *src);
void			ft_strcat(char *dst, char *src);
void			ft_strcatnp(char *dst, char *src, int slen, int elen);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_chartostring(int c);
int				ft_hexalen(unsigned long nb);
int				ft_strlen(char *str);
char			*ft_ultoa(int n);
int				nbr_of_words(const char *str, char c);
char			**ft_split(const char *str, char c);
int				ft_atoi(const char *str);
int				is_charset(char c, char *charset);
void			**ft_newarray(size_t w, size_t h, size_t size);

#endif
