//������51��Ŀ�������е��ظ�����
//��һ������Ϊn����������������ֶ���0-n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�
//����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ��������֡�
//���磺������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�����2����3.
#pragma once
#include<iostream>
using namespace std;
//1.���������е�Ԫ�ؽ������ţ�
//a[i] == i,++i;
//a[i] != i,(1)a[i] == a[a[i]],���ҵ�һ���ظ���Ԫ�أ���2��a[i] != a[a[i]],swap��a[i],a[a[i]]��;
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
