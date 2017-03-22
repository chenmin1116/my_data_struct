#pragma once
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
//������һ����A��ʾ��һ�У�B��ʾ�ڶ���...........Z��ʾ��26�У�AA��ʾ��27�У�AB��ʾ��28��..............�Դ����ơ���д��һ��������������ĸ��ʾ���кñ��룬������ǵڼ��С�
//˼·����ʮ����������A-Z��ʾ�ɶ�ʮ�����ơ�
int SearchRow(char* str,int length)//strlen
{ 
	//��A-Z��ʾ��26���ƣ������±�Ϊ�������ֵ��
	char ch[] = {'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//��дһ����0����Ϊ������ĸ�ֱ�ƥ�����ǵ�ֵ��
	char* p1 = str;
	char* p2 = str+length-1;
	double count = 0.0;
	int row = 0;
	while(p1  <= p2)
	{
	  for(int i=0;i<sizeof(ch)/sizeof(ch[0]);++i)
	  {
		  if(*p2 == ch[i])
		  {
			row += i*pow(26.0,count);
			count++;
			p2--;
			break;
		  }
	  }
	}
	return row;
}

//��Ŀ����ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ����������9��ʾ�ɶ�����λ1001������λ��1.�������9�ú������2.
int FindNumBitIs1(int num)
{
	int count = 0;
	while(num != 0)
	{
		count++;
		num = num &(num - 1);
	}
	return count;
}
//��Ŀ����һ������ж�һ�������ǲ���2�������η���
bool Is2IntegerPower(int num)
{
	int count = 0;
	while(num != 0)
	{
		count++;
		num &= num-1; 
	}
	if(count == 1)
		return true;
	return false;
}
//��Ŀ��������������m��n��������Ҫ�ı�m�Ķ�����Ʊ�ʾ�еĶ���λ�����ܵõ�n.
int BitOfInt1ToInt2(int m,int n)
{
	int result = m^n;
	int count = 0;
	while(result)
	{
		count++;
		result &= (result -1);
	}
	return count;
}


void Test()
{
	int m = 13;
	cout<<"Bit is 1:"<<FindNumBitIs1(m)<<endl;
	cout<<"Is 2 Integer Power :"<<Is2IntegerPower(m)<<endl;
	cout<<"Int1 To Int2 Of Bit: "<<BitOfInt1ToInt2(10,13)<<endl;
	char *ptr = "AB";
	int length = strlen(ptr);
	int rows = SearchRow(ptr,length);
	cout<<"'"<< ptr <<"' "<<"row  is :"<<rows<<endl;
}