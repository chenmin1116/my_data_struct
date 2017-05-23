#include"common.h"
static int CommonCreat_Sem(int flags)
{
	key_t key = ftok(PATHNAME,PROJ_ID);
	int sem_id =0;
	if(key<0)
	{
		perror("ftok");
		return -1;
	}
	else
	{
	    sem_id = semget(key,1,flags);
		if(sem_id < 0)
		{
			perror("semget");
			return -2;
		}

	}
	return sem_id;
}
int Creat_Sem()
{
	int sem_id = CommonCreat_Sem(IPC_CREAT | IPC_EXCL | 0666);
	return sem_id;
}
int Get_Sem()
{
	int sem_id = CommonCreat_Sem(IPC_CREAT);
	return sem_id;
}

int Init_Sem(int sem_id,int Val)
{
	union semun _un;
	_un.val = Val;
	int ret = semctl(sem_id,0,SETVAL,_un);
	if(ret < 0)     //init failed
	{
		perror("semctl"); 
		return -1;
	}
	return 0;  //init success
}

int Destory_Sem(int sem_id)
{
	int ret = semctl(sem_id,0,IPC_RMID);
	if(ret < 0)
	{
		perror("semctl");
		return -1;
	}
	return 1;
}

static int CommonPV(int sem_id,int who,int op)
{
	struct sembuf _sf;
	_sf.sem_num = who;
	_sf.sem_op = op; //P:-1;V:1
	_sf.sem_flg = 0;
	int ret = semop(sem_id,&_sf,1);
	if(ret<0)
	{
		perror("semop");
		return -1;
	}
	return 0;
}
int P(int sem_id,int who)
{
	return CommonPV(sem_id,who,-1);
}

int V(int sem_id,int who)
{
	return CommonPV(sem_id,who,1);
}


