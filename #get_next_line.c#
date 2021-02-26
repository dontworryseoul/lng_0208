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
	char        buf[BUFFER_SIZE + 1];
    int         flag;

    flag = -1;
    if (fd < 0, line == 0, BUFFER_SIZE <= 0)
        return (flag);
    if (flag = is_nl(&backup)) // 0이면 다음 로직으로
        return (flag);
    
    if (flag = read_line(fd, line, &buf, &backup)) 
        return (flag);
// while 필요한 함수
// 1. '\n' 전까지 별도 문장으로 만들어 주는 함수.
// 2. '\n' 후부터 별도 문장으로 만들어 주는 함수.
// backup에 buf 이어붙이는 기능
// backup에 개행문자 있을 시 line, new_backup 분리하는 기능

}

int is_nl(char **backup)
{
    if (ft_strchr(*backup))
        //do something and return 1;
    //if (!*backup)
    //    free(*backup);
    return (0);
}

int read_line(int fd, char **line, char **buf, char **backup)
{
    
    while (read(fd, *buf, BUFFER_SIZE) == BUFFER_SIZE)
    {
        //버퍼사이즈만큼 읽어들이는걸 성공했을때의 로직
    }
        //-->버퍼사이즈만큼 읽는걸 실패했을때 1. 남은 문자들이 버퍼사이즈만큼 있지 않을때 --> 마지막 줄 도달
}

int set_line()
{
        // 라인을 값에 결과물을 저장...
}
    