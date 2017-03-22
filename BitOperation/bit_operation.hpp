#pragma once
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
//面试题一：用A表示第一列，B表示第二列...........Z表示第26列，AA表示第27列，AB表示第28列..............以此类推。请写出一个函数，输入字母表示的列好编码，输出她是第几列。
//思路：把十进制数字用A-Z表示成二十六进制。
int SearchRow(char* str,int length)//strlen
{ 
	//把A-Z表示成26进制；数组下标为所代表的值。
	char ch[] = {'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//多写一个‘0’是为了让字母分别匹配他们的值，
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

//题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如把9表示成二进制位1001，有两位是1.因此输入9该函数输出2.
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
//题目：用一条语句判断一个整数是不是2的整数次方。
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
//题目：输入两个整数m和n，计算需要改变m的额二进制表示中的多少位，才能得到n.
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