#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>



int main()
{
	int sv[2];
	if(socketpair(AF_LOCAL,SOCK_STREAM,0,sv) < 0)
	{
		perror("socketpair");
		return 1;
	}


	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return 2;
	}

	else
	{
		if(id == 0)
		{
			//child
			close(sv[0]);
			while(1)
			{
			    sleep(3);
				//write------------->read
				char buf[1024];
				char* msg = "Hello,I am your Child.";
				write(sv[1],msg,strlen(msg));

		    	ssize_t s = read(sv[1],buf,sizeof(buf)-1);
				if(s > 0)
				{
					buf[s] = 0;
					printf("the child###  %s\n",buf);
				}
			
			}
		}

		else
		{
			//father
			close(sv[1]);

			while(1)
			{
				//read--------------->write
				char buf[1024];
				char* msg = "Hello,I am your father.";
				ssize_t s = read(sv[0],buf,sizeof(buf)-1);
				if(s > 0 )
				{
					buf[s] = 0;
					printf("the father###  %s\n",buf);
				}
				write(sv[0],msg,strlen(msg));
			}
		}
	}
	return 0;
}
