#include<iostream>
using namespace std;
//#include<cassert>

class UnionFindSet
{
private:
	int* _a;
	int _n;
public:
	//���ڵ����Ϣ��ʼ��Ϊ-1����ʾÿ������ֻ������һ���ڵ�
	//��1��ÿ�����ڵ�ľ���ֵ��ʾ��������м����ڵ㣻
	//��2�����ڼ����������м�����
	//��3�����ڵ���0�Ľڵ��ʾ����ڵ��λ��

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

//���ҽڵ�ĸ��ڵ�
	int FindRoot(int x)
	{
		int root = x;
		while(_a[root] >= 0)
		{
			root = _a[root];
		}
		return root;
	}
//��x2����x1�ĸ��ڵ��£�
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
	//nΪ�ڵ���ܸ�����
	//mΪ���Խڵ���ڹ�ϵ��
	//arrΪ��ϵ����
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
	cout<<"���ڼ�����:"<<count<<endl;
}