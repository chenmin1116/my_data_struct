#pragma once
#include<iostream>
#include<vector>
using namespace std;
//ʹ�ñ�ʶλ���ÿ���ڵ������ݵ�״̬
enum Status
{
	EXIST,
	EMPTY,
	DELETE,
};

//�����ϣ��Ľڵ�
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

//�����ϣ��Ľṹ
template<class K,class V>
class HashTable
{typedef  HashTableNode<K,V> Node;

private:
	vector<Node> _vec;
	size_t _size;

protected:

   //��������ɢ�б��е�����
	void SwapHashTable(HashTable<K,V>& _table1)
	{
		this->_vec.swap(_table1._vec);
		_size =_table1._vec .size();
	}
	
	size_t GetIndex(const K& key)
	{return key%this->_vec.size();}
	
	size_t _GetNextPrime(size_t num)
	{
	//ʹ���������������ϣ1������������͹�ϣ��ͻ
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
		//for(int i=0;i<_size;i++)   //��ԭ��ɢ�б��е����ݿ�������ʱ������ɢ�б�
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
			//����һ����ʱ��ɢ�б���ԭɢ�б�����ݲ��룬���Һ�ԭ����ɢ�б����������ﵽ���ݵ�Ч����
			HashTable<K,V> _table1;
			_table1._vec.resize(NewSize);
			//��ԭ��ɢ�б��е����ݰ��չ��򣬿�����_vec1�У�
			for(size_t i=0;i<this->_vec.size();i++)
			{
				if(this->_vec[i]._status == EXIST)//ֻ����ԭ��ɢ�б���״̬ΪEXIST�ģ�������Ĭ��Ϊ�գ�
				{
				   size_t index = this->_vec[i]._key%NewSize;
				   if(_table1._vec[index]._status == EMPTY)
				   {
					   //��״̬Ϊ��ʱ��ֱ�Ӳ���
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
			//���ݿ�����ϣ���������ɢ�б�ʵ�����ݣ�
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
	//��������
	//��������


	//����ڵ�
	//1,�������
	//2.����Ƿ�����ͻ��
	//3.��û�г�ͻʱ��ֱ�Ӳ���
	//4.��������ͻʱ������һ��״̬ΪEMPTY�Ľڵ���룻
	//5.����������>=0.7��ʱ��������ݣ�ʵ���Կռ任ʱ�䣻
	//6.�������� = ������е�Ԫ�ظ���/ɢ�б�ĳ��ȣ�
	//7.��������ʱ��ɢ�б�Ĵ�С����Ϊ�����������׷�����ͻ��
	void Insert(const K& key,const V& value)
	{
		size_t index = GetIndex(key);
		if(this->_vec.size() == 0)
		{
			_CheckSize();//����
			Insert(key,value);//���²���
		}
		else
		{
			
			if(this->_size*10/this->_vec.size() <7 )    //����������С��0.7 ��ʱ����в���
			{
				if(this->_vec[index]._status == EMPTY || this->_vec[index]._status == DELETE)  //��index��λ�ÿ��Բ���ʱ
				{
					this->_vec[index]._key = key;
					this->_vec[index]._value = value;
					this->_vec[index]._status = EXIST;
					_size++;
				}

				else  //��index��λ���Ѿ���ռ
				{
					while(this->_vec[index]._status == EXIST)
					{
						if(index == this->_vec.size())
						{index = 0;}
						index++;
					}    
					//�ҵ���һ��״̬��ΪEXIST
					this->_vec[index]._key = key;
					this->_vec[index]._value = value;
					this->_vec[index]._status = EXIST;

				}
			}

			else
			{
				_CheckSize();//����
				Insert(key,value);//���²���
			}
		}
	}
	//1.�ȴ�index��_vec.size()֮���ң������ҵ��ˣ����ؽڵ�ĵ�ַ
	//2.������û���ҵ�����0��index���������ң������ҵ��ˣ�ֱ�ӷ��ؽڵ�ĵ�ַ��
	//3.����û���ҵ���ֱ�ӷ���NULL��

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

		size_t src = index;//��¼key�ĳ�ʼindex
		for(index=0;index<src;index++)
		{
			if(this->_vec[index]._key == key)
			{
				return &_vec[index];
			}
		}
		return NULL;
	}

	//1.����û���ҵ���ֱ�ӷ���false;
	//�����ҵ��ˣ����ڵ��״̬��ʶλ��ΪDELETE������size--;
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
	cout<<"ɾ��֮ǰ���ң�"<<ht1.Find(18)<<endl;
	cout<<"ɾ����"<<ht1.Remove(18)<<endl;
	cout<<"ɾ��֮���ٽ��в��ң�"<<ht1.Find(18)<<endl;
}