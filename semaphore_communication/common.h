#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#define PATHNAME "/home/cm/code"
#define PROJ_ID 0x6666

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
};

//
//struct sembuf
//{
//	unsigned short sem_num;
//	short sem_op;
//	short sem_flg;
//};
int Creat_Sem();
int Get_Sem();
int Init_Sem(int sem_id,int val);
int Destory_Sem(int sem_id);
int P(int sem_id,int who);
int V(int sem_id,int who);
#endif
