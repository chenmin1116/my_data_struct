//��ά�������ֵĲ���
/*��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������*/
#include<iostream>
using namespace std;

bool FindIndexOfDoubleArray(int* arry ,int rows/*��*/,int columns/*��*/,int numbers)
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

void testFindIndexInDoubleArray1()//���Զ�ά����֮�д��ڵ����֣�����������ֵ����Сֵ֮�䣩��
{
	int arry[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int rows = 4;
	int columns = 4;
	int numbers =7;
	cout<<"Find is "<<FindIndexOfDoubleArray((int*)arry,rows,columns,numbers)<<endl;
}

void testFindIndexInDoubleArray2()//���Զ�ά����֮�в����ڵ��������������������������ֵ����Сֵ֮�䣻
{
	int arry[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int rows = 4;
	int columns = 4;
	int numbers = 3;
	cout<<"Find is "<<FindIndexOfDoubleArray((int*)arry,rows,columns,numbers)<<endl;
}

void testFindIndexInDoubleArray3()//����һ���յ�ָ�루��ά���飩��
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