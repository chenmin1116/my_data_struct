#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
using namespace std;

typedef struct LinkNode
{
	int _value;
	struct LinkNode* _next;
}LinkNode,*pLinkNode;

typedef struct LinkList
{
	LinkNode* _phead;
}LinkList,*pLinkList;

void Init_LinkList(pLinkList plist)
{
	assert(plist);
	plist->_phead = NULL;
	//plist->_phead = plist->_phead->_next;
}

pLinkNode Creat_Node_LinkList(int value)
{
	pLinkNode NewNode = (pLinkNode)malloc(sizeof(LinkNode));
	if(NewNode == NULL)
	{
		cout<<"分配内存失败！！！"<<endl;
		return NULL;
	}
	else
	{
		NewNode->_value = value;
		NewNode->_next = NULL;
		return NewNode;
	}
}
void Push_Back_LinkList(pLinkList plist,int value)//单链循环链表后插
{
	assert(plist);
	pLinkNode NewNode = Creat_Node_LinkList(value);
	if(plist->_phead == NULL)
	{
		plist->_phead = NewNode;
		NewNode->_next = plist->_phead ;
	}
	else
	{
		pLinkNode cur = plist->_phead;
		while(cur->_next != plist->_phead)
		{
			cur = cur->_next ;
		}
		cur->_next = NewNode;
		NewNode->_next = plist->_phead ;
	}
}

void Push_Front_LinkList(pLinkList plist,int value)//单链循环链表前插
{
	assert(plist);
	pLinkNode NewNode = Creat_Node_LinkList(value);
	if(plist->_phead == NULL)
	{
		plist->_phead = NewNode;
		NewNode->_next = plist->_phead ;
	}
	else
	{
		NewNode->_next = plist->_phead;
		plist->_phead = NewNode;
	}
}
void Display_LinkList(pLinkList plist)
{
	assert(plist);
	if(plist->_phead == NULL)
	{cout<<"This LinkList is Empty!!!"<<endl;}
	pLinkNode cur = plist->_phead;
	while(cur->_next  != plist->_phead)
	{
		cout<<cur->_value<<"->";
		cur = cur->_next ;
	}
	cout<<"NULL"<<endl;
}


void Jonsepher_cycle(pLinkList plist,int k,int m)//将数据存入循环单链表中，k为从第几个节点开始计数,m位数到第m个数就删除这个数
{
	int count = 1;
	pLinkNode cur = plist->_phead ;
	pLinkNode prev = plist->_phead ;
	pLinkNode del = NULL;
	while(count != k)       //找到开始的点
	{
		cur = cur->_next;
		++count;
	}
	//cur指向了开始的节点；
	count = 1;
	while(cur->_next != cur)
	{
		prev = cur;
		cur = cur->_next;
		++count;
		if(count == m)
		{
			del = cur;
			if(cur == plist->_phead)
			{
				plist->_phead = plist->_phead ->_next;
			}
			prev->_next = cur->_next;
			cout<<del->_value<<"->";
			free(del);
			del = NULL;
			cur = prev->_next;
			count = 1;
		}
	}
	
}
void TestLinkListCycle()
{
	LinkList list;
	Init_LinkList(&list);
	Push_Back_LinkList(&list,1);
	Push_Back_LinkList(&list,2);
    Push_Back_LinkList(&list,3);
	Push_Back_LinkList(&list,4);
	Display_LinkList(&list);
	Jonsepher_cycle(&list,2,3);//对于list从第二个节点开始每隔三个节点就删除一个；
}