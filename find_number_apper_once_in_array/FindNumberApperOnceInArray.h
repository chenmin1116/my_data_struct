//������ֻ����һ�ε�����
//��Ŀ��һ�����������г�����������֮�⣬���������ֶ����������Σ���д�����ҳ�������ֻ����һ�ε�
//���֡�Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1).
#pragma once
#include<iostream>
using namespace std;
size_t FindFirstBitIs1InRight(int num)//����num�������ұ�Ϊ1��λ��
{
	int indexbit = 0;
	while(((num&1) == 0)/*���ұ�Ϊ1��λ ����ʱ��ֹͣѭ��*/&&(indexbit<8*sizeof(int)/*�������Ƶ�λ��*/))
	{
		num = num>>1;
		++indexbit;
	}
	return indexbit;
}
bool IndexBitIs1(int num,int indexbit)//�ж�num��indexbitλ�Ƿ�Ϊ1
{
	num = num>>indexbit;
	return (num&1);
}

//1.���������������Ԫ�ؽ�����������
//2.���������õ������ж����ұߵĵ�xλΪ1��
//3.�������е�Ԫ�ذ��յ�xλ�Ƿ�Ϊ1���л��֣�
//4.�Ի��ֵ����������е�Ԫ�طֱ����������������ҵ�������ֻ����һ�ε��������֣�
void FindNumberApperOnceInArray(int arr[],int length,int num1,int num2)//num1��num2ָ����Ϊ�˴�����������
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
	cout<<"�����г���һ�ε���������Ϊ��"<<num1<<","<<num2<<endl;
}


void TestFindNumberApperOnceInArray()
{
	int arr[] = {2,4,3,6,3,2,5,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int num1 = NULL ;
	int num2 = NULL ;
	FindNumberApperOnceInArray(arr,size,num1,num2);
	
}