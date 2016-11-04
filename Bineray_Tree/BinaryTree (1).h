#pragma once
#include <queue>
#include <stack>

template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	BinaryTreeNode(const T& x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
	{}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}

	BinaryTree(T* a, size_t size, const T& invalid)
	{
		assert(a);
		size_t index = 0;
		_root = _CreateTree(a, size, index, invalid);
	}

	BinaryTree(const BinaryTree<T>& t)
	{
		_root = _Copy(t._root);
	}

	//BinaryTree<T>& operator=(const BinaryTree<T>& t)
	//{
	//	if (this != &t)
	//	{
	//		Node* root = _Copy(t._root);
	//		_Destory(_root);
	//		_root = root;
	//	}

	//	return *this;
	//}

	BinaryTree<T>& operator=(BinaryTree<T> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~BinaryTree()
	{
		_Destory(_root);
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout<<endl;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout<<endl;
	}

	void PrevOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				cout<<cur->_data<<" ";
				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			s.pop();
			// 访问top的右子树
			cur = top->_right;
		}
		cout<<endl;
	}

	void InOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{	
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			cout<<top->_data<<" ";
			s.pop();
			cur = top->_right;
		}
		cout<<endl;
	}

	void PostOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		Node* prev = NULL;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			// 1.如果右树访问过了，则访问当前节点
			// 2.如果右树没有访问过，则跳到右树去访问（子问题的思想）
			if (top->_right == NULL || top->_right == prev)
			{
				cout<<top->_data<<" ";
				prev = top;
				s.pop();
			}
			else
			{
				cur = top->_right;
			}
		}

		cout<<endl;
	}

	// queue
	void LevelOrder()
	{
		queue<Node*> q;
		if (_root)
			q.push(_root);

		while (!q.empty())
		{
			Node* front = q.front();
			q.pop();
			cout<<front->_data<<" ";
			if (front->_left)
				q.push(front->_left);
			if (front->_right)
				q.push(front->_right);
		}

		cout<<endl;
	}

	size_t Size()
	{
		return _Size(_root);
	}

	size_t Depth()
	{
		return _Depth(_root);
	}

	Node* Find(const T& x)
	{
		return _Find(_root, x);
	}

	size_t FindKLevel(size_t k)
	{
		size_t level = 1;
		return _FindKLevel(_root, k, level);
	}

	size_t FindLeafSize()
	{
		return _FindLeafSize(_root);
	}

protected:
	Node* _Copy(Node* root)
	{
		if(root == NULL)
			return NULL;
		
		Node* newRoot = new Node(root->_data);
		newRoot->_left = _Copy(root->_left);
		newRoot->_right = _Copy(root->_right);
		return newRoot;
	}

	void _Destory(Node* root)
	{
		if (root == NULL)
			return;

		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
	}

	size_t _FindLeafSize(Node* root)
	{
		if (root == NULL)
			return 0;

		if (root->_left == NULL && root->_right == NULL)
			return 1;

		return _FindLeafSize(root->_left) + 
			_FindLeafSize(root->_right);
	}

	/*size_t _FindKLevel(Node* root, size_t k)
	{
		if (root == NULL)
			return 0;

		if (k == 1)
			return 1;

		return _FindKLevel(root->_left, k-1)
			+ _FindKLevel(root->_right, k-1);
	}*/

	size_t _FindKLevel(Node* root, size_t k, size_t level)
	{
		static size_t num = 0;
		if (root == NULL)
			return 0;

		if (level == k)
		{
			++num;
			return num;
		}
		
		_FindKLevel(root->_left, k, level+1);
		_FindKLevel(root->_right, k, level+1);

		return num;
	}

	void _PrevOrder(Node* root)
	{
		if (root == NULL)
			return;

		cout<<root->_data<<" ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout<<root->_data<<" ";
		_InOrder(root->_right);
	}

	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;

		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout<<root->_data<<" ";
	}

	// O(lg(N))x
	// O(N)
	/*size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}*/

	size_t _Size(Node* root)
	{
		static size_t count = 0;
		if (root == NULL)
			return 0;

		++count;
		_Size(root->_left);
		_Size(root->_right);

		return count;
	}

	//size_t _Depth(Node* root)
	//{
	//	if (root == NULL)
	//		return 0;

	//	return _Depth(root->_left) > _Depth(root->_right) 
	//		? _Depth(root->_left)+1: _Depth(root->_right)+1;
	//}

	size_t _Depth(Node* root)
	{
		if (root == NULL)
			return 0;

		size_t leftD = _Depth(root->_left);
		size_t rightD = _Depth(root->_right);
		return leftD > rightD ? leftD+1 : rightD+1;
	}

	// O(N)/O(1)
	Node* _Find(Node* root, const T& x)
	{
		if (root == NULL)
			return NULL;

		if (root->_data == x)
			return root;

		Node* ret = _Find(root->_left, x);
		// 如果左子树没有找到，再到右子树去找
		if (ret == NULL)
			ret = _Find(root->_right, x);

		return ret;
	}

	Node* _CreateTree(T* a, size_t size,
		size_t& index,const T& invalid)
	{
		Node* root = NULL;
		if (index < size && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, size, ++index, invalid);
			root->_right = _CreateTree(a, size, ++index, invalid);
		}

		return root;
	}

protected:
	Node* _root;
};

//
// t1
// t2
// 多线程
//
void TestBinaryTree()
{
	int array[10] = {1, 2, 3, '#', '#', 4, '#' , '#', 5, 6};
	BinaryTree<int> t1(array, 10, '#');
	t1.PrevOrder();
	t1.PrevOrderNonR();
	t1.InOrder();
	t1.InOrderNonR();
	t1.PostOrder();
	t1.PostOrderNonR();

	cout<<"Size?"<<t1.Size()<<endl;
	cout<<"Leaf Size?"<<t1.FindLeafSize()<<endl;
	cout<<"K Level Size?"<<t1.FindKLevel(3)<<endl;
	cout<<"Depth?"<<t1.Depth()<<endl;
	// 黑盒测试、白盒测试
	BinaryTreeNode<int>* ret = t1.Find(6);
	assert(ret);
	cout<<"Find 6?"<<ret->_data<<endl;
	ret = t1.Find(10);
	cout<<"Find 10?"<<ret<<endl;

	t1.LevelOrder();

	int array2[15] = {1,2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#',8}; 
	BinaryTree<int> t2(array2, 15, '#');
	t2.PrevOrder();
	t2.PrevOrderNonR();
	t2.InOrder();
	t2.InOrderNonR();
	t2.PostOrder();
	t2.PostOrderNonR();
}

template<class T>
struct BinaryTreeNodeP
{
	T _data;
	BinaryTreeNodeP<T>* _left;
	BinaryTreeNodeP<T>* _right;
	BinaryTreeNodeP<T>* _parent;

	BinaryTreeNodeP(const T& x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
};

template<class T>
class BinaryTreeP
{
	typedef BinaryTreeNodeP<T> Node;
	BinaryTreeP(T* a, size_t size, const T& invalid)
	{
		assert(a);
		size_t index = 0;
		_root = _CreateTree(a, size, index, invalid);
	}

protected:
	Node* _CreateTree(T* a, size_t size, size_t& index,
		const T& invalid)
	{
		Node* root = NULL;
		if (index < size && a[index] != invalid)
		{
			root = new Node(a[index]);
			Node* left = _CreateTree(a, size,
				++index, invalid);
			Node* right = _CreateTree(a, size,
				++index, invalid);

			root->_left = left;
			root->_right = right;
			if(left)
				left->_parent = root;
			if(right)
				right->_parent = root;
		}

		return root;
	}

	Node* _root;
};

