#pragma once
#include<iostream>
#include<vector>
using namespace std;
//位图在STL中是以bitset来呈现的
class BitMap
{
public:
	vector<size_t> _bitmap;
public:
	BitMap(size_t range)
	{
		_bitmap.resize((range>>5)+1);    //确定存放在那个size_t的位置；
	}
	void Set(size_t size)                
	{
		size_t index = size>>5;
		size_t num = size%32;
		size_t tmp = 1;
		tmp = tmp<<num;
		_bitmap[index] |= tmp;

	}
	void Reset(size_t size)
	{
		size_t index = size>>5;
		size_t num = size%32;
	    _bitmap[index] &= ~(1<<num);
	}
	bool Test(size_t size)
	{
		size_t index = size>>5;
		size_t num = size%32;
		_bitmap[index] &= (1<<num);
		
		if(_bitmap[index] == 1)
			return true;
		else
			return false;
	}
};

void TestBitMap()
{
	BitMap bit_map(13);
	bit_map.Set(5);
	cout<<bit_map.Test(5)<<endl;
	cout<<bit_map._bitmap[0]<<endl;
	
	bit_map.Reset(5);
	cout<<bit_map._bitmap[0]<<endl;
	cout<<bit_map.Test(5)<<endl;
}