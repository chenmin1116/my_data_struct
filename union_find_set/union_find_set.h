#include<iostream>
using namespace std;
//#include<cassert>

class UnionFindSet
{
private:
	int* _a;
	int _n;
public:
	//将节点的信息初始化为-1，表示每个树中只有自身一个节点
	//（1）每个根节点的绝对值表示这个数中有几个节点；
	//（2）存在几个负数就有几棵树
	//（3）大于等于0的节点表示其根节点的位置

	UnionFindSet(int n)
		:_n(n)
	{
		_a = new int[n+1];
		for(int i=0;i<n+1;++i)
		{
			_a[i] = -1;
		}
	}

	~UnionFindSet()
	{
		delete[] _a;
	}

//查找节点的父节点
	int FindRoot(int x)
	{
		int root = x;
		while(_a[root] >= 0)
		{
			root = _a[root];
		}
		return root;
	}
//将x2并到x1的根节点下；
	void Union(int x1,int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if(root1 != root2)
		{
			_a[root1] += _a[root2];
			_a[root2] = root1;
		}
	}

	int  CountRootNode()
	{
		int count = 0;
		for(int i=0;i<_n;i++)
		{
			if(_a[i] < 0)
			{
				++count;
			}
		}
		return count;
	}
};



int Node(int n,int m,int arr[][2])
{
	//n为节点的总个数；
	//m为几对节点存在关系；
	//arr为关系数组
	UnionFindSet ufs(n);
	for(int i=0;i<m;i++)
	{
		ufs.Union(arr[i][0],arr[i][1]);
	}
	int count = ufs.CountRootNode();
	return count;
}

void TestUnionFind()
{
	int arr[][2]={{0,6},{0,7},{0,8},{1,4},{1,9},{2,3},{2,5}};
	int count = Node(10,7,arr);
	cout<<"存在几棵树:"<<count<<endl;
}