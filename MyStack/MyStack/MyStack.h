#pragma once

#include <vector>

class MyStack
{
	std::vector<int> _v;
public:
	MyStack(void);//构造函数
	~MyStack(void);//析构函数
	void push(int);
	int pop();
	std::string toString();
};

