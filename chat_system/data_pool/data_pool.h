
#ifndef _DATA_POOL_H_
#define _DATA_POOL_H_

#include <iostream>
#include <vector>
#include <string>
#include <semaphore.h>

class data_pool{
	public:
		data_pool(int _cap);
		void getData(std::string &outString);
		void putData(const std::string &inString);
		~data_pool();
	private:
		std::vector<std::string> pool;
		int cap;
		int get_step;
		int put_step;

		sem_t data_sems;
		sem_t blank_sems;
};

#endif









