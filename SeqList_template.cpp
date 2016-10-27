#include<iostream>
using  namespace std;
#include<cassert>

template<typename T>
class Seqlist
{
private:
	T* _pdata;
	int _sz;
	int _capacity;
private:
	void CheckCapacity();
public:
	Seqlist();
	~Seqlist();
	Seqlist& PushBack(const T x);
	void Print();
	Seqlist(Seqlist&seq);
	Seqlist& PushFront(const T x);
	Seqlist& PopBack();
	Seqlist& PopFront();
	Seqlist& Insert(const T x,int index);
	int Find(const T x);
	Seqlist&  Remove(const T x) ; 
};

template<typename T>
void Seqlist<T>::Print()
{
	for(int i=0;i<this->_sz ;i++)
		{
			cout<<this->_pdata [i]<<" ";
		}
	cout<<endl;
}

template<typename T>
Seqlist<T>::Seqlist ()
	:_pdata(NULL)
	,_sz(0)
	,_capacity(0)
{
	cout<<"构造函数"<<endl;
}

template<typename T>
Seqlist<T>::~Seqlist()
{
	cout<<"析构函数"<<endl;
	if(this->_pdata != NULL)
	{
		assert(this->_pdata );
		delete[] this->_pdata;
		this->_pdata =NULL;
	}
}

template<typename T>
void Seqlist<T>:: CheckCapacity()
{
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

template<typename T>
Seqlist<T>& Seqlist<T>:: PushBack(const T x)
{
	CheckCapacity();
	this->_pdata[this->_sz] = x;
	this->_sz ++;
	this->_pdata[this->_sz] = '\0';
	return *this;
}

//
template<typename T>
Seqlist<T>::Seqlist<T>(Seqlist<T>&seq)
{
	cout<<"拷贝构造"<<endl;
	if(this->_pdata != NULL)
	{
		delete[] this->_pdata ;
		this->_pdata = new DataType[seq._capacity ];
		memcpy(this->_pdata ,seq._pdata ,seq._sz *sizeof(seq._pdata ));
	}
}

template<typename T>
Seqlist<T>& Seqlist<T>:: PushFront(const T x)
{
	cout<<"头插函数"<<endl;
	CheckCapacity();
	int i=this->_sz;
	int j=this->_sz-1;
	while(j>=0)
	{
		this->_pdata [i] = this->_pdata [j];
		--i;
		--j;
	}
	this->_pdata[j] = x;
	this->_pdata[this->_sz+=1] = '\0';
	return *this;
}

template<typename T>
Seqlist<T>& Seqlist<T>:: PopBack()             //尾删
{
	cout<<"尾删函数"<<endl;
	this->_pdata[_sz] = '\0';
	this->_sz--;
	return *this;
}

template<typename T>
Seqlist<T>& Seqlist<T>:: PopFront()          //头删
{
	cout<<"头删函数"<<endl;
	for(int i=0;i<this->_sz;i++)
	{
		this->_pdata[i] = this->_pdata[i+1];
	}
	this->_pdata[this->_sz]='\0';
	return *this;
}

template<typename T>
Seqlist<T>& Seqlist<T>:: Insert(const T x,int index)    //在特定位置插入某一指定元素
{
	assert(this->_pdata);
	cout<<"插入函数"<<endl;
	if(index>this->_sz)
	{return *this;}
	CheckCapacity();
	for(int i=0;i<this->_sz;i++)
	{
		if(i == index)
		{
			int k=this->_sz+1;
			for(int j=this->_sz;j>=i;j--)
			{
				this->_pdata[k] = this->_pdata[j];
			}
			this->_pdata[i] = x;
			this->_pdata[this->_sz+=2] = '\0';
			return *this;
		}
	}
	return *this;
}

template<typename T>
int Seqlist<T>:: Find(const T x)
{
	cout<<"查找函数"<<endl;
	for(int i=0;i<this->_sz;i++)
	{
		if(this->_pdata[i] == x)
		{
			this->_sz = i;
			return this->_sz;
		}
	}
	return -1;
}

template<typename T>
Seqlist<T>& Seqlist<T>:: Remove(const T x)                //删除最先出现的特定元素
{
	cout<<"删除特定元素函数"<<endl;
	for(int i=0;i<this->_sz;i++)
	{
		if(this->_pdata[i] == c)
		{
			for(int j=i+1;j<this->_sz;j++)
			{
				this->_pdata[i] = this->_pdata[j];
			}
			this->_pdata[--this->_sz] = '\0';
			return *this;
		}
	}
	return *this;
}

void test1()
{
	Seqlist<int>seq;
	seq.PushBack (1);
	seq.PushBack (2);
	seq.PushBack (3);
	seq.PushBack (4);
	seq.PushBack (5);
	seq.Print();
	seq.PushFront(1);
	seq.Print();
	seq.PopBack();
    seq.Print();
	seq.PopFront();
	seq.Print ();
	seq.Insert(8,2);
	seq.Print ();
	seq.Find(3);
	seq.Print ();
	seq.Remove(1);
	seq.Print ();
	 

}

int main()
{
	test1();
	system("pause");
	return 0;
}


