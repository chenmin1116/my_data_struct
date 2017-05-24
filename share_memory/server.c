#include"common.h"
//server

int main()
{
	int shm_id = Get_ShareMemory(4096);
	//printf("shm_id = %d\n",shm_id);
	char* addr = shmat(shm_id,NULL,0);
    //sleep(2);
	int i =0;
	while(i<26)
	{
		printf("client# %s\n",addr);
		i++;
	}
	shmdt(addr);
	sleep(2);
	Destory_ShareMemory(shm_id);
	return 0;
	
}
