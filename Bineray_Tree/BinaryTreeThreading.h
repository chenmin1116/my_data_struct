#pragma once

enum PointerTag {THREAD, LINK};

template <class T>
struct BinaryTreeNodeThd
{
	T _data ;                         // 数据
	BinaryTreeNodeThd<T >* _left;	  // 左孩子
	BinaryTreeNodeThd<T >* _right;    // 右孩子
	PointerTag   _leftTag ;           // 左孩子线索标志
	PointerTag   _rightTag ;          // 右孩子线索标志

	BinaryTreeNodeThd(const T& x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
		,_leftTag(LINK)
		,_rightTag(LINK)
	{}
};


// 实现中序遍历的迭代器
template<class T, class Ref, class Ptr>
struct __TreeIterator
{
	typedef BinaryTreeNodeThd<T> Node;
	typedef __TreeIterator<T, Ref, Ptr> Self;

	__TreeIterator(){};
	__TreeIterator(Node* node)
		:_node(node)
	{}

	// const T&
	// T&
	Ref operator*()
	{
		assert(_node);
		return _node->_data;
	}

	Self& operator++()
	{
		assert(_node);
		if (_node->_rightTag == LINK)
		{
			// 右树的最左节点
			Node* right = _node->_right;
			while (right && right->_leftTag == LINK)
			{
				right = right->_left;
			}

			_node = right;
		}
		else
		{
			_node = _node->_right;
		}

		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		++(*this);
		return tmp;
	}

	Self& operator--()
	{
		assert(_node);
		if (_node->_leftTag == LINK)
		{
			// 左树的最右节点
			Node* left = _node->_left;
			while (left && left->_rightTag == LINK)
			{
				left = left->_right;
			}

			_node = left;
		}
		else
		{
			_node = _node->_left;
		}

		return *this;
	}

	bool operator != (const Self s) const
	{
		return _node != s._node;
	}

	Node* _node;
};

template<class T>
class BinaryTreeThd
{
	typedef BinaryTreeNodeThd<T> Node;
public:
	typedef __TreeIterator<T, T& ,T*> Iterator;
	typedef __TreeIterator<T, const T& , const T*> ConstIterator;

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur && cur->_leftTag == LINK)
		{
			cur = cur->_left;
		}

		return Iterator(cur);
	}

	ConstIterator Begin() const;

	Iterator End()
	{
		return Iterator(0);
	}

	ConstIterator End() const;



	BinaryTreeThd(T* a, size_t size, const T& invalid)
	{
		size_t index = 0;
		_root = _CreateTree(a, size, index, invalid);
	}

	void InOrderThreading()
	{
		Node* prev = NULL;
		_InOrderThreading(_root, prev);
	}

	void InOrderThd()
	{
		Node* cur = _root;
		while (cur)
		{
			// 找最左节点
			while(cur && cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}

			cout<<cur->_data<<" ";

			while(cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout<<cur->_data<<" ";
			}

			//
			cur = cur->_right;
		}
		cout<<endl;
	}

	void PrevOrderThreading()
	{
		Node* prev = NULL;
		_PrevOrderThreading(_root, prev);
	}

	void PrevOrderThd()
	{
		Node* cur = _root;
		while (cur)
		{
			while (cur && cur->_leftTag == LINK)
			{
				cout<<cur->_data<<" ";
				cur = cur->_left;
			}

			cout<<cur->_data<<" ";

			cur = cur->_right;
			
			/*
			while(cur && cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout<<cur->_data<<" ";
			}

			if(cur)
				cur = cur->_right;*/
		}
		cout<<endl;
	}

	void PostOrderThreading()
	{
		Node* prev = NULL;
		_PostOrderThreading(_root, prev);
	}

protected:
	void _PostOrderThreading(Node* cur, Node*& prev)
	{
		if(cur == NULL)
			return;

		_PostOrderThreading(cur->_left, prev);
		_PostOrderThreading(cur->_right, prev);

		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		if (prev->_right == NULL)
		{	
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}

		prev = cur;
	}

	void _PrevOrderThreading(Node* cur, Node* & prev)
	{
		if (cur == NULL)
			return;
		
		// 线索化
		if(cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}

		prev = cur;

		// 递归线索化子树
		if(cur->_leftTag == LINK)
			_PrevOrderThreading(cur->_left, prev);

		if(cur->_rightTag == LINK)
			_PrevOrderThreading(cur->_right, prev);
	}

	void _InOrderThreading(Node* root, Node* & prev)
	{
		if(root == NULL)
			return;
		
		_InOrderThreading(root->_left, prev);
	
		// 线索化左
		if(root->_left == NULL)
		{
			root->_leftTag = THREAD;
			root->_left = prev;
		}

		// 线索化上一个节点的右
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = root;
		}

		prev = root;

		_InOrderThreading(root->_right, prev);
	}


	Node* _CreateTree(T* a, size_t size,
		size_t& index, const T& invalid)
	{
		Node* root = NULL;
		if (index < size && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, size,
				++index, invalid);
			root->_right = _CreateTree(a, size,
				++index, invalid);
		}

		return root;
	}

protected:
	Node* _root;
};

void TestBinaryTreeThd()
{
	//int array[10] = {1, 2, 3, '#', '#', 4, '#' , '#', 5, 6};
	//BinaryTreeThd<int> t1(array, 10, '#');
	//t1.InOrderThreading();
	//t1.InOrderThd();

	//BinaryTreeThd<int> t2(array, 10, '#');
	//t2.PrevOrderThreading();
	//t2.PrevOrderThd();

	//int array2[15] = {1,2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#',8}; 
	//BinaryTreeThd<int> t3(array2, 15, '#');
	//t3.InOrderThreading();
	//t3.InOrderThd();

	//BinaryTreeThd<int> t4(array2, 15, '#');
	//t4.PrevOrderThreading();
	//t4.PrevOrderThd();

	int array[10] = {1, 2, 3, '#', '#', 4, '#' , '#', 5, 6};
	BinaryTreeThd<int> t1(array, 10, '#');
	t1.InOrderThreading();
	t1.InOrderThd();

	BinaryTreeThd<int>::Iterator it = t1.Begin();
	while (it != t1.End())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}
