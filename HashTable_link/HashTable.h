//#pragma once
//#include<iostream>
//#include<vector>
//using namespace std;
////使用标识位标记每个节点存放数据的状态
//enum Status
//{
//	EXIST,
//	EMPTY,
//	DELETE,
//};
//
////定义哈希表的节点
//template<class K,class V>
//struct HashTableNode
//{
//	K _key;
//	V _value;
//	Status _status;
//	HashTableNode(const K& key = K(),const V& value = V())
//		:_key(key)
//		,_value(value)
//		,_status(EMPTY)
//	{}
//};
//
////定义哈希表的结构
//template<class K,class V>
//class HashTable
//{typedef  HashTableNode<K,V> Node;
//
//private:
//	vector<Node> _vec;
//	size_t _size;
//
//protected:
//
//   //交换两个散列表中的内容
//	void SwapHashTable(HashTable<K,V>& _table1)
//	{
//		this->_vec.swap(_table1._vec);
//		_size =_table1._vec .size();
//	}
//	
//	size_t GetIndex(const K& key)
//	{return key%this->_vec.size();}
//	
//	size_t _GetNextPrime(size_t num)
//	{
//	//使用素数表对齐做哈希1表的容量，降低哈希冲突
//		const int _PrimeSize= 28;
//		static const unsigned long _PrimeList[_PrimeSize] =
//		{
//		53ul, 97ul, 193ul, 389ul, 769ul,
//		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
//		49157ul, 98317ul, 196613ul, 393241ul,
//		786433ul,
//		1572869ul, 3145739ul, 6291469ul, 12582917ul,
//		25165843ul,
//		50331653ul, 100663319ul, 201326611ul, 402653189ul,
//		805306457ul,
//		1610612741ul, 3221225473ul, 4294967291ul
//		};
//			//vector<HashTableNode> _vec1;
//		
//			//NewSize = 0;
//			for(int i=0;i<_PrimeSize;i++)
//			{
//				if(_PrimeList[i] > num)
//				{
//					return  _PrimeList[i];
//				}
//		    }
//		//for(int i=0;i<_size;i++)   //将原来散列表中的内容拷贝到临时创建的散列表
//		//{
//		//	if(_vec[i]._status == EXIST)
//		//	{
//		//		int tmp_index = _vec[i]._key%_vec1.size();
//		//		_vec1[tmp_index]._key = _vec[i]._key;
//		//		_vec1[tmp_index]._value = _vec[i]._value;
//		//		_vec1[tmp_index]._status = EXIST;
//		//	}
//		//}
//		//this->SwapHashTable(_vec1);
//    }
//
//	void _CheckSize()
//	{
//		if((this->_vec.size()==0)||(this->_size*10/this->_vec.size()>=7))
//		{
//			size_t NewSize = _GetNextPrime(this->_vec.size());
//			//构建一个临时的散列表，将原散列表的内容插入，并且和原来的散列表作交换，达到扩容的效果；
//			HashTable<K,V> _table1;
//			_table1._vec.resize(NewSize);
//			//将原来散列表中的数据按照规则，拷贝到_vec1中；
//			for(size_t i=0;i<this->_vec.size();i++)
//			{
//				if(this->_vec[i]._status == EXIST)//只处理原来散列表中状态为EXIST的；其他的默认为空；
//				{
//				   size_t index = this->_vec[i]._key%NewSize;
//				   if(_table1._vec[index]._status == EMPTY)
//				   {
//					   //当状态为空时，直接插入
//					   _table1._vec[index]._key = this->_vec[i]._key;
//					   _table1._vec[index]._value = this->_vec[i]._value;
//					   _table1._vec[index]._status = EXIST;
//				   }
//				   else
//				   {
//					   while(_table1._vec[index]._status == EXIST)
//					   {index++;}
//					   _table1._vec[index]._key = this->_vec[i]._key;
//					   _table1._vec[index]._value = this->_vec[i]._value;
//					   _table1._vec[index]._status = EXIST;
//				   }
//				}
//			}
//			//数据拷贝完毕，交换两个散列表，实现扩容；
//			SwapHashTable(_table1);
//		}
//		else
//			return;
//	}
//public:
//	HashTable()
//		:_size(0)
//	{
//		_vec.resize(_GetNextPrime(0));
//	}
//	//拷贝构造
//	//析构函数
//
//
//	//插入节点
//	//1,检查容量
//	//2.检查是否插入冲突；
//	//3.当没有冲突时，直接插入
//	//4.当发生冲突时，找下一个状态为EMPTY的节点插入；
//	//5.当负载因子>=0.7的时候进行增容，实现以空间换时间；
//	//6.负载因子 = 填入表中的元素个数/散列表的长度；
//	//7.进行增容时：散列表的大小设置为素数，不容易发生冲突；
//	void Insert(const K& key,const V& value)
//	{
//		size_t index = GetIndex(key);
//		if(this->_vec.size() == 0)
//		{
//			_CheckSize();//增容
//			Insert(key,value);//重新插入
//		}
//		else
//		{
//			
//			if(this->_size*10/this->_vec.size() <7 )    //当负载因子小于0.7 的时候进行插入
//			{
//				if(this->_vec[index]._status == EMPTY || this->_vec[index]._status == DELETE)  //当index的位置可以插入时
//				{
//					this->_vec[index]._key = key;
//					this->_vec[index]._value = value;
//					this->_vec[index]._status = EXIST;
//					_size++;
//				}
//
//				else  //当index的位置已经被占
//				{
//					while(this->_vec[index]._status == EXIST)
//					{
//						if(index == this->_vec.size())
//						{index = 0;}
//						index++;
//					}    
//					//找到下一个状态不为EXIST
//					this->_vec[index]._key = key;
//					this->_vec[index]._value = value;
//					this->_vec[index]._status = EXIST;
//
//				}
//			}
//
//			else
//			{
//				_CheckSize();//增容
//				Insert(key,value);//重新插入
//			}
//		}
//	}
//	//1.先从index到_vec.size()之间找，若是找到了，返回节点的地址
//	//2.若还是没有找到，从0到index的区间中找，若是找到了，直接返回节点的地址；
//	//3.若是没有找到。直接返回NULL。
//
//	Node* Find(const K& key)
//	{
//		size_t index = key%this->_vec.size();
//		for(size_t i=index;i<=this->_vec.size();i++)
//		{
//			if(this->_vec[i]._key == key)
//			{
//				return &_vec[i] ;
//			}
//		}
//
//		size_t src = index;//记录key的初始index
//		for(index=0;index<src;index++)
//		{
//			if(this->_vec[index]._key == key)
//			{
//				return &_vec[index];
//			}
//		}
//		return NULL;
//	}
//
//	//1.若是没有找到，直接返回false;
//	//若是找到了，将节点的状态标识位置为DELETE，并将size--;
//	bool Remove(const K& key)
//	{
//		Node* del = Find(key);
//		if(del == NULL)
//		{return false;}
//		else
//		{
//			 del->_status = DELETE;
//			_size--;
//			return true;
//		}
//	}
//};
//
//
//void TestHashTable1()
//{
//	HashTable<int,int> ht1;
//	int a[] = {89,18,49,58,9};
//	for(size_t i=0;i<sizeof(a)/sizeof(a[0]);++i)
//	{
//		ht1.Insert(a[i],i);
//	}
//	cout<<"删除之前查找："<<ht1.Find(18)<<endl;
//	cout<<"删除："<<ht1.Remove(18)<<endl;
//	cout<<"删除之后再进行查找："<<ht1.Find(89) <<endl;
//}


//利用开链法来解决哈希冲突
#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//定义HashTable的节点信息
template<class K,class V>
struct HashTableNode
{
	K _key;
	V _value;
	HashTableNode<K,V>* _next;
	HashTableNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		,_next(NULL)
	{}
};


template<class K>
struct __HashFunc
{
	size_t operator()(const K& key)
	{
		return  key;
	}
};

template<>
struct __HashFunc<string>
{
	static size_t BKDRHash(const char* str)
	{
		unsigned int seed= 131;// 31 131 1313 13131 131313
		unsigned int hash= 0;
		while(*str)
		{
			hash=hash*seed+(*str++);
		}
		return(hash& 0x7FFFFFFF);
	}

    size_t operator()(const string& str)
	{
		return BKDRHash(str.c_str());
	}
};

//定义HashTable
//使用开链法进行定义，防止哈希冲突
//所谓开链法就是将冲突的Key值，连载同一个key值得链表下；
template<class K,class V,class HashFunc = __HashFunc<K>>
class HashTable
{
	typedef  HashTableNode<K,V> Node;
private:
	vector<Node*> _tables;
	size_t _size;
protected:
	void _CheckSize()
	{
		//当哈希表的容量为0或者当哈希表的平均元素数目与哈希表的容量相等
		//(
		//if(this->_tables.size() == 0 || this->_size == this->_tables.size())
		//{
		//	size_t NewSize = this->_GetNextPrime(_tables.size());
		//	HashTable<K,v> hte;
		//	hte._tables.resize(NewSize);
		//	for(int i=0;i<this->_tables.size();i++)  //将原来散列表中的内容拷贝到临时创建的散列表中
		//	{
		//		if(this->_tables[i] != NULL)
		//		{
		//			hte.
		//		}
		//	}
		//}
	}
	//仿函数
	size_t _HashFunc(const K& key)
	{return (key) % this->_tables.size();}
	
	size_t _GetNextPrime(size_t num)
	{
	   //使用素数表对齐做哈希表的容量，降低哈希冲突
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
			
		for(int i=0;i<_PrimeSize;i++)
		{
			if(_PrimeList[i] > num)
			{
				return  _PrimeList[i];
			}
		}
	}
public:
	HashTable()
		:_size(0)
		
	{
		_tables.resize(53);
	}
	//拷贝构造
	void Insert(const K& key,const V& value)
	{
		//首先插入选择的方式为头插得方式，进行插入（哈希表不考虑数据进入的顺序）
		//（1）先调用_CheckSize()函数考虑是否要进行增容；
		//（2）插入头结点；
		//（3）插入其他节点
		//（4）对于_size要进行设置
		if(this->Find(key) != NULL)
		{return;}
		else
		{
			this->_CheckSize();
			size_t index = this->_HashFunc(key);
			if(_tables[index] == NULL)
			{
				_tables[index] = new Node(key,value);
				++this->_size;
			}
			else
			{
				Node* tmp = new Node(key,value);
				tmp->_next =_tables[index];
				_tables[index] = tmp; 
				++this->_size ;
			}
		}
	}
	Node* Find(const K& key)
	{
		//确定key值，所对应的vector存放的位置，
		//定义一个指针，在所对应的位置下的链表进行查找；
		//如果找到，返回指向key的指针；
		//如果没有找到，则返回NULL；
		size_t index = this->_HashFunc(key);
		Node* cur = _tables[index];
		if(cur == NULL)                       //当key所对应的位置没有存数据时，返回NULL；
		{return NULL;}
		else                                  //当key所对应的位置存了数据时，开始查找；
		{
			while(cur)
			{
				if(cur->_key == key)          //找到了，返回指向key值的指针；
					return cur;
				else
					cur = cur->_next ;        //当cur不等于NULL而且没有找到的情况下继续查找；
			}
		}
		return NULL;            //在key所对应位置的链表中没有找到
		
	}
	bool Remove(const K& key)
	{
		//当删除的节点不存在时，返回false；
		//当删除的节点存在时：
		//删除分为两种可能；
		//（1）删除头结点；
		//（2）删除中间节点或者尾节点；
		//（3）调用_HashFunc(const K& key),确定位置；
		//   1>定义一个prev指针和一个cur指针，确定key值得前后，
		//   2>进行指针交换，实现删除
		//返回true；
		if(this->Find(key) == NULL)
			return false;
		else
		{
			size_t index = this->_HashFunc(key);
			Node* prev = NULL;
			Node* cur = _tables[index];
			if(cur->_key == key)   //删除的是头结点
			{
			_tables[index] = cur->_next;
			delete cur;
			cur = NULL;
			--this->_size;
			return true;
			}
			while(cur)
			{
				prev = cur;
				cur = cur->_next;
				if(cur->_key == key)
				{
					prev->_next = cur->_next ;
					delete cur;
					cur = NULL;
					--this->_size;
					return true;
				}
			}
		}
		return false;
	}
};

void TestHashBKDR()
{
	HashTable<int,int> ht;
	int a[] = {89,18,49,58,9,62,17,71};
	for(size_t i=0;i<sizeof(a)/sizeof(a[0]);++i)
	{
		ht.Insert(a[i],i);
	}
	cout<<ht.Find(18)<<endl;
	cout<<ht.Find (17)<<endl;
	cout<<ht.Find(9)<<endl;
	cout<<ht.Remove(89)<<endl;
	cout<<ht.Remove(18)<<endl;
	cout<<ht.Find (18)<<endl;
}

void TestHashBKDRString()
{
	HashTable<string,int,__HashFunc<string>> ht1;
	string  a[] = {"star","your","hero","flag"};
	for(size_t i =0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		ht1.Insert(a[i],i);
	}
}