#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int get_next_line(int fd, char **line)
{
    static char *backup[OPEN_MAX + 1];
    char        *tmp;
    char        *buf;
    int         ret;
    int         read_len;

    if (fd < 0 && line == 0 && BUFFER_SIZE <= 0)
        return (-1);
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)
    if (!buf)
        return (-1);
    read_len = read(fd, buf, BUFFER_SIZE);
    buf[read_len] = '\0';
    if (read_len == 0)
        return (0);
    *line = ft_strjoin(backup, buf);
    free(buf);
    return (1);    
}

int main(void)
{
    int fd;
    char *line;
    char buf[BUFFER_SIZE + 1];
    int num;

    fd = open("text.txt", O_RDONLY);
    get_next_line(fd, &line);
    puts(line);
    free(line);
    close (fd);
    return (0);
}