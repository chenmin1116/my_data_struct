#pragma once 
#include<iostream>
#include<vector>
#include <Windows.h>
using namespace std;

template<class T>
class ObjectPool
{
	
	struct BlockNode
	{
		void* _memory;    //内存块
		BlockNode* _next;   //指向下一个节点的指针
		size_t _objectnumber;  //可用内存对象个数

		BlockNode(size_t objectnumber)
			:_objectnumber(objectnumber)
			,_next(NULL)
		{
			_memory = malloc(_itemsize * objectnumber);
		}

		~BlockNode()
		{
			free(_memory);
			_memory = NULL;
		}
	};
	
protected:
	size_t _CountIn;  //当前所用的节点计数
	BlockNode* _first;
	BlockNode* _last;
	size_t  _MaxNum;    //节点申请内存块的对象个数
    static size_t _itemsize;   //单个对象的个数
	T* _lastDelete;     //指向最后一个所释放的对象

public:
	ObjectPool(size_t initNum = 32,size_t MaxNum = 100000)
		:_CountIn(0)
		,_MaxNum(MaxNum)
		,_lastDelete(NULL)
		//,_itemsize(sizeof(T))
	{
		_first = _last = new BlockNode(initNum);
	}

	void AllocateNewNode()
	{
		size_t objnum = _CountIn*2;
		if(objnum>_MaxNum)
			objnum = _MaxNum;
		_last->_next = new BlockNode(objnum);
		_CountIn = 0;
		_last = _last->_next;

	}


	T* New()
	{
		//1.优先考虑以前释放的空间；
		//2.在内存块中申请空间；
		//3.申请新的节点对象；
		if(_lastDelete)
		{
			T* obj = _lastDelete;
			_lastDelete = *((T**) _lastDelete);
			return new(obj)T;
		}

		if(_CountIn >= _last->_objectnumber)
		{
			AllocateNewNode();
		}
		T* obj = (T*)((char*)_last->_memory + _CountIn*_itemsize);
		_CountIn++;
		return new(obj)T();
	}
	void Delete(T* ptr)
	{
		if(ptr)
		{
			ptr->~T();
			*((T**)ptr) = _lastDelete;
			_lastDelete = ptr;
		}
	}
	void Destroy()
	{
		BlockNode* cur = _first;
		while(cur)
		{
			BlockNode* del = cur;
			cur = cur->_next;
			delete del;
			_CountIn = 0;
			_first = _last = NULL;
			if(_lastDelete)
			{
				cout<<"内存泄漏！！！"<<endl;
			}
		}
	}

	~ObjectPool()
	{
		Destroy();
	}

	static size_t InitItemsize()
   {
	if(sizeof(T) >= sizeof(T*))
		return sizeof(T);
	else
		return sizeof(T*);
   }
};
template<class T>
size_t ObjectPool<T>::_itemsize = ObjectPool<T>::InitItemsize();




///////////////////////////////////////////////////////////
// 测试内存对象池的常规使用和内存对象的重复使用
void TestObjectPool()
{
	vector<string*> v;

	ObjectPool<string> pool;
	for (size_t i = 0; i < 32; ++i)
	{
		v.push_back(pool.New());
		printf("Pool New [%d]: %p\n", i, v.back());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < 32; ++i)
	{
		v.push_back(pool.New());
		printf("Pool New [%d]: %p\n", i, v.back());
	}

	v.push_back(pool.New());
}



// 针对当前的内存对象池进行简单的性能测试
void TestObjectPoolOP()
{
	size_t begin , end;
	vector<string*> v;
	const size_t N = 1000000;
	v.reserve(N);

	cout<<"pool new/delete==============================="<<endl;
	// 反复申请释放5次
	begin = GetTickCount();
	ObjectPool<string> pool;
	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}


	end = GetTickCount();
	cout<<"Pool:"<<end - begin<<endl;

	cout<<"new/delete==============================="<<endl;
	begin = GetTickCount();

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	end = GetTickCount();
	cout<<"new/delete:"<<end - begin<<endl;
}
