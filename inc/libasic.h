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

#endif