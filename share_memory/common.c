#include"common.h"

static int CommonCreat_ShareMemory(int size,int flags)
{
	key_t key = ftok(PATHNAME,PROJ_ID);
	if(key < 0)
	{
		perror("ftok");
		return -1;
	}
	int shm_id =  shmget(key,size,flags);
	if(shm_id < 0)
	{
		perror("shmget");
		return -2;
	}
	return shm_id;
}

int Creat_ShareMemory(int size)
{
	return  CommonCreat_ShareMemory(size,IPC_CREAT | IPC_EXCL | 0666);
}
int Get_ShareMemory(int size)
{
	return  CommonCreat_ShareMemory(size,IPC_CREAT);

}
int Destory_ShareMemory(int shm_id)
{
	int ret =  shmctl(shm_id,IPC_RMID,NULL);
	if(ret < 0)
	{
		perror("shmctl");
		return -1;
	}
	return 0;
}
