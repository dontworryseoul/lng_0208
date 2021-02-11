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
/*
** 받아온 문장을 strlen 으로 전체 길이를 알아내고
** 받아온 문장 '\n' 까지의 길이를 알아내고
** malloc 문장 길이 - 개행까지 길이 + 1 
** '\n' 개행 뒤 문장을 위에서 할당 받은 메모리에 할당 후 반환.
*/
char *set_after_nl(char **backup)
{
    char *tmp;
    tmp = ft_strdup(ft_strchr(*backup, '\n') + 1);
    free(*backup);
    return (tmp);
}
/*
** 받아온 문장에 '\n' 까지 읽고, 그 길이 +1만큼 malloc으로 메모리 공간 할당
** 할당한 영역에 문장 처음부터 '\n'까지 넣기.
** 만들어진 문장을 반환하기.
*/
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