//第一种解法
#include"Stack_Compare.h"

void TestStack()
{
	Min_Stack<int> stack1;
	stack1.Push (1);
	stack1.Push (2);
	stack1.Push (3);
	stack1.Push (4);
	stack1.Push (5);
	stack1.Push (6);
	stack1.Push (7);
	stack1.Push (8);
	stack1.Push (9);
	stack1.Push (0);
	stack1.Push (11);
	stack1.Push (12);
	stack1.Push (13);
	stack1.Push (14);
	stack1.Print();
	cout<<"the min element is:"<<stack1.GetTop()<<endl;
	
}

int main()
{
	TestStack();
	system("pause");
	return 0;
}

//第二种解法
//#include"Stack_Compare.h"
//void TestStack()
//{
//	Min_Stack<int> stack1;
//	Min_Stack<int> stack2;
//	stack1.Push (1,stack2);
//	stack1.Push (2,stack2);
//	stack1.Push (3,stack2);
//	stack1.Push (4,stack2);
//	stack1.Print();
//	stack2.Print();
//	cout<<"the min element is:"<<stack2.GetTop()<<endl;
//	
//}
//int main()
//{
//	TestStack();
//	system("pause");
//	return 0;
//}
