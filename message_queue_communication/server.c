//server-------------first receive data and next to send data
#include"common.h"
int main()
{
	char buf[1024];
	int msg_id = Creat_messageQueue();
	while(1)
	{ 
		//receive data
		receiveData_Of_messageQueue(msg_id,CLIENT_TYPE,buf);
		printf("Client#%s\n",buf);
		//send data
		printf("Please Enter# ");
		fflush(stdout);
		ssize_t s = read(0,buf,sizeof(buf)-1);
		if(s>0) //read success
		{
			buf[s-1] = 0;
			sendData_To_messageQueue(msg_id,SERVER_TYPE,buf);
			printf("send done,wait receive........\n");
		}
	}
	return 0;
	Delete_messageQueue(msg_id);
}
