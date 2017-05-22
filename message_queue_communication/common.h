#ifndef _COMMON_H
#define _COMMON_H
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
#define PATHNAME "/home/cm/code"
#define PROJ_ID 0x6666
#define SERVER_TYPE 1
#define CLIENT_TYPE 2
struct msgbuf
{
	long mtype;
	char mtext[1024];
};

int commonCreat_messageQueue(int flags);
int Get_messageQueue();
int Creat_messageQueue();
int Delete_messageQueue(int msg_id);
int sendData_To_messageQueue(int msg_id,int sendType,char* msg);
int receiveData_Of_messageQueue(int msg_id,int recvType,char *out);

#endif
