#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
void only_free(char *str)
{
    if (str)
        free(str);
    str = 0;
}

int get_next_line(int fd, char **line)
{
    static char *backup[OPEN_MAX + 1];
    char        *buf;
    char        *tmp;
    char        *p_n;
    int         read_len;
    int         flg;
    // int         ret;

    if (backup[fd])
        *line = ft_strdup(tmp);
    else
        *line = ft_strdup("");
    if (fd < 0 && line == 0 && BUFFER_SIZE <= 0)
        return (-1);
    buf = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
    if (!buf)
        return (-1);
    flg = 1;
    while (flg && read_len = read(fd, buf, BUFFER_SIZE))
    {
        buf[read_len] = '\0';
        if ((p_n = ft_strcat(buf, '\n')))
        {
            *p_n = '\0';
            flg = 0;
            ++p_n;
            tmp = ft_strdup(p_t);
        }
    }
    if (read_len == -1)
    {
        free(buf);
        return (-1);
    }
    if (read_len == 0)
    {
        free(buf);
        return (0);
    }
    tmp = backup[fd];
    *line = ft_strjoin(backup[fd], buf);
    only_free(tmp);
    free(buf);
    return (1);    
}

int main(void)
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    puts(line);
    // get_next_line(fd, &line);
    // puts(line);
    free(line);
    close (fd);
    return (0);
}