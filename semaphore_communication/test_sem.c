#include"common.h"
//#include<unistd.h>
int main()
{
	int sem_id = Creat_Sem();
	int val = 1;
	Init_Sem(sem_id,val);
	int pid = fork();
	if(pid == 0)
	{
	  //child
	  while(1)
	  {
		P(sem_id,0);
		printf("A");
		fflush(stdout);
		usleep(123456);
		printf("A");
		fflush(stdout);
		usleep(123456);
		V(sem_id,0);
	  }
	}
	else
	{
		while(1)
		{
		    P(sem_id,0);
			printf("B");
			fflush(stdout);
			usleep(123456);
			printf("B");
			fflush(stdout);
			V(sem_id,0);
		}
		wait(NULL);
	}
    printf("\n");
    Destory_Sem(sem_id);
    return 0;
}
