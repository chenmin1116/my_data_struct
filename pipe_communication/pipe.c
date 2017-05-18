/*************************************************************************
	> File Name: pipe.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Sat 13 May 2017 08:38:52 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main()
{
	//---------------creat pipe start-------------------
	int pipefd[2]={0};
	int ret = pipe(pipefd);//success return 0; failed is -1;
	if(ret == -1 )
	{
		perror("pipe failed");
		return 1;
	}
   //---------------creat pipe end ----------------------
   pid_t id = fork();
   if(id ==0)
   {
	   //child---------write
	   close(pipefd[0]);
	   char* msg = "star";
	   while(1)
	   {
	     write(pipefd[1],msg,sizeof(msg)-1);
	     sleep(1);
	   }
   }
   else
   {
	   //father-------read
	   close(pipefd[1]);
	   char buf[1024];
	   while(1)
	   {

	      ssize_t s = read(pipefd[0],buf,sizeof(buf)-1);
	      if(s>0) //read success
	      {
		     buf[s] = 0;
		     printf("father is read:%s\n",buf);
	      }
	  }
   }
	return 0;
}
