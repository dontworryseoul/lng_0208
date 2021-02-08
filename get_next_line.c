#include "get_next_line.h"

int find_return(int fd, char **buf, backup)
{
    // char buf[BUFFER_SIZE + 1];	
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE +1))))
		return (-1);
    while (ft_strchr(backup, \n))
    {
        if ((read_len = read(fd, buf, BUFFER_SIZE)) == -1)
            return (-1);
        else if(read_len == 0)
            break ;
        buf[read_len] = '\0'; //
        backup = ft_strjoin(backup, buf)
    } //while문에 나온 값은 '\n'을 포함한 문장. 
}

int get_next_line(int fd, char **line)
{
    static char *backup;
	char *buf;
/*
// if (fd < 0, line == 0, BUFFER_SIZE <= 0)
//  return (-1)
// backup에 개행이 있을 때 까지 반복 
find_return(fd, &buf,    );
// while 필요한 함수
// 1. '\n' 전까지 별도 문장으로 만들어 주는 함수.
// 2. '\n' 후부터 별도 문장으로 만들어 주는 함수.
// backup에 buf 이어붙이는 기능
// backup에 개행문자 있을 시 line, new_backup 분리하는 기능
*/
}
