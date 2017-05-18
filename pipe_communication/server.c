//server -------------read data from named pipe
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	umask(0);
	//creat a pipe of named mypipe
	int ret = mkfifo("./mypipe",S_IFIFO|0666);//success return 0;failed return -1;
	if(ret < 0)
	{
		//creat pipe failed
		perror("creat pipe.");
		return 1;
	}
	if(ret == 0)
	{
		//creat pipe success
	    int fd = open("./mypipe",O_RDONLY);
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
			  ssize_t s = read(fd,buf,sizeof(buf)-1);
			  if(s>0)   //read success
			  {
				  buf[s-1] = 0;
				  printf("client# %s\n",buf);
			  }
			  else
			  {
				  if(s<0)
				  {
				    //read failed
				    perror("read file.");
				    return 3;
				  }
				  if(s == 0)
				  {
					  printf("client is quit.\n");
					  break;
				  }
			  }

			}
		}

	}
	return 0;
}
