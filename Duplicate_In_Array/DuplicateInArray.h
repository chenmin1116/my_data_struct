//面试题51题目：数组中的重复数组
//在一个长度为n的数组里的所有数字都在0-n-1的范围内。数组中某些数字是重复的，
//但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的是数字。
//例如：如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复数字2或者3.
#pragma once
#include<iostream>
using namespace std;
//1.对于数组中的元素进行重排；
//a[i] == i,++i;
//a[i] != i,(1)a[i] == a[a[i]],则找到一个重复的元素；（2）a[i] != a[a[i]],swap（a[i],a[a[i]]）;
int DuplicateInArray(int arr[],int size)
{
	int i=0;
	while(i<size)
	{
		if(arr[i] == i)
			++i;
		else
		{
			if(arr[i] != arr[arr[i]])
			{swap(arr[i],arr[arr[i]]);}
			else
			{return arr[i];}
		}
	}
	return -1;
}

void TestDuplicateArray()
{
	int arr[] = {2,3,1,0,2,5,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	int ret = 0;
	ret = DuplicateInArray(arr,size);
	cout<<"ret is :"<<ret<<endl;

}
