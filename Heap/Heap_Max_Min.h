#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Heap
{
private:
	vector<T> _a;
public:
	Heap(T* a,int size)
	{
		_a.reserve(size);
		for(int i=0;i<size;i++)
		{
			_a.push_back(a[i]);
		}
		for(int i=0;i<(size-2)/2;i++)
		{
			AdjustDown(i);
		}
	}
	void AdjustDown(size_t root)
	{
		size_t parent = root;
		size_t child = 2*parent + 1;
		while(child < _a.size()-1)
		{
            child = 2*parent + 1;
			if( (_a[child+1]>_a[child]) && (child+1<_a.size()) )
			{child++;}
			
			if(_a[child] > _a[parent])
			{
				swap(_a[child],_a[parent]);
				parent = child;
			}
			else
			{break;}
	   }
	}
	void AdjustUp(size_t child)
	{
		size_t parent = (child-1)/2;
		while(parent>0)
		{
			parent = (child-1)/2;
            if(_a[child] > _a[parent])
			{
				swap(_a[child],_a[parent]);
				child = parent;
			}

			else
			{
				break;
			}
		}

	}
public:
	void Pop();
	void Push(const T& x);
	size_t Size();
	bool Empty();
	void Print();
};

template<typename T>
void Heap<T>:: Pop()
{
	swap(_a[0],_a[_a.size()-1]);
	_a.pop_back();
	AdjustDown(0);
}

template<typename T>
void Heap<T>:: Push(const T& x)
{
	_a.push_back(x);
	AdjustUp(_a.size()-1);
}

template<typename T>
size_t Heap<T>:: Size()
{
	return _a.size();
}

template<typename T>
bool Heap<T>:: Empty()
{
	return _a.empty();
}

template<typename T>
void Heap<T>:: Print()
{
	for(int i=0;i<_a.size();i++)
	{
		cout<<_a[i]<<" ";
	}
cout<<endl;
}