
#include "data_pool.h"

data_pool::data_pool(int _cap):
	cap(_cap), pool(_cap), get_step(0), put_step(0)
{
	sem_init(&data_sems, 0, 0);
	sem_init(&blank_sems, 0, cap);
}

void data_pool::getData(std::string &outString)
{
	sem_wait(&data_sems);
	outString = pool[get_step++];
	get_step %= cap;
	sem_post(&blank_sems);
}

void data_pool::putData(const std::string &inString)
{
	sem_wait(&blank_sems);
	pool[put_step++] = inString;
	put_step %= cap;
	sem_post(&data_sems);
}

data_pool::~data_pool()
{
	sem_destroy(&data_sems);
	sem_destroy(&blank_sems);
}











