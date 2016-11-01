//#include<iostream>
//#include<cstdio>
//using namespace std;
//template <typename T>
//class ScopedPtr
//{
//private:
//	T* _ptr;
//protected:
//	ScopedPtr(const ScopedPtr<T> &sp);//拷贝构造
//    ScopedPtr& operator=(const ScopedPtr<T>&sp);	//赋值构造
//public:
//	ScopedPtr(T* ptr);
//	~ScopedPtr();
//	T& operator*();
//	T* operator->();
//
//};
//
//template<typename T>
//ScopedPtr<T>::ScopedPtr(T* ptr)
//{
//	cout<<"构造函数！"<<endl;
//   this->_ptr = ptr;
//}
//
//
//template<typename T>
//ScopedPtr<T>::~ScopedPtr()
//{
//	cout<<"析构函数"<<endl;
//	delete this->_ptr;
//	this->_ptr = NULL;
//	
//}
//
//template<typename T>
//T& ScopedPtr<T>:: operator*()
//{
//	return *this->_ptr;
//}
//
//
//template<typename T>
//T* ScopedPtr<T>::operator->()
//{
//	return this->_ptr;
//}
//
//
//void testscopedptr()
//{
//	ScopedPtr<char> sp("abcdef");
//	cout<<*sp<<endl;
//	
//}
//int main()
//{
//   testscopedptr();
//   system("pause");
//   return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//using namespace std;
//template <typename T>
//class ScopedArr
//{
//private:
//	T* _ptr;
//	ScopedArr(const ScopedArr<T>& sa);
//	ScopedArr& operator==(const ScopedArr<T>& sa);
//public:
//	ScopedArr(T* ptr);
//	~ScopedArr();
//	T& operator[](int index); 
//
//};
//
//
//template<typename T>
// ScopedArr<T>::ScopedArr(T* ptr)
//{
//	cout<<"构造函数"<<endl;
//	this->_ptr = ptr;
// }
//template<typename T>
//ScopedArr<T>::~ScopedArr()
//{
//	cout<<"析构函数"<<endl;
//	delete this->_ptr;
//	this->_ptr = NULL;
//}
//template<typename T>
//T& ScopedArr<T>:: operator[](int index)
//{
//	return this->_ptr[index];
//}
//
//void testcopedarr()
//{
//	ScopedArr<char> sa("chenmin");
//	cout<<sa.operator[](5)<<endl;
//}
//
//int main()
//{
//	testcopedarr();
//	system("pause");
//	return 0;
//}
//auto_ptr存在权限转移
//#include<iostream>
//#include<cstdio>
//using namespace std;
//template <typename T>
//class AutoPtr
//{
//private:
//	T* _ptr;
//public:
//	AutoPtr(T* ptr);
//	~AutoPtr();
//	AutoPtr(AutoPtr<T>& ap);
//	AutoPtr& operator=(AutoPtr<T>&ap);
//	T& operator*();
//	T* operator->();
//
//};
//
//
//template <typename T>
//AutoPtr::AutoPtr(T* ptr)
//{
//	cout<<"构造函数"<<endl;
//	this->_ptr = ptr;
//}
//template <typename T>
//AutoPtr::~AutoPtr()
//{
//	cout<<"析构函数"<<endl;
//	delete this->_ptr;
//	this->_ptr = NULL;
//}
//template <typename T>
//AutoPtr::AutoPtr( AutoPtr<T>& ap)                     
//{
//	this->_ptr = ap._ptr;
//	ap._ptr = NULL;
//}
//template <typename T>
//AutoPtr& AutoPtr::operator=( AutoPtr<T>&ap)
//{
//	delete this->_ptr;
//	this->_ptr = ap._ptr;
//	ap._ptr = NULL;
//}
//template <typename T>
//T& AutoPtr:: operator*()
//{
//	return *this->_ptr;
//}
//template <typename T>
//T* AutoPtr:: operator->()
//{
//	return _ptr;
//}
//
//void testautoptr()
//{
//	AutoPtr<char> ap("chenmin");
//	AutoPtr<char> ap1(ap);
//	AutoPtr<char> ap2("hello");
//	ap = ap2;
//	
//}
//
//int main()
//{
//	testautoptr();
//	system("pause");
//	return 0;
//}


