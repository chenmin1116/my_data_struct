//数组中只出现一次的数字
//题目：一个整形数组中除了两个数字之外，其他的数字都出现了两次；请写程序找出这两个只出现一次的
//数字。要求时间复杂度为O(N)，空间复杂度为O(1).
#pragma once
#include<iostream>
using namespace std;
size_t FindFirstBitIs1InRight(int num)//查找num整数最右边为1的位；
{
	int indexbit = 0;
	while(((num&1) == 0)/*当右边为1的位 出现时：停止循环*/&&(indexbit<8*sizeof(int)/*控制右移的位数*/))
	{
		num = num>>1;
		++indexbit;
	}
	return indexbit;
}
bool IndexBitIs1(int num,int indexbit)//判断num的indexbit位是否为1
{
	num = num>>indexbit;
	return (num&1);
}

//1.将所给数组的所有元素进行异或操作；
//2.将异或操作得到的数判断最右边的第x位为1；
//3.将数组中的元素按照第x位是否为1进行划分；
//4.对划分的两个数组中的元素分别进行异或操作，便可找到数组中只出现一次的两个数字；
void FindNumberApperOnceInArray(int arr[],int length,int num1,int num2)//num1和num2指针是为了带回运算结果；
{
	int result = 0;
	int indexbit = 0;
	for(int i=0;i<length;++i)
	{
		result ^= arr[i];
	}
	indexbit = FindFirstBitIs1InRight(result);
	num1 = num2 = 0;
	for(int i=0;i<length;++i)
	{
		if(IndexBitIs1(arr[i],indexbit) == true)
		{
			num1 ^= arr[i];
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	cout<<"数组中出现一次的两个数字为："<<num1<<","<<num2<<endl;
}


void TestFindNumberApperOnceInArray()
{
	int arr[] = {2,4,3,6,3,2,5,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int num1 = NULL ;
	int num2 = NULL ;
	FindNumberApperOnceInArray(arr,size,num1,num2);
	
}