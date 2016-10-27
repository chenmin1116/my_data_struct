//1. ʵ��һ��ջ��Ҫ��ʵ��Push����ջ����Pop����ջ����Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO(1)
//��һ�ֽⷨ
#pragma once
#include<iostream>
#include<cassert>
using namespace std;

template <typename T> 
class Min_Stack
{
private:
	T *top;
	int _sz;
	int _capacity;
protected:
	void CheckCapacity();
public:
	Min_Stack();
	~Min_Stack();
	T GetTop();
	void Pop();
	void Push(const T x);
	T  Min();
	void Print();
	
};

template <typename T> 
Min_Stack<T>::Min_Stack()
	:top(NULL)
	,_sz(0)
	,_capacity(0)
{}
template <typename T> 
Min_Stack<T>::~Min_Stack()
{
	assert(top);
	delete[] top;
	top = NULL;
	
}
template <typename T> 
T Min_Stack<T>:: GetTop()
{ if(top == NULL)
  {
	  return -1;
  }
 else
 {
	return this->top[--this->_sz];
 }
}
template <typename T> 
void Min_Stack<T>::Pop()
{
	assert(top);
	this->_sz--;

}
template <typename T>
void Min_Stack<T>:: CheckCapacity()
{
	if(this->_capacity == this->_sz)
	{
		int NewCapacity = this->_capacity * 2+5;
		int *tmp = new T[NewCapacity];
	    //memcpy(tmp,top,sizeof(T)*this->_sz);
		for(int i=0;i<this->_sz;i++)
		{
			tmp[i] = top[i];
		}
		delete [] top;
		top = tmp;
		this->_capacity = NewCapacity; 
	}
}

template <typename T> 
void Min_Stack<T>:: Push(const T x)
{
	
	if(top == NULL)
	{
		CheckCapacity();
		top[_sz] = x;
		this->_sz++;
	}
	else
	{
		CheckCapacity();
		if(x > this->GetTop())
	   {
			this->_sz++;    //GetTop()���������ĸ�����
			T tmp = this->GetTop();
			this->_sz++;    //GetTop()���������ĸ�����
			this->Pop();
			top[_sz] = x;
			this->_sz++;
			top[_sz] = tmp;
			this->_sz++;
	
	   }
		else
		{
			top[_sz] = x;
			this->_sz ++;
		}
	}
}

template <typename T>
T Min_Stack<T>:: Min()
{
	return  *(top+_sz-1);
}

template <typename T> 
void Min_Stack<T>:: Print()
{
	for(int i=this->_sz-1;i>=0;i--)
	{
		cout<<this->top[i]<<" ";
	}
	cout<<endl;
}

//�ڶ��ֽⷨ

//#pragma once
//#include<iostream>
//#include<cassert>
//using namespace std;
//
//template <typename T> 
//class Min_Stack
//{
//private:
//	T *top;
//	int _sz;
//	int _capacity;
//protected:
//	void CheckCapacity();
//public:
//	Min_Stack();
//	~Min_Stack();
//	T GetTop();
//	void Pop();
//	void Push(const T x,Min_Stack<T>& stack2);
//	void Print();
//	
//};
//
//template <typename T> 
//Min_Stack<T>::Min_Stack()
//	:top(NULL)
//	,_sz(0)
//	,_capacity(0)
//{}
//template <typename T> 
//Min_Stack<T>::~Min_Stack()
//{
//	assert(top);
//	delete[] top;
//	top = NULL;
//	
//}
//template <typename T> 
//T Min_Stack<T>:: GetTop()
//{ if(top == NULL)
//  {
//	  return -1;
//  }
// else
// {
//	return this->top[--this->_sz];
// }
//}
//template <typename T> 
//void Min_Stack<T>::Pop()
//{
//	assert(top);
//	this->_sz--;
//
//}
//template <typename T>
//void Min_Stack<T>:: CheckCapacity()
//{
//	if(this->_capacity == this->_sz)
//	{
//		int NewCapacity = this->_capacity * 2+5;
//		int *tmp = new T[NewCapacity];
//	    //memcpy(tmp,top,sizeof(T)*this->_sz);
//		for(int i=0;i<this->_sz;i++)
//		{
//			tmp[i] = top[i];
//		}
//		delete [] top;
//		top = tmp;
//		this->_capacity = NewCapacity; 
//	}
//}
//
//template <typename T> 
//void Min_Stack<T>:: Push(const T x,Min_Stack<T>& stack2)
//{
//	if(top == NULL)               //��������ջ�ֱ�����һ��Ԫ��
//	{
//		this->CheckCapacity();
//		stack2.CheckCapacity();
//
//		this->top[this->_sz] = x;
//    	this->_sz++;
//
//		stack2.top[stack2._sz] = x;
//		stack2._sz++;
//	}
//	else
//	{
//		this->CheckCapacity();
//		stack2.CheckCapacity();
//		if(x>this->GetTop())
//		{
//			this->_sz++;
//			this->top[this->_sz] = x;
//			this->_sz++;
//		}
//		else
//		{
//			this->_sz++;
//			this->top[this->_sz] = x;
//			this->_sz++;
//
//			stack2.Pop();
//			stack2.top[stack2._sz] = x;
//			stack2._sz++;
//
//		}
//	}
//}
//
//template <typename T> 
//void Min_Stack<T>:: Print()
//{
//	for(int i=this->_sz-1;i>=0;i--)
//	{
//		cout<<this->top[i]<<" ";
//	}
//	cout<<endl;
//}
//
//
