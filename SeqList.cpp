#include<iostream>
using namespace std;

template <typename T>
class SeqList
{
	template <typename T>
	friend ostream& operator<<(ostream&os,SeqList<T>&seq)
	{
	for(int i=0;i<seq._sz;i++)
	{
		cout<<seq._pdata[i]<<" ";
	}
	return os;
	}
private:
	T* _pdata;
	int _sz;
	int _capacity;
private:
	void CheckCapacity();
public:
	SeqList();
	~SeqList();
	void PushBack(T x);
	void PushFront(T x);
	void PopBack();
	void PopFront();
	Seqlist(Seqlist<T>&seq);
	void Insert(const T x,int index);
	int  Find(const T x);
	void  Remove(const T x) ; 
};



template <typename T>
SeqList<T>::SeqList()
	:_pdata(NULL)
	,_sz(0)
	,_capacity(0)
{
	cout<<"SeqList()"<<endl;
}

template <typename T>
SeqList<T>::~SeqList()
{
	cout<<"~SeqList()"<<endl;
	this->_pdata=NULL;
	this->_sz=0;
	this->_capacity=0;
}
template <typename T>
void SeqList<T>::CheckCapacity()
{
	cout<<"CheckCapacity()"<<endl;
   if(this->_capacity == this->_sz)
	{
		int NewCapacity = 2*this->_capacity +10;
		T *tmp = new T[NewCapacity];
		for(int i=0;i<this->_sz;i++)
		{
			tmp[i]=this->_pdata[i];
		}
		delete[] this->_pdata;
		this->_pdata = new T[NewCapacity];
		this->_pdata = tmp;
		this->_capacity = NewCapacity;
	}
}

template <typename T>
void SeqList<T>:: PushBack(T x)
{
	cout<<"PushBack(T x)"<<endl;
	this->CheckCapacity();
	this->_pdata[this->_sz] = x;
	this->_sz++;
	this->_pdata[this->_sz] = '\0';
}
template <typename T>
void SeqList<T>:: PushFront(T x)
{
	cout<<"PushFront(T x)"<<endl;
	CheckCapacity();
	for(int i=this->_sz;i>0;i--)
	{
		this->_pdata[i] = this->_pdata[i-1];
	}
	this->_pdata[0] = x;
	this->_sz++;
	this->_pdata[this->_sz] = '\0';
}
template <typename T>
void SeqList<T>::PopBack()
{
	cout<<"PopBack()"<<endl;
	this->_pdata[this->_sz-1]='\0';
	this->_sz--;
}
template <typename T>
void SeqList<T>:: PopFront()
{
	cout<<"PopFront()"<<endl;
	for(int i=0;i<this->_sz-1;i++)
	{
		this->_pdata[i] = this->_pdata[i+1];
	}
	 this->_sz--;
	this->_pdata[_sz] = '\0';
   
}

template <typename T>
SeqList<T>::Seqlist<T>(Seqlist<T>&seq)
{
	this->_pdata = new T[seq._capacity];
	this->_sz = seq._capacity;
	for(int i=0;i<this->_sz;i++)
	{
		this->_pdata[i] = seq._pdata[i];
	}
	this->_capacity = seq._capacity;
}

template <typename T>
void SeqList<T>:: Insert(const T x,int index)
{
    CheckCapacity();
	for(int i=0;i<this->_sz;i++)
	{
		if(i == index)
		{
            for(int j=this->_sz;j>i;j--)
			{
				this->_pdata[j] = this->_pdata[j-1];
			}
		}
	}
	this->_pdata[index] = x;
}

template <typename T>
int SeqList<T>:: Find(const T x)
{
	for(int i=0;i<this->_sz;i++)
	{
		if(this->_pdata[i] = x)
		{
			return i;
		}
	}
	return 0;;
}

template <typename T>
void SeqList<T>::Remove(const T x) 
{
	int tmp = Find(x);
    if(tmp != 0)
	{
		for(int i=tmp;i<this->_sz;i++)
		{
			this->_pdata[i] = this->_pdata[i++];
		}
	}
}

void test1()
{
	SeqList<int> seq;
	seq.PushBack(1);
	seq.PushBack(2);
	seq.PushBack(3);
	seq.PushBack(4);
	seq.PushBack(5);
	seq.PushBack(6);
	seq.PushFront(0);
	seq.PopBack();
	seq.PopFront();
	cout<<seq<<endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}