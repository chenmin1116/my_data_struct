#include"common.h"

int commonCreat_messageQueue(int flags)
{
    key_t key = ftok(PATHNAME,PROJ_ID);
	if(key < 0)
	{
		perror("ftok");
		return -1;
	}
	int msg_id =  msgget(key,flags);
	if(msg_id < 0)
	{
		perror("msgget");
		return -2;
	}
	return msg_id;
}

int Creat_messageQueue()
{
	int msg_id = commonCreat_messageQueue(IPC_CREAT | IPC_EXCL|0666);
	return msg_id;
}


int Get_messageQueue()
{
	int msg_id = commonCreat_messageQueue(IPC_CREAT);
	return msg_id;
}

int Delete_messageQueue(int msg_id)
{
	if( msgctl(msg_id,IPC_RMID,NULL)<0)
	{
		return -1;
	}
	return 0;
}

//send data
int sendData_To_messageQueue(int msg_id,int sendType,char* msg)
{
	struct msgbuf buf;
	buf.mtype = sendType;
	strcpy(buf.mtext,msg);
	int snd_msg = msgsnd(msg_id,(void*)&buf,sizeof(buf.mtext),0);
	if(snd_msg <0)
	{
		perror("msgsng");
		return -3;
	}
	return 0;;
}

//receive data
int receiveData_Of_messageQueue(int msg_id,int recvType,char* out)
{
	struct msgbuf buf;
	ssize_t s = msgrcv(msg_id,(void*)&buf,sizeof(buf.mtext),recvType,0);
	if(s < 0)
	{
		perror("msgrcv");
		return -4;
	}
	strcpy(out,buf.mtext);
	return 0;
}













