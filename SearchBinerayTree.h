#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct SearchBinerayTreeNode
{
	SearchBinerayTreeNode<T> *_left;
	SearchBinerayTreeNode<T> *_right;
	T  key;
	SearchBinerayTreeNode(const T&x)
		:_left(NULL)
		,_right(NULL)
		,key(x)
	{}
};

template<typename T>
class SearchBineryTree
{
	typedef SearchBinerayTreeNode<T> Node;
protected:
	Node *CreatTree(T*a,size_t size,size_t &index,const T& invalid)   
	{
		Node* root = NULL;
		if((a[index] != invalid)&&(index<size))
		{
			root = new Node(a[index]);
			root->_left = CreatTree(a,size,++index,invalid);
			root->_right = CreatTree(a,size,++index,invalid);
		}
		return root;
	}
    
	void _InOrder(Node *root)      //中序遍历实现
	{
		if(root == NULL)
			return;
		_InOrder(root->_left);
		cout<<root->key<<" ";
		_InOrder(root->_right);
	}
public:
	SearchBineryTree()
		:_root(NULL)
	{}

	SearchBineryTree(T *a,size_t size,const T& invalid)
	{
		size_t index = 0;
		_root = CreatTree(a,size,index,invalid);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
bool Insert(const T&key)
{
	if(_root == NULL)
	{
		_root = new Node(key);
		return true;
	}
	Node *cur = _root;
	Node *parent = NULL;
	while(cur)
	{
		if(cur->key < key)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			if(cur->key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
	}

	if(parent->key > key)
	{
		parent->_left = new Node(key);
	}

	else
	{
		parent->_right = new Node(key);
	}
	return true;
}
bool Remove(const T&key)
{
	if(_root == NULL)
	{
		return false;
	}
	Node *parent = NULL;
	Node *cur = _root;
	while(cur->key != key)      
	{
		if(cur->key <key)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
				if(cur->key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
		}
	}  

	if(cur->_left == NULL)
	{
		Node *tmp = cur;
		if(parent->_left == cur)
		{
			parent->_left = cur->_right;
		}
		else
		{
			parent->_right = cur->_right;
		}
		delete cur;
	}
	else
	{
		Node *tmp1 = cur;
		Node *tmp2 = cur->_left;
		if(cur->_right == NULL) 
		{
			if(parent->_left == cur)
			{
				parent->_left = cur->_left;
				delete cur;
			}
			else
			{
				if(tmp2->key > parent->key)
				{
					parent->_right = cur->_left;
					delete cur;
				}
				else
				{
					if(tmp2->key < parent->key)  
					{
						parent->_left = cur->_left;
						delete cur;
					}
					
				}
			}
			return true;
		}
		return false;
	}

	if( (cur->_left != NULL) && (cur->_right != NULL) )
	{
		Node* tmpParent = cur;
		Node* tmp = cur->_left;
		while(tmp)
		{
			tmpParent = tmp;
			tmp = tmp->_right ;
		}
		cur = tmp;
		tmp->_right = NULL;
		return true;
	}
	return false;
}

	////要删除的节点左右孩子都不为空
	//if((cur->_left != NULL)&&(cur->_left != NULL))
	//{
	//	Node *p = cur->_right;
	//	while(p)
	//	{
	//		p = p->left;
	//	}

	//}

bool Find(const T&key)
{
	Node *cur = _root;
	while(cur)
	{
		if(cur->key < key)
		{
			cur = cur->_right;
		}
		else
		{
			if(cur->key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
	}
	return false;
}

private:
	Node *_root;
};





