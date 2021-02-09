//#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*strchr(const char *s, int c)
{
	while (42)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		++s;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		*dest_cpy++ = *src_cpy++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		++i;
	return (i);
}

char*		strdup(const char *s)
{
	char	*s_cpy;
	size_t	len;

	len = ft_strlen(s);
	if (s == 0)
		return (NULL);
	if (!(s_cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(s_cpy, s, len);
	s_cpy[len] = '\0';
	return (s_cpy);
}

int main()
{
    char *tmp;

    tmp = strdup("asdf\n");
    *(strchr(tmp, 's')) = '\0';
    printf("%s\n", tmp);
    free(tmp);
    return 0;
}