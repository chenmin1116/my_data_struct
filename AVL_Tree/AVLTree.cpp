#include"AVLTree.h"
#include<iostream>
using namespace std;

void TestAVLTree()
{
	AVLTree<int,int> S;
	S.Insert(13,0);
	S.Insert(3,0);
	S.Insert(7,0);
	S.Insert(11,0);
	S.Insert(9,0);
	S.Insert(26,0);
	S.Insert(18,0);
	S.Insert(14,0);
	S.Insert(25,0);
	
}

int main()
{
	TestAVLTree();
	system("pause");
	return 0;
}