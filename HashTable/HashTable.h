#pragma once
#include<iostream>
#include<vector>
using namespace std;
//使用标识位标记每个节点存放数据的状态
enum Status
{
	EXIST,
	EMPTY,
	DELETE,
};

//定义哈希表的节点
template<class K,class V>
struct HashTableNode
{
	K _key;
	V _value;
	Status _status;
	HashTableNode(const K& key = K(),const V& value = V())
		:_key(key)
		,_value(value)
		,_status(EMPTY)
	{}
};

//定义哈希表的结构
template<class K,class V>
class HashTable
{typedef  HashTableNode<K,V> Node;

private:
	vector<Node> _vec;
	size_t _size;

protected:

   //交换两个散列表中的内容
	void SwapHashTable(HashTable<K,V>& _table1)
	{
		this->_vec.swap(_table1._vec);
		_size =_table1._vec .size();
	}
	
	size_t GetIndex(const K& key)
	{return key%this->_vec.size();}
	
	size_t _GetNextPrime(size_t num)
	{
	//使用素数表对齐做哈希1表的容量，降低哈希冲突
		const int _PrimeSize= 28;
		static const unsigned long _PrimeList[_PrimeSize] =
		{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul,
		786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul,
		25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul,
		805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
		};
			//vector<HashTableNode> _vec1;
		
			//NewSize = 0;
			for(int i=0;i<_PrimeSize;i++)
			{
				if(_PrimeList[i] > num)
				{
					return  _PrimeList[i];
				}
		    }
		//for(int i=0;i<_size;i++)   //将原来散列表中的内容拷贝到临时创建的散列表
		//{
		//	if(_vec[i]._status == EXIST)
		//	{
		//		int tmp_index = _vec[i]._key%_vec1.size();
		//		_vec1[tmp_index]._key = _vec[i]._key;
		//		_vec1[tmp_index]._value = _vec[i]._value;
		//		_vec1[tmp_index]._status = EXIST;
		//	}
		//}
		//this->SwapHashTable(_vec1);
    }

	void _CheckSize()
	{
		if((this->_vec.size()==0)||(this->_size*10/this->_vec.size()>=7))
		{
			size_t NewSize = _GetNextPrime(this->_vec.size());
			//构建一个临时的散列表，将原散列表的内容插入，并且和原来的散列表作交换，达到扩容的效果；
			HashTable<K,V> _table1;
			_table1._vec.resize(NewSize);
			//将原来散列表中的数据按照规则，拷贝到_vec1中；
			for(size_t i=0;i<this->_vec.size();i++)
			{
				if(this->_vec[i]._status == EXIST)//只处理原来散列表中状态为EXIST的；其他的默认为空；
				{
				   size_t index = this->_vec[i]._key%NewSize;
				   if(_table1._vec[index]._status == EMPTY)
				   {
					   //当状态为空时，直接插入
					   _table1._vec[index]._key = this->_vec[i]._key;
					   _table1._vec[index]._value = this->_vec[i]._value;
					   _table1._vec[index]._status = EXIST;
				   }
				   else
				   {
					   while(_table1._vec[index]._status == EXIST)
					   {index++;}
					   _table1._vec[index]._key = this->_vec[i]._key;
					   _table1._vec[index]._value = this->_vec[i]._value;
					   _table1._vec[index]._status = EXIST;
				   }
				}
			}
			//数据拷贝完毕，交换两个散列表，实现扩容；
			SwapHashTable(_table1);
		}
		else
			return;
	}
public:
	HashTable()
		:_size(0)
	{
		_vec.resize(_GetNextPrime(0));
	}
	//拷贝构造
	//析构函数


	//插入节点
	//1,检查容量
	//2.检查是否插入冲突；
	//3.当没有冲突时，直接插入
	//4.当发生冲突时，找下一个状态为EMPTY的节点插入；
	//5.当负载因子>=0.7的时候进行增容，实现以空间换时间；
	//6.负载因子 = 填入表中的元素个数/散列表的长度；
	//7.进行增容时：散列表的大小设置为素数，不容易发生冲突；
	void Insert(const K& key,const V& value)
	{
		size_t index = GetIndex(key);
		if(this->_vec.size() == 0)
		{
			_CheckSize();//增容
			Insert(key,value);//重新插入
		}
		else
		{
			
			if(this->_size*10/this->_vec.size() <7 )    //当负载因子小于0.7 的时候进行插入
			{
				if(this->_vec[index]._status == EMPTY || this->_vec[index]._status == DELETE)  //当index的位置可以插入时
				{
					this->_vec[index]._key = key;
					this->_vec[index]._value = value;
					this->_vec[index]._status = EXIST;
					_size++;
				}

				else  //当index的位置已经被占
				{
					while(this->_vec[index]._status == EXIST)
					{
						if(index == this->_vec.size())
						{index = 0;}
						index++;
					}    
					//找到下一个状态不为EXIST
					this->_vec[index]._key = key;
					this->_vec[index]._value = value;
					this->_vec[index]._status = EXIST;

				}
			}

			else
			{
				_CheckSize();//增容
				Insert(key,value);//重新插入
			}
		}
	}
	//1.先从index到_vec.size()之间找，若是找到了，返回节点的地址
	//2.若还是没有找到，从0到index的区间中找，若是找到了，直接返回节点的地址；
	//3.若是没有找到。直接返回NULL。

	Node* Find(const K& key)
	{
		size_t index = key%this->_vec.size();
		for(size_t i=index;i<=this->_vec.size();i++)
		{
			if(this->_vec[i]._key == key)
			{
				return &_vec[i] ;
			}
		}

		size_t src = index;//记录key的初始index
		for(index=0;index<src;index++)
		{
			if(this->_vec[index]._key == key)
			{
				return &_vec[index];
			}
		}
		return NULL;
	}

	//1.若是没有找到，直接返回false;
	//若是找到了，将节点的状态标识位置为DELETE，并将size--;
	bool Remove(const K& key)
	{
		Node* del = Find(key);
		if(del == NULL)
		{return false;}
		else
		{
			 del->_status = DELETE;
			_size--;
			return true;
		}
	}
};


void TestHashTable1()
{
	HashTable<int,int> ht1;
	int a[] = {89,18,49,58,9};
	for(size_t i=0;i<sizeof(a)/sizeof(a[0]);++i)
	{
		ht1.Insert(a[i],i);
	}
	cout<<"删除之前查找："<<ht1.Find(18)<<endl;
	cout<<"删除："<<ht1.Remove(18)<<endl;
	cout<<"删除之后再进行查找："<<ht1.Find(18)<<endl;
}