#include "get_next_line.h"

void only_free(char *buf)
{
    if (buf)
        free(buf);
    buf = 0;
}

int find_return(int fd, char **backup)
{
    int read_len;
    char *tmp;
    char *buf;

    read_len = 1;
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
    while (!(ft_strchr(*backup, '\n')) && read_len != 0)
    {
        if ((read_len = read(fd, buf, BUFFER_SIZE)) == -1)
        {
            only_free(buf);
            return (-1);
        }
        buf[read_len] = '\0';
        tmp = ft_strjoin(*backup, buf);
        only_free(*backup);
        *backup = tmp;
    }
    only_free(buf);
    if (read_len == 0)
        return (0);
    return (1);
}

char *set_after_nl(char **backup)
{
    char *tmp;
    tmp = ft_strdup(ft_strchr(*backup, '\n') + 1);
    free(*backup);
    return (tmp);
}

char *set_prev_nl(char *backup)
{
    char *str;
    char *tmp;

    if (!(tmp = ft_strdup(backup)))
        return (0);
    only_free(backup);
    *(ft_strchr(tmp, '\n')) = '\0';
    return (tmp);
}

int get_next_line(int fd, char **line)
{
    static char *backup[OPEN_MAX + 1];
    char *tmp;
    int ret ;

    if (fd < 0 && line == 0 && BUFFER_SIZE <= 0)
        return (-1);
    if ((ret = find_return(fd, &backup[fd])) == -1)
        return (-1);
    else if (ret == 0)
        return (0);
    *line = set_prev_nl(backup[fd]);
    backup[fd] = set_after_nl(&backup[fd]);
    return (1);//마지막행일때 0과같이 출력하는 예외처리를 어디서 해줄지 고민하기.
}