#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
size_t	ft_strlen(const char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *d, void const *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int get_next_line(int fd, char **line);

#endif
