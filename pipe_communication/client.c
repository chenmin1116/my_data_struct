//client -------------write data from named pipe
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	    int fd = open("./mypipe",O_WRONLY);
		if(fd < 0) //open file failed
		{
			perror("open file.");
			return 2;
		}
		if(fd >0) //open file success
		{
			char buf[1024];
			while(1)
			{
			  printf("Please Enter:");
			  ssize_t s = read(0,buf,sizeof(buf)-1);
			  if(s>0)   //read success
			  {
				  buf[s] = 0;
				  write(fd,buf,strlen(buf));
			  }
			  else
			  {
				  //read failed
				  perror("read data.");
				  return 3;
			  }

			}
		}
    close(fd);
	return 0;
}
