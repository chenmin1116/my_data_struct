#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char* argv[])
{

	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("socket");
		return 2;
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[2]));
	server.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(sock,(struct sockaddr*)&server,sizeof(server)) < 0)
	{
		perror("connect");
		return 3;
	}

	while(1)
	{
		printf("Please Enter:");
		fflush(stdout);
		char buf[1024];
		ssize_t s = read(0,buf,sizeof(buf)-1);
		if(s>0)
		{
			buf[s-1] = 0;
			write(sock,buf,sizeof(buf)-1);
		}
		else
		{
			perror("read");
			break;
		}
	}

	close(sock);
	return 0;
}
