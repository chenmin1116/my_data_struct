//题目：使用两个栈实现一个队列
#pragma once
#include<iostream>
#include<stack>
using namespace std;

template <class T>
class Queue
{
public:
	stack<T> stack1;
	stack<T> stack2;
public:
	Queue()
	{}
	~Queue()
	{}
	void appendTail(const T& node)    //直接对于stack1插入元素即可；
	{
		stack1.push(node);
	}
	void deleteHead()        //队头删除元素；
	{
		if(stack1.empty() == true && stack2.empty() == true)  //当stack1和stack2都为空时;
		{
			cout<<"此队列为空！！！"<<endl;
			return;
		}
		if(stack2.empty() == true)    //当stack2为空的时候：将stack1中的元素pop并且push到stack2中，并将stack2中的栈顶元素pop即可；
		{
			while(stack1.empty() != true)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			stack2.pop();
			return;
		}
		else//当stack2不为空时：直接将stack2中的栈顶元素pop即可；
		{
			  stack2.pop();
			  return;
		}
	}
};

void TestDoubleStackToQueue1()  
{
	Queue<int> queue1;
	queue1.appendTail(1);//对于空队列进行添加元素；
	queue1.appendTail(2);//对于非空队列进行插入元素；
	queue1.appendTail(3);
	queue1.appendTail(4);
	queue1.appendTail(5);
    queue1.deleteHead();//对于非空队列进行删除元素；并且连续删除直至队列为空；
	queue1.deleteHead();
	queue1.deleteHead();
	queue1.deleteHead();
	queue1.deleteHead();
	queue1.deleteHead();//对于空队列进行删除操作
}
	