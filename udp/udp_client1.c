#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>

static void Usage(const char proc)
{
	printf("please enter :%s [server_ip] [server_port]\n,proc");
}

int main(int argc,char* argv)
{
	if(argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}

	//creat sock
	int sock_fd = socket(AF_INET,SOCK_DGRAM,,0);
	if(sock_fd < 0)
	{
		perror("socket");
		exit(2);;
	}
	//creat socket success
	//bind
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[2]));
	server.sin_addr.s_addr = inet_addr(argv[1]);

	int len_server = sizeof(server);
	if(bind(sock_fd,(struct sockaddr*)&server,&len_server) < 0)
	{
		perror("bind");
		exit(3);
	}
	//bind success
	//write---------->read



	return 0;
}
