#pragma once
#include<iostream>
#include<cassert>
using namespace std;

//ֱ�Ӳ�������
//��һ�������Ϊ�������򣺣�1������������2��������
//���������е�������������
void InsertSort(int* a ,int size)
{
	assert(a);
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

//ϣ������
void HillSort(int* a,int size)
{
	assert(a);
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

//ѡ������
//�������������������Ҫ��������䣻
//���ڱ������п��ƣ�������С�������䣬��������
//ʱ�临�Ӷ�O(n2)

void SelectSort(int* a ,int size)
{
	assert(a);
	size_t left = 0;
	size_t right = size-1;
	while( left <= right )
	{
		for(size_t i=left;i <= right;i++)
		{
			if(a[i] < a[left])
			{
				swap(a[left],a[i]);
			}
			if(a[i] > a[right])
			{
				swap(a[i],a[right]);
			}
		}
		++left;
		--right;
	}
}
//������
//1.���ѣ��������µ���
//2.������
void AdjustDown(int* a,int root,size_t size)
{
	int parent = root;
	int left = parent*2 + 1;
	int right = left + 1;
	while(left<size)
	{
		int max = left;
		if(right<size && a[right]<a[max])
		{
			max = right;
		}
		if(a[parent]<a[max])
		{
			swap(a[max],a[parent]);
			parent = max;
			left = parent*2 + 1;
			right = left + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a,int size)
{
	assert(a);
	for(size_t i = size/2-1;i >= 0;--i)
	{
		AdjustDown(a,i,size);
	}

	int end = size-1;
	while(end>0)
	{
		swap(a[0],a[end]);
		AdjustDown(a,0,end);
		--end;
	}
}

//ð������
 
void BubbleSort(int* a,int size)
{
	assert(a);
	for(int i = 0;i<size;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(a[i] < a[j])
			{swap(a[i],a[j]);}
		}
	}
}

//��������

void QuickSort(int* a,int size)
{
  assert(a);
	int left = 0;
	int right = size-1;
	while(left<= right)
	{
		int temp = a[right];
		for(int i = left;i<=right;i++)
		{
			if(a[i] < a[left])
			{
				swap(a[i],a[left]);
			}
		}
		for(int i = right;i>= 0;i--)
		{
			if(a[i]>a[right])
			{
				swap(a[i],a[right]);
			}
		}
		a[left] = temp;
	}
}


//�ǱȽ�������
//��������
void CountSort(int* a,size_t size)
{
	assert(a);
	//Ѱ��a[]�е����ֵ����Сֵ���жϷ�Χ����ȷ����������Ĵ�С��
	int min = a[0];
	int max = a[0];
	for(size_t i=0;i<size;i++)
	{
		if(a[i]<min)
			min = a[i];
		if(a[i]>max)
			max = a[i];
	}
	int range = max-min+1;
	//ȷ���������������
	int* count = new int[range];
	memset(count,0,sizeof(int)*range);
	for(size_t i=0;i<size;i++)
	{
		
			count[a[i]-min]++;
	}
	//��ͨ���������������ֵд��a[]�У���ʵ������
	int index = 0;
	for(size_t i=0;i<range;i++)
	{
		while(count[i]--)
		{
			a[index++] = i+min;
		}
	}
	delete[] count;
}

//��������
//��1��LSD�ȶԵ�λ���������ٶԸ�λ��������
//��2��MSD�ȶԸ�λ���������ٶԵ�λ��������
int GetMaxDigit(int* a , size_t size)
{
	int base = 10;
	int digit =1;
	for(size_t i=0;i<size;i++)
	{
		while(a[i]>= base)
		{
		   ++digit;
		   base*=10;
		}
	}
	return digit;
}
void LSDSort(int* a,size_t size)
{
	//(1)����������λ��
	//(2)ͳ��0��9��Ͱ�����ݳ��ֵĴ�����
	//(3)�����ŵ���ʼλ�ã�
	//(4)���ڸ�λ��������������λ��һ��ѭ����

	assert(a);
	
	int* tmp = new int[size];
	memset(tmp,0,sizeof(int)*size);
	int MaxDigit = GetMaxDigit(a,size);
	int base = 1;
	//ͳ��0��9��Ͱ�У����ݳ��ֵĸ���

	for( int i=0; i< MaxDigit;++i)
	{
		int count[10]={0};
	    int start[10]={0};
		for(size_t j=0;j<size;j++)
		{
			int num = (a[j]/base)%10;
			count[num]++;
		}
		//������ʼλ��

		for(size_t j=1;j<10;++j)
		{
			start[j] = start[j-1]+count[j-1];
		}

		for(size_t j=0;j<size;j++)
		{
			int num = (a[j]/base)%10;
			tmp[start[num]++] =a[j] ;
		}
		base*=10;
	}
	for(size_t j=0;j<size;++j)
	{
		a[j] = tmp[j];
	}
	delete[] tmp;
}

void Display(int* a,int size)
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
	int arr3[]={12,56,0,9,32,20};
	int arr4[]={9,8,7,6,5,4,3,2,1,0};
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	int size3 = sizeof(arr3)/sizeof(arr3[0]);
	int size4 = sizeof(arr4)/sizeof(arr4[0]);
	InsertSort(arr1,size1);
	HillSort(arr2,size2);
	SelectSort(arr3,size3);
	BubbleSort(arr4,size4);
	CountSort(arr3,size3);
	LSDSort(arr1,size1);
	HeapSort(arr1,size1);
	Display(arr1,size1);
	Display(arr2,size2);
	Display(arr3,size3);
	Display(arr4,size4);

}

