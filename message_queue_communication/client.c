//client---------------first send data and next is to receive data
#include"common.h"
int main()
{
   int msg_id = Get_messageQueue();
   //read data from stdin and send to msgqueue

   char buf[1024];
   while(1)
   {
	 printf("Please Enter# ");
	 fflush(stdout);
	 ssize_t s = read(0,buf,sizeof(buf)-1);
	 if(s<0)
	 {
		 //read failed
		 perror("read");
	 }
	 buf[s-1] = 0;
     sendData_To_messageQueue(msg_id,CLIENT_TYPE,buf);
	 printf("send done,wait receive............\n");

	 receiveData_Of_messageQueue(msg_id,SERVER_TYPE,buf);
	 printf("Server# %s\n",buf);
   }
	return 0;
}

