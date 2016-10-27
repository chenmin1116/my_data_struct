#include"Heap_Max_Min.h"

void TestHeap()
{
	int a[] = {1,5,6,3,4,7,8};
	int size = sizeof(a)/sizeof(a[0]);
	Heap<int> heap(a,size);
    //heap.Push(15);
	//heap.Print();
	//cout<<heap.Empty()<<endl;
	//cout<<heap.Size()<<endl;
	//heap.Pop();
	heap.Print();
}
int main()
{
	TestHeap();
	system("pause");
	return 0;
}