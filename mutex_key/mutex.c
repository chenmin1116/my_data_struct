#include<stdio.h>
#include<pthread.h>
int _val = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_run()
{
	int i=0;
	while(i<5000)
	{

	    pthread_mutex_lock(&mutex);
		_val++;
		i++;
		printf("%d\n",_val);
	    pthread_mutex_unlock(&mutex);
	}
	printf("\n");
	return NULL;
}

int main()
{
	pthread_t tid = 0;  //save the new thread of id;
	int pth_cre = pthread_create(&tid,NULL,thread_run,NULL);
	if(pth_cre != 0)
	{
		perror("pthread_create");
		return -1;
	}
	int i =0;
	while(i<5000)
	{
		pthread_mutex_lock(&mutex);
		int tmp = _val;
		tmp = tmp + 1;
		_val = tmp;
		++i;
		printf("%d\n",_val);
		pthread_mutex_unlock(&mutex);
	}
	pthread_join(tid,NULL);
	printf("\n");
	pthread_mutex_destroy(&mutex);
	return 0;
}
