//二维数组数字的查找
/*题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序；
请完成这样的一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/
#include<iostream>
using namespace std;

bool FindIndexOfDoubleArray(int* arry ,int rows/*行*/,int columns/*列*/,int numbers)
{
	bool Find = false;
	int i = 0;
	int j = columns-1;
	while(i<rows && j>=0)
	{
		if(arry[i*columns+j] > numbers)
		{
			--j;
		}
		if(arry[i*columns+j] < numbers)
		{
			++i;
		}
		if(arry[i*columns+j] == numbers)
		{
			Find = true;
			break;
		}
	}
	return Find;
}

void testFindIndexInDoubleArray1()//测试二维数组之中存在的数字（在数组的最大值和最小值之间）；
{
	int arry[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int rows = 4;
	int columns = 4;
	int numbers =7;
	cout<<"Find is "<<FindIndexOfDoubleArray((int*)arry,rows,columns,numbers)<<endl;
}

void testFindIndexInDoubleArray2()//测试二维数组之中不存在的数，并且这个数置于数组的最大值与最小值之间；
{
	int arry[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int rows = 4;
	int columns = 4;
	int numbers = 3;
	cout<<"Find is "<<FindIndexOfDoubleArray((int*)arry,rows,columns,numbers)<<endl;
}

void testFindIndexInDoubleArray3()//测试一个空的指针（二维数组）；
{
	cout<<"Find is "<<FindIndexOfDoubleArray(NULL,0,0,2)<<endl;
}
int main()
{
	testFindIndexInDoubleArray1();
	testFindIndexInDoubleArray2();
	testFindIndexInDoubleArray3();
	system("pause");
	return 0;
}