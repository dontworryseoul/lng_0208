#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <unistd.h>
# include <stdlib.h>

int     get_next_line(int fd, char **line);
char    *ft_strdup(const char *s);
void    *ft_memcpy(void *dest, const void *src, size_t n);
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);

#endif