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
		void* _memory;    //�ڴ��
		BlockNode* _next;   //ָ����һ���ڵ��ָ��
		size_t _objectnumber;  //�����ڴ�������

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
	size_t _CountIn;  //��ǰ���õĽڵ����
	BlockNode* _first;
	BlockNode* _last;
	size_t  _MaxNum;    //�ڵ������ڴ��Ķ������
    static size_t _itemsize;   //��������ĸ���
	T* _lastDelete;     //ָ�����һ�����ͷŵĶ���

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
		//1.���ȿ�����ǰ�ͷŵĿռ䣻
		//2.���ڴ��������ռ䣻
		//3.�����µĽڵ����
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
				cout<<"�ڴ�й©������"<<endl;
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
// �����ڴ����صĳ���ʹ�ú��ڴ������ظ�ʹ��
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



// ��Ե�ǰ���ڴ����ؽ��м򵥵����ܲ���
void TestObjectPoolOP()
{
	size_t begin , end;
	vector<string*> v;
	const size_t N = 1000000;
	v.reserve(N);

	cout<<"pool new/delete==============================="<<endl;
	// ���������ͷ�5��
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
