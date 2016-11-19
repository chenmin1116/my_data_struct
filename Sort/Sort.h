#pragma once
#include<iostream>
using namespace std;

//直接插入排序
//将一个数组分为两个区域：（1）有序区；（2）无序区
//将无序区中的数插入有序区
void InsertSort(int* a ,size_t size)
{
	int in_order = 0;
	int index = 0;
	
	int out_of_order = index+1;
	int temp = index+1;
	
	for(out_of_order = index+1;out_of_order<size;)
	{
		index = in_order++;
		temp = out_of_order++;
		int cur = a[temp];
		while(index>=0 && temp>0 )
		{
			if(a[index]>cur)
			{
				a[index+1] = a[index];
				index--;
				temp--;
			}
			else
				break;
		}
		a[++index] = cur;
	}
}

//希尔排序
void HillSort(int* a,size_t size)
{
	int gap = 1;
	int pos = 0;
	int index = pos;
    
	int temp =index+gap;
	int cur = a[temp];

	for(pos=0;pos<size;pos++)
	{
		index = pos;
		temp = index+gap;
		cur = a[temp];
		while(index>=0 && temp < size)
		{
			if(a[index] > cur)
			{
				a[index+gap] = a[index];
				index -= gap;
				temp -= gap;
			}
			else
				break;
		}
		a[index+gap] = cur;
	}
}

void Display(int* a,size_t size)
{
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


void TestInsertSort()
{
	int arr1[]={4,1,12,5,7,2};
	int arr2[]= {78,25,0,98,12,36,20};
	size_t size1 = sizeof(arr1)/sizeof(arr1[0]);
	size_t size2 = sizeof(arr2)/sizeof(arr2[0]);
	InsertSort(arr1,size1);
	HillSort(arr2,size2);
	Display(arr1,size1);
	Display(arr2,size2);
}

