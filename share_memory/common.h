#ifndef _COMMON_H
#define _COMMON_H
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define PATHNAME "/home/cm"
#define PROJ_ID 0x6666
int Creat_ShareMemory(int size);
int Get_ShareMemory(int size);
int Destory_ShareMemory(int shm_id);

#endif
