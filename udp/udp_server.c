#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
static void Usage(const char proc)
{
	printf("please enter :%s [server_ip] [server_port]\n",proc);
}
int main(int argc ,char*argv)
{
	if(argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
	//creat sock
	int sock_fd = socket(AF_INET,SOCK_DGRAM,0);

	//creat sock failed
	if(sock_fd < 0)
	{
		peeror("socket");
		exit(2);
	}
	//creat sock success
	//bind
	struct sockaddr_in server_self;
	server_self.sin_family = AF_INET;
	server_self.sin_port = htons(atoi(argv[2]));
	server_self.sin_addr.s_addr = inet_addr(argv[1]);
	int len_server = sizeof(server_self);
	if(bind(sock_fd,(struct sockaddr*)&server_self,&len_server) < 0);
	{
		perror("bind");
		exit(3);
	}
	//bind success
	
	struct sockaddr_in client;
	int len_client = sizeof(client);
	while(1)
	{
		char buf[1024];
		ssize_t s = recvfrom(sock_fd,(void*)buf,sizeof(buf) - 1,0,(struct sockaddr*)&client,&len_client);
		if(s > 0)
		{
			buf[s] = 0;
			printf("the client#  %s\n",buf);
			sendto(sock_fd,(void*)buf,sizeof(buf)-1,0,(struct sockaddr*)server_self,len_server);
		}
		else
		{
			if(s == 0)
			{
				printf("the client is quit!!\n");
				break;
			}
			else
			{
				perror("recvfrom");;
				break;
			}
		}
	}
	close(sock_fd);
	
	return 0;
}
