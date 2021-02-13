#include "get_next_line.h"

int find_return(int fd, char **backup)
{
    int read_len;
    char *tmp;
    char *buf;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
    while (!(ft_strchr(*backup, '\n')))
    {
        if ((read_len = read(fd, buf, BUFFER_SIZE)) == -1)
        {
            free(buf);
            buf = 0;
            return (-1);
        }
        else if(read_len == 0)
            break ;
        buf[read_len] = '\0';
        tmp = ft_strjoin(*backup, buf);
        if (*backup)
            free(*backup);
        *backup = tmp;
    }
    free(buf);
    return (1);
}

char *set_after_nl(char **backup, int *flagcheck)
{
    char *tmp;

    tmp = 0;
    if (ft_strchr(*backup, '\n'))
        tmp = ft_strdup(ft_strchr(*backup, '\n') + 1);
    else
        *flagcheck = 0;
    free(*backup);
    return (tmp);
}

char *set_prev_nl(char *backup)
{
    char *tmp;

    tmp = ft_strdup(backup);
    if((ft_strchr(tmp, '\n')))
        *(ft_strchr(tmp, '\n')) = '\0';
    return (tmp);
}

#include <stdio.h>
#include <limits.h>
int get_next_line(int fd, char **line)
{
    static char *backup[OPEN_MAX];
    int flagcheck;

    if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
        return (-1);
    if ((flagcheck = find_return(fd, &backup[fd])) == -1)
        return (-1);
    if (!flagcheck)
        return (0);
    if (!(*line = set_prev_nl(backup[fd])))
        return (0);
    if (!(backup[fd] = set_after_nl(&backup[fd], &flagcheck)))
        return (0);
    return (flagcheck);
}