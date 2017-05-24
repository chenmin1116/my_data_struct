#include"common.h"
//client
int main()
{
	int shm_id = Creat_ShareMemory(4096);
	sleep(1);
	char* addr = shmat(shm_id,NULL,0);
	sleep(2);
	int i =0;
	while(i<26)
	{
		addr[i] = 'A'+i;
		i++;
		addr[i] = 0;
	}
	shmdt(addr);
	sleep(2);
	return 0;
	
}
