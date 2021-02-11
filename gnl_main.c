#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int get_next_line(int fd, char **line)
{
    static char *
}

int main(void)
{
    int fd;
    char *line;
    char buf[BUFFER_SIZE + 1];
    int num;

    fd = open("text.txt", O_RDONLY);
    num = read(fd, buf, BUFFER_SIZE);
    buf[num] = '\0';
    // get_next_line(fd, &line);
    line = buf;
    puts(buf);
    printf("%d\n", OPEN_MAX);
    // puts(line);
    close (fd);
    return (0);
}