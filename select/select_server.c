#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<sys/select.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX_SIZE sizeof(fd_set)*8 
int fds[MAX_SIZE];

static void Usage(char* proc)
{
	printf("Usage: %s [local_ip] [local_port]\n",proc);
}


int startup(char* ip,int port)
{
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("socket");
		return 1;
	}
	//creat sock success;

	struct sockaddr_in local_server;
	local_server.sin_family = AF_INET;
	local_server.sin_port = htons(port);
	local_server.sin_addr.s_addr = inet_addr(ip);

	socklen_t  len_server = sizeof(local_server);
	if(bind(sock,(struct sockaddr*)&local_server,len_server) < 0)
	{
		perror("bind");
		return 2;
	}

	//bind success
	
	if(listen(sock,5) < 0)
	{
		perror("listen");
		return 3;
	}

	//listen sucess;
	
	return sock;
}
int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
	}

	int listen_sock = startup(argv[1],atoi(argv[2]));

	//select
	fd_set rfds;   //defination read file descripter set
	int nums = sizeof(fds)/sizeof(fds[0]);  //fd num;
	int i = 0 ;
	//set invalid  start value;
	for(i=0;i<nums;i++)
	{
		fds[i] = -1;
	}

	while(1)	
	{
		FD_ZERO(&rfds);
		FD_SET(listen_sock,&rfds);
		int max = listen_sock;
		fds[0] = listen_sock;
		struct timeval timeout = {10,0};

		for(i=0;i<nums;i++)
		{
			if(fds[i] > -1)
			{
 				FD_SET(fds[i],&rfds);
				if(max < fds[i])
				{
					max = fds[i];
				}
			}
		} //for
		switch(select(max+1,&rfds,NULL,NULL,&timeout))
		{
			case 0: //timeout
 				printf("timeout.....\n");
				break;
			case -1://erro
   				perror("select");
				break;
			default:
   				{
   					//least one sock is ready;
					for(i =0;i<nums;i++)
					{
   						if(fds[i] == -1)
						{
							continue;
						}

						if(FD_ISSET(fds[0],&rfds))   
						{
  							struct sockaddr_in client;
							socklen_t len_client = sizeof(client);

							int new_sock = accept(fds[i],(struct sockaddr*)&client,&len_client);

							if(new_sock<0)
							{
 								perror("accept");
								continue;
							}

							printf("get a new client: [%s] [%d]",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
							fflush(stdout);

							int j = 1;
							for(j=1;j<nums;j++)
							{
 								if(fds[j] == -1)
								{
									break;
								}
							}

							if(j == nums)
							{
								close(new_sock);
							}
							else
							{
								fds[j] = new_sock;
							}
						}  //if

						else if(i != 0 && FD_ISSET(fds[i],&rfds))
						{
  							char buf[1024];
 							ssize_t s = read(fds[i],buf,sizeof(buf)-1);
							if(s > 0)
							{
								printf("client# %s\n",buf);
							}
							else if(s == 0)
							{
  								printf("the client is quit!!\n");
								close(fds[i]);
								fds[i] = -1;
							}
						}
						else
						{
  							//buf[0] = 0;
							//printf("no fd ready.\n");
						}
					}//for
				}//defalut
				break;
		}//switch

	}//while
	
	

	return 0;
}
