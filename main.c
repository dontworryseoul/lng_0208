#include "get_next_line.h"

int main()
{
  int fd = open("text.txt", O_RDONLY);
  int fd2 = open("text6.txt",O_RDWR|O_CREAT|O_APPEND|O_EXCL,0777);
  char *line;
  int res;
	
  while ((res=get_next_line(fd, &line)) > 0)
  {
    puts(line);
	  //printf("%d\n", res);
    write(fd2, line, ft_strlen(line));
    write(fd2, "\n", 1);
    free(line);
  }
  puts(line);
  printf("%d\n", res);
  write(fd2, line, ft_strlen(line));
  free(line);
  close(fd);
  close(fd2);
  //system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
  return (0);
}