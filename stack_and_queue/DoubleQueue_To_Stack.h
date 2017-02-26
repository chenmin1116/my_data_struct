//使用两个队列实现一个栈；
//栈：先进后出；队列：先进先出；
#pragma once
#include<iostream>
#include<queue>
using namespace std;

template<class T>
class Stack
{
private:
	queue<T> queue1;
	queue<T> queue2;
public:
	void Push(const T& node)
	{
		if(queue1.empty() == true && queue2.empty() == true)//当两个队列均为空时,输入数据的时候选择queue1；
		{
			queue1.push(node);
		}
		else
		{
			if(queue1.empty() == true && queue2.empty() == false)//queue1为空，queue2不为空；
			{
				queue2.push(node);
			}
			if(queue1.empty() == false && queue2.empty() == true)
			{
				queue1.push(node);
			}
		}
	}
	void Pop()
	{
		//当queue1和queue2均为空时：
		if(queue1.empty() == true && queue2.empty() == true)
		{cout<<"栈为空，无法进行此操作！！！"<<endl;return;}
		//queue1为空时:将queue2中的数据依次插入queue1中，并且将queue2中的前n-1个数据pop();
		//并将最后一个pop（）完成出栈操作；
		if(queue1.empty() == true && queue2.empty() == false)
		{   
			while(queue2.size()-1 > 0)
			{
				queue1.push(queue2.front());
				queue2.pop();
			}
			queue2.pop();
			return;
		}
		if(queue1.empty() == false && queue2.empty() == true)
		{
			while(queue1.size()-1 > 0)
			{
				queue2.push(queue1.front());
				queue1.pop();
			}
			queue1.pop();
			return;
		}
	}
};


void DoubleQueue_To_Stack()
{
   Stack<int> stack1;
   stack1.Push(1); //对于空栈进行插入
   stack1.Push(2);//对于非空栈进行插入
   stack1.Push(3);
   stack1.Push(4);//1 2 3 4对于空栈进行连续的插入操作；
   stack1.Pop();//1 2 3//对于非空栈进行出栈操作；
   stack1.Pop();//1 2
   stack1.Pop();//1
   stack1.Pop();//对于空栈进行连续出栈操作，直到这个栈为空；
   stack1.Pop();//对于空栈进行出栈操作
}