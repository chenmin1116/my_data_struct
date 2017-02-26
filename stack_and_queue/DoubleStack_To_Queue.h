//��Ŀ��ʹ������ջʵ��һ������
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
	void appendTail(const T& node)    //ֱ�Ӷ���stack1����Ԫ�ؼ��ɣ�
	{
		stack1.push(node);
	}
	void deleteHead()        //��ͷɾ��Ԫ�أ�
	{
		if(stack1.empty() == true && stack2.empty() == true)  //��stack1��stack2��Ϊ��ʱ;
		{
			cout<<"�˶���Ϊ�գ�����"<<endl;
			return;
		}
		if(stack2.empty() == true)    //��stack2Ϊ�յ�ʱ�򣺽�stack1�е�Ԫ��pop����push��stack2�У�����stack2�е�ջ��Ԫ��pop���ɣ�
		{
			while(stack1.empty() != true)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			stack2.pop();
			return;
		}
		else//��stack2��Ϊ��ʱ��ֱ�ӽ�stack2�е�ջ��Ԫ��pop���ɣ�
		{
			  stack2.pop();
			  return;
		}
	}
};

void TestDoubleStackToQueue1()  
{
	Queue<int> queue1;
	queue1.appendTail(1);//���ڿն��н������Ԫ�أ�
	queue1.appendTail(2);//���ڷǿն��н��в���Ԫ�أ�
	queue1.appendTail(3);
	queue1.appendTail(4);
	queue1.appendTail(5);
    queue1.deleteHead();//���ڷǿն��н���ɾ��Ԫ�أ���������ɾ��ֱ������Ϊ�գ�
	queue1.deleteHead();
	queue1.deleteHead();
	queue1.deleteHead();
	queue1.deleteHead();
	queue1.deleteHead();//���ڿն��н���ɾ������
}
	