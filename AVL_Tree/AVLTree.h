#pragma once
#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	AVLTreeNode<K,V>* _parent;
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K,V>* _right;
	int _bf;  //节点的左右子树高度差（右子树高度-左子树高度）

	AVLTreeNode()
		:_key(0)
		,_value(0)
		,_parent(NULL)
		,_left(NULL)
		,_right(NULL)
		,_bf(0)
	{}

};

template<class K,class V>
class AVLTree
{
	typedef  AVLTreeNode<K,V> Node;
private:
	Node* _root;

protected:
	void _RotatelL(Node* parent)
	{
		Node* subR = parent->_right ;
		Node* subRL = subR->_left ;
		parent->_right = subRL;
		if(subRL)
		{subRL->_parent = parent;}
		subR->_left = parent;
		Node* ppNode = parent->_parent ;
		parent->_parent =subR;
		if(ppNode == NULL)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			if(ppNode->_left == parent)
			{ppNode->_left = subR;}
			else
			{ppNode->_right = subR;}
		}
		subR->_parent = ppNode;
		subR->_bf =0;
		parent->_bf =0;
	}

	void _RotatelR(Node* parent)
	{
		Node* subL = parent->_left ;
		Node* subLR = subL->_right ;
		parent->_left = subLR;
		if(subLR)
		{subLR->_parent = parent;}
		subL->_left = parent;
		Node* ppNode = parent->_parent ;
		parent->_parent = subL;
		if(ppNode == NULL)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			if(ppNode->_left == parent)
			{ppNode->_left = subL;}
			else
			{ppNode->_right = subL;}
		}
		subL->_parent = ppNode;
		subL->_bf = 0;
		parent->_bf = 0;
	}

	void _RotatelLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_right;
		if(bf == 0)
		{

		}
		RotatelL(parent->_left);
		RotatelR(parent);
	}

	void _RotatelRL(Node* parent)
	{
		RotatelR(parent->_right);
		RotatelL(parent);
	}
public:
	AVLTree()
		:_root(NULL)
	{}

bool Insert(const K& key,const V& value)
{
	if(_root == NULL)
	{
		_root = new Node(key,value);
	    return true;
	}
	Node* parent = NULL;
	Node* cur = _root;
	while(cur)
	{
		if(cur->_key < key)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			if(cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{break;}
		}
	}
	cur = new Node(key,value);
	cur->_parent = parent;

	while(parent)
	{
		if(parent->_left)
		{parent->_bf--;}
		else
		{
			if(parent->_right)
			{parent->_bf++;}
		}
		if(parent->_bf == 0)
		{break;}
		else
		{
			if(parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else
			{
				if(parent->_bf == 2)
				{
					if(cur->_bf == 1)
					{_RotatelL(parent);}
					else
					{_RotatelRL(parent);}
				}
				else
				{
					if(cur->_bf == -1)
					{_RotatelR(parent);}
					else
					{_RotatelLR(parent);}
				}
			}
		}
	}
}
};