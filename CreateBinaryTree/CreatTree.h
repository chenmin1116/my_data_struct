#pragma once
#include<iostream>
#include<vector>
using namespace std;
typedef struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	BinaryTreeNode(int x)
		:_value(x)
		,_left(NULL)
		,_right(NULL)
	{}
	BinaryTreeNode()
		:_value(0)
		,_left(NULL)
		,_right(NULL)
	{}
}Node,*pNode;
class BinaryTree
{
public:
	Node* _root;
public:
	BinaryTree()
		:_root(NULL)
	{}
	Node* __CreatBinaryTree__(int* startprevOrder,int* endprevOrder,int* startinOrder,int* endinOrder)
	{
		int rootValue = startprevOrder[0];
		pNode root = new Node();
		root->_value = rootValue;
		root->_left = root->_right = NULL;
		if(startprevOrder == endprevOrder)//������������ֻ��һ��Ԫ��ʱ
		{
			if(startinOrder == endinOrder && *startprevOrder == *startinOrder)
				return root;
			return NULL;
		}
		int* rootinOrder = startinOrder;
		while(rootinOrder != endinOrder && *rootinOrder != rootValue)
		{++rootinOrder;}
		//(1)�������г�������û���ҵ�rootinOrder��
		//(2)�ҵ������rootinOrder��
		int leftlength = rootinOrder - startinOrder;//���ڵ����������Ľڵ���Ŀ��
		int* leftprevOrderEnd = startprevOrder + leftlength;//ǰ�����е��������ڵ�ķ�Χ
		if(leftlength > 0)
		{
			root->_left = __CreatBinaryTree__(startprevOrder+1,leftprevOrderEnd,startinOrder,rootinOrder-1);
		}
		if(leftlength < endprevOrder-startprevOrder)
		{
			root->_right = __CreatBinaryTree__(leftprevOrderEnd+1,endprevOrder,rootinOrder+1,endinOrder);
		}
		return root;
	}
	//���õݹ�ķ�ʽ��������������������к���������������ؽ�������
	Node* CreatBinaryTree(int prevOrder[],int inOrder[],int length)
	{
		if(prevOrder == NULL || inOrder == NULL ||length <= 0)
			return NULL;
		return __CreatBinaryTree__(prevOrder,prevOrder+length-1,inOrder,inOrder+length-1);
	}    
};


void TestBinaryTree()
{
	BinaryTree bt;
	int prevOrder[] = {1,2,4,7,3,5,6,8};
	int inOrder[] = {4,7,2,1,5,3,8,6};
	int length = sizeof(prevOrder)/sizeof(prevOrder[0]);
	bt._root  = bt.CreatBinaryTree(prevOrder,inOrder,length);
	cout<<"bt._root->_value:"<<bt._root->_value<<endl;
}