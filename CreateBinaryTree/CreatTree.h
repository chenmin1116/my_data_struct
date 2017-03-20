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
		if(startprevOrder == endprevOrder)//当先序序列中只有一个元素时
		{
			if(startinOrder == endinOrder && *startprevOrder == *startinOrder)
				return root;
			return NULL;
		}
		int* rootinOrder = startinOrder;
		while(rootinOrder != endinOrder && *rootinOrder != rootValue)
		{++rootinOrder;}
		//(1)中序序列出错，导致没有找到rootinOrder；
		//(2)找到了这个rootinOrder；
		int leftlength = rootinOrder - startinOrder;//根节点内左子树的节点数目；
		int* leftprevOrderEnd = startprevOrder + leftlength;//前序序列的左子树节点的范围
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
	//采用递归的方式，根据树的先序遍历序列和中序遍历序列来重建二叉树
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