#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>


void* handler_request(void* arg)
{
	    int new_sock = (int)arg;
		char buf[1024];
		while(1)
		{
			ssize_t s = read(new_sock,buf,sizeof(buf)-1);
			if(s > 0)
			{
				buf[s] = 0;
				printf("the client#: %s\n",buf);
				write(new_sock,buf,sizeof(buf)-1);
			}
			else
			{
				if(s == 0)
				{
	   				printf("the client is quit\n");
					break;
				}
				else
				{
	  				perror("read");
					break;
				}
			}
		}
		close(new_sock);
}
int startup(char* ip,int port)
{
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("socket");
		exit(2);
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port); //host to net
	local.sin_addr.s_addr = inet_addr(ip);   //


	if(bind(sock,(struct sockaddr*)&local,sizeof(local))<0)
	{
		perror("bind");
		exit(3);
	}

	if(listen(sock,5)<0)
	{
		perror("listen");
		exit(4);
	}
	return sock;
}


void Usage(char* proc)
{
	printf("Usage:%s,[local ip],[ip_port]\n",proc);
}
int main(int argc,char* argv[])
{

	if(argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
	
	int listen_sock = startup(argv[1],atoi(argv[2]));
	printf("fd:%d\n",listen_sock);

	while(1)
	{
		struct sockaddr_in client;
		socklen_t len = sizeof(client);
		int new_sock = accept(listen_sock,(struct sockaddr*)&client,&len);
		if(new_sock < 0)
		{
			perror("accept");
			continue;
		}
	//	close(listen_sock);
		printf("get a client:[%s][%d]\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));

		//version 1.2
		pthread_t tid;
		pthread_create(&tid,NULL,handler_request,(void*)new_sock);

		pthread_detach(tid);

		//version 1.1  multi_process
//		pid_t id = fork();
//		if(id > 0)
//		{
//			//father process---------------->exit;
//			close(new_sock);
//			waitpid(id,NULL,0);
//		}
//		else
//		{
//			close(listen_sock);
//			if(fork()<0)
//			{
//				exit(0);           //
//			}
//			while(1)
//			{
//				char buf[1024];
//				ssize_t s = read(new_sock,buf,sizeof(buf)-1);
//				if(s > 0)
//				{
//					buf[s] = 0;
//					printf("the client#: %s\n",buf);
//					write(new_sock,buf,sizeof(buf)-1);
//				}
//				else
//				{
//					if(s == 0)
//					{
// 
//					}
//					else
//					{
// 		  				perror("read");
//						break;
//					}
//				}
//			}
//			close(new_sock);
//			exit(1);
//	
//		}
//
//

		
		//version 1.0
	//	char buf[1024];
	//	while(1)
	//	{
	//		ssize_t s = read(new_sock,buf,sizeof(buf)-1);
	//		if(s > 0)
	//		{
	//			buf[s] = 0;
	//			printf("the client#: %s\n",buf);
	//			write(new_sock,buf,sizeof(buf)-1);
	//		}
	//		else
	//		{
	//			if(s == 0)
	//			{
	//   				printf("the client is quit\n");
	//				break;
	//			}
	//			else
	//			{
	//  				perror("read");
	//				break;
	//			}
	//		}
	//	}
	//		close(new_sock);
	} 
	close(listen_sock);
	return 0;
}
