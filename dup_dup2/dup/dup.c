#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	umask(0);
	int fd = open("log",O_WRONLY | O_CREAT,0666);
	if(fd < 0)
	{
		perror("open");
		return 1;
	}

	close(1);
	fd = dup(fd);

	int count = 1;
	while(count<=10)
	{
		printf("Hello,world!!!   %d\n",count++);
	}
	return 0;
}
