//ʹ����������ʵ��һ��ջ��
//ջ���Ƚ���������У��Ƚ��ȳ���
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
		if(queue1.empty() == true && queue2.empty() == true)//���������о�Ϊ��ʱ,�������ݵ�ʱ��ѡ��queue1��
		{
			queue1.push(node);
		}
		else
		{
			if(queue1.empty() == true && queue2.empty() == false)//queue1Ϊ�գ�queue2��Ϊ�գ�
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
		//��queue1��queue2��Ϊ��ʱ��
		if(queue1.empty() == true && queue2.empty() == true)
		{cout<<"ջΪ�գ��޷����д˲���������"<<endl;return;}
		//queue1Ϊ��ʱ:��queue2�е��������β���queue1�У����ҽ�queue2�е�ǰn-1������pop();
		//�������һ��pop������ɳ�ջ������
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
   stack1.Push(1); //���ڿ�ջ���в���
   stack1.Push(2);//���ڷǿ�ջ���в���
   stack1.Push(3);
   stack1.Push(4);//1 2 3 4���ڿ�ջ���������Ĳ��������
   stack1.Pop();//1 2 3//���ڷǿ�ջ���г�ջ������
   stack1.Pop();//1 2
   stack1.Pop();//1
   stack1.Pop();//���ڿ�ջ����������ջ������ֱ�����ջΪ�գ�
   stack1.Pop();//���ڿ�ջ���г�ջ����
}