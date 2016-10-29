#pragma once
#include<iostream>
using namespace std;

//定义红黑树节点的颜色
enum Color
{
	Red,
	Black,
};

//定义红黑树节点信息
template<class K,class V>
struct RedBlackTreeNode
{
	RedBlackTreeNode<K,V>* _left;
	RedBlackTreeNode<K,V>* _right;
	RedBlackTreeNode<K,V>* _parent;
	K _key;
	V _value;
	Color _col;

	RedBlackTreeNode(const K& key,const V& value)
		:_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		,_key(key)
		,_value(value)
		,_col(Red)
	{}
	
};

//定义红黑树
template<class K,class V>
class RedBlackTree
{
	typedef  RedBlackTreeNode<K,V> Node;
private:
	RedBlackTreeNode<K,V>* _root;
protected:
	void RotatelLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL= subR->_left;
		parent->_right = subRL;
		if(subRL)
		{subRL->_parent = parent;}
		subR->_parent = parent;
		Node* ppNode = parent->_parent ;
		parent->_parent = subR;
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
	}
	void RotatelRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if(subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* ppNode = parent->_parent;
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
	}

	void _InOrder(Node* root)
	{
		if(root == NULL)
		{return;}
		_InOrder(root->_left);
		cout<<root->_key <<" ";
		_InOrder(root->_right);
	}
public:
	RedBlackTree()
		:_root(NULL)
	{}
	void InOrder()
	{
		_InOrder(_root);
	}
    bool Insert(const K& key,const V& value)
	{
		if(this->_root == NULL)
		{
			_root = new Node(key,value);
			_root->_col = Black;  //将根节点的颜色置为Black
		    return true;
		}
		else
		{
			Node* cur = _root;
			Node* parent = cur->_parent = NULL;
			while(cur )
			{   
			   if( cur->_key < key)
			   {
				   parent = cur;
				   cur = cur->_right;
				   parent->_right = cur;
			   }
			   else
			   {
				   if(cur->_key > key)
				   { 
					   parent = cur;
					   cur = cur->_left;
					   parent->_left = cur;
				   }
				   else
				   {return false;}      //树中存在与插入节点相同的key
			   }
			 }
			
			cur = new Node(key,value);
			cur->_parent = parent ;
			
			while(parent->_col == Red && cur != NULL)
			{
				Node* grandfather = parent->_parent;
				Node* uncle = grandfather->_right;
				
				if(grandfather && parent == grandfather->_left)
				{
					//叔叔节点存在且为红色；
					if(uncle && uncle->_col == Red)
					{
						parent->_col = Black;
						uncle->_col = Black;
						grandfather->_col = Red;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						//叔叔节点不存在或者叔叔节点存在且为黑色
						if(cur == parent->_right)
						{
							RotatelLeft(parent);
							swap(parent,cur);
						}
						RotatelRight(grandfather);
						parent->_col = Black;
						grandfather->_col = Red;
						break;
					}
				}
				else
				{
					
					if(uncle && uncle->_col == Red)
					{
						Node* uncle = grandfather->_left;
						parent->_col = Black;
						uncle->_col = Black;
						grandfather->_col = Red;
						cur = grandfather;
						parent = cur->_parent ;
					}
					else
					{
						//叔叔节点存在或者叔叔节点存在且为黑色
						if(cur == parent->_left)
						{
							RotatelRight(parent);
							swap(parent,cur);
						}
						RotatelLeft(grandfather);
						parent->_col = Black;
						grandfather->_col = Red;
						break;
					}
				}
				_root->_col = Black;
				return true;
			}
			return false;
		}
	}
};


void TestRedBlack()
{
	RedBlackTree<int,int> rb;
	int a[]={16,3,7,11,9,26,18,14,15};
	int value = 0;
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		rb.Insert(a[i],value);
	}
	rb.InOrder();
}

