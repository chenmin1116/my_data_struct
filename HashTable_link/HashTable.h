//#pragma once
//#include<iostream>
//#include<vector>
//using namespace std;
////ʹ�ñ�ʶλ���ÿ���ڵ������ݵ�״̬
//enum Status
//{
//	EXIST,
//	EMPTY,
//	DELETE,
//};
//
////�����ϣ���Ľڵ�
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
////�����ϣ���Ľṹ
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
//   //��������ɢ�б��е�����
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
//	//ʹ����������������ϣ1�������������͹�ϣ��ͻ
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
//		//for(int i=0;i<_size;i++)   //��ԭ��ɢ�б��е����ݿ�������ʱ������ɢ�б�
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
//			//����һ����ʱ��ɢ�б�����ԭɢ�б������ݲ��룬���Һ�ԭ����ɢ�б����������ﵽ���ݵ�Ч����
//			HashTable<K,V> _table1;
//			_table1._vec.resize(NewSize);
//			//��ԭ��ɢ�б��е����ݰ��չ��򣬿�����_vec1�У�
//			for(size_t i=0;i<this->_vec.size();i++)
//			{
//				if(this->_vec[i]._status == EXIST)//ֻ����ԭ��ɢ�б���״̬ΪEXIST�ģ�������Ĭ��Ϊ�գ�
//				{
//				   size_t index = this->_vec[i]._key%NewSize;
//				   if(_table1._vec[index]._status == EMPTY)
//				   {
//					   //��״̬Ϊ��ʱ��ֱ�Ӳ���
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
//			//���ݿ�����ϣ���������ɢ�б���ʵ�����ݣ�
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
//	//��������
//	//��������
//
//
//	//����ڵ�
//	//1,�������
//	//2.����Ƿ�����ͻ��
//	//3.��û�г�ͻʱ��ֱ�Ӳ���
//	//4.��������ͻʱ������һ��״̬ΪEMPTY�Ľڵ���룻
//	//5.����������>=0.7��ʱ��������ݣ�ʵ���Կռ任ʱ�䣻
//	//6.�������� = ������е�Ԫ�ظ���/ɢ�б��ĳ��ȣ�
//	//7.��������ʱ��ɢ�б��Ĵ�С����Ϊ�����������׷�����ͻ��
//	void Insert(const K& key,const V& value)
//	{
//		size_t index = GetIndex(key);
//		if(this->_vec.size() == 0)
//		{
//			_CheckSize();//����
//			Insert(key,value);//���²���
//		}
//		else
//		{
//			
//			if(this->_size*10/this->_vec.size() <7 )    //����������С��0.7 ��ʱ����в���
//			{
//				if(this->_vec[index]._status == EMPTY || this->_vec[index]._status == DELETE)  //��index��λ�ÿ��Բ���ʱ
//				{
//					this->_vec[index]._key = key;
//					this->_vec[index]._value = value;
//					this->_vec[index]._status = EXIST;
//					_size++;
//				}
//
//				else  //��index��λ���Ѿ���ռ
//				{
//					while(this->_vec[index]._status == EXIST)
//					{
//						if(index == this->_vec.size())
//						{index = 0;}
//						index++;
//					}    
//					//�ҵ���һ��״̬��ΪEXIST
//					this->_vec[index]._key = key;
//					this->_vec[index]._value = value;
//					this->_vec[index]._status = EXIST;
//
//				}
//			}
//
//			else
//			{
//				_CheckSize();//����
//				Insert(key,value);//���²���
//			}
//		}
//	}
//	//1.�ȴ�index��_vec.size()֮���ң������ҵ��ˣ����ؽڵ�ĵ�ַ
//	//2.������û���ҵ�����0��index���������ң������ҵ��ˣ�ֱ�ӷ��ؽڵ�ĵ�ַ��
//	//3.����û���ҵ���ֱ�ӷ���NULL��
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
//		size_t src = index;//��¼key�ĳ�ʼindex
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
//	//1.����û���ҵ���ֱ�ӷ���false;
//	//�����ҵ��ˣ����ڵ��״̬��ʶλ��ΪDELETE������size--;
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
//	cout<<"ɾ��֮ǰ���ң�"<<ht1.Find(18)<<endl;
//	cout<<"ɾ����"<<ht1.Remove(18)<<endl;
//	cout<<"ɾ��֮���ٽ��в��ң�"<<ht1.Find(89) <<endl;
//}


//���ÿ������������ϣ��ͻ
#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//����HashTable�Ľڵ���Ϣ
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

//����HashTable
//ʹ�ÿ��������ж��壬��ֹ��ϣ��ͻ
//��ν���������ǽ���ͻ��Keyֵ������ͬһ��keyֵ�������£�
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
		//����ϣ��������Ϊ0���ߵ���ϣ����ƽ��Ԫ����Ŀ���ϣ�����������
		//(
		//if(this->_tables.size() == 0 || this->_size == this->_tables.size())
		//{
		//	size_t NewSize = this->_GetNextPrime(_tables.size());
		//	HashTable<K,v> hte;
		//	hte._tables.resize(NewSize);
		//	for(int i=0;i<this->_tables.size();i++)  //��ԭ��ɢ�б��е����ݿ�������ʱ������ɢ�б���
		//	{
		//		if(this->_tables[i] != NULL)
		//		{
		//			hte.
		//		}
		//	}
		//}
	}
	//�º���
	size_t _HashFunc(const K& key)
	{return (key) % this->_tables.size();}
	
	size_t _GetNextPrime(size_t num)
	{
	   //ʹ����������������ϣ�������������͹�ϣ��ͻ
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
	//��������
	void Insert(const K& key,const V& value)
	{
		//���Ȳ���ѡ��ķ�ʽΪͷ��÷�ʽ�����в��루��ϣ�����������ݽ����˳��
		//��1���ȵ���_CheckSize()���������Ƿ�Ҫ�������ݣ�
		//��2������ͷ��㣻
		//��3�����������ڵ�
		//��4������_sizeҪ��������
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
		//ȷ��keyֵ������Ӧ��vector��ŵ�λ�ã�
		//����һ��ָ�룬������Ӧ��λ���µ��������в��ң�
		//����ҵ�������ָ��key��ָ�룻
		//���û���ҵ����򷵻�NULL��
		size_t index = this->_HashFunc(key);
		Node* cur = _tables[index];
		if(cur == NULL)                       //��key����Ӧ��λ��û�д�����ʱ������NULL��
		{return NULL;}
		else                                  //��key����Ӧ��λ�ô�������ʱ����ʼ���ң�
		{
			while(cur)
			{
				if(cur->_key == key)          //�ҵ��ˣ�����ָ��keyֵ��ָ�룻
					return cur;
				else
					cur = cur->_next ;        //��cur������NULL����û���ҵ�������¼������ң�
			}
		}
		return NULL;            //��key����Ӧλ�õ�������û���ҵ�
		
	}
	bool Remove(const K& key)
	{
		//��ɾ���Ľڵ㲻����ʱ������false��
		//��ɾ���Ľڵ����ʱ��
		//ɾ����Ϊ���ֿ��ܣ�
		//��1��ɾ��ͷ��㣻
		//��2��ɾ���м�ڵ����β�ڵ㣻
		//��3������_HashFunc(const K& key),ȷ��λ�ã�
		//   1>����һ��prevָ���һ��curָ�룬ȷ��keyֵ��ǰ��
		//   2>����ָ�뽻����ʵ��ɾ��
		//����true��
		if(this->Find(key) == NULL)
			return false;
		else
		{
			size_t index = this->_HashFunc(key);
			Node* prev = NULL;
			Node* cur = _tables[index];
			if(cur->_key == key)   //ɾ������ͷ���
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