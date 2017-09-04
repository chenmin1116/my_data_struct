#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

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
	fd = dup2(fd,1);
	int count = 1;
	while(count <= 10)
	{
		printf("Hello,world!!!   %d\n",count++);
	}

	return 0;
}
