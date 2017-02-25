#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<iostream>
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
}
pLinkNode CreatNode_LinkList(int value)
{
	pLinkNode NewNode =(pLinkNode) malloc(sizeof(LinkNode));
	if(NewNode == NULL)
	{
		cout<<"分配内存失败！！！"<<endl;
	}
	
	NewNode->_value = value;
	NewNode->_next = NULL;
	return NewNode;
	
}
void Insert_Index_Back_LinkList(pLinkList plist,pLinkNode pos,int value)//特定位置后插入；
{
	//对于空链表进行插入
	assert(plist);
	pLinkNode cur = NULL;
	pLinkNode NewNode = CreatNode_LinkList(value);
	cur = plist->_phead;
	if(cur == NULL)
	{
		plist->_phead = NewNode;
		NewNode->_next = NULL;
	}
	else
	{
		while(cur != pos)
		{
			cur = cur->_next;
		}
		NewNode->_next = cur->_next;
		cur->_next = NewNode;
	}
}
void Insert_Index_Front_LinkList(pLinkList plist,pLinkNode pos,int value)//特定位置后插入；
{
	//1.空链表插入；
	//2.非空链表插入；
	assert(plist);
	pLinkNode cur = plist->_phead;
	pLinkNode NewNode = CreatNode_LinkList(value);
	if(plist->_phead == NULL)
	{
		plist->_phead = NewNode;
		NewNode->_next = NULL;
	}
	else
	{
		while(cur->_next != pos)
		{
			cur = cur->_next;
		}
		NewNode->_next = cur->_next;
		cur->_next = NewNode;
	}
}
void Remove_LinkList(pLinkList plist,int value)  //删除特定元素的首个节点；
{
	assert(plist);
	pLinkNode del = plist->_phead;
	pLinkNode cur = plist->_phead;
	if(plist->_phead == NULL)          //此链表为空链表
	{
		cout<<"此链表为空链表！！！"<<endl;
	}
	if(plist->_phead->_next->_value == value)
	{
		plist->_phead = plist->_phead->_next;
		free(del);
		del = NULL;
	}
	else
	{
		while(cur != NULL)
		{
			if(cur->_value == value)
			{
				del->_next = cur->_next;
				break;
			}
			del = cur;
			cur = cur->_next;
		}
	}
}
void RemoveAll_LinkList(pLinkList plist,int value)//删除特定元素的所有节点；
{
	//1.当所操作链表为空链表
	//2.
	assert(plist);
	pLinkNode del = plist->_phead;
	pLinkNode cur = plist->_phead;
	if(plist->_phead == NULL)
	{
		cout<<"此操作的链表为空链表！！！"<<endl;
	}
	else
	{
		while(cur != NULL)
		{
			if(cur == plist->_phead && cur->_value == value)
			{
				plist->_phead = plist->_phead->_next;
			}
			if(cur != plist->_phead && cur->_value == value)
			{
				del->_next = cur->_next;
			}
			del = cur;
			cur = cur->_next;
		}
	}
}
//void Sort_LinkList(pLinkList plist)//对于链表的节点元素进行排序；升序
//{
//	assert(plist);
//	pLinkNode cur1 = plist->_phead;
//	pLinkNode cur2 = plist->_phead;
//	pLinkNode tmp = plist->_phead;
//    if(plist->_phead == NULL)
//	{cout<<"此链表为空！！！"<<endl;}
//	else
//	{
//		while(cur1 != NULL)
//		{
//			pLinkNode tmp = plist->_phead;
//			while(cur2 != NULL)
//			{
//				cur2 = cur2->_next;
//				if(cur2->_next->_value > tmp->_value)
//				{
//					if(tmp = plist->_phead)
//					{
//						plist->_phead = plist->_phead->_next ;   //处理头结点
//						//将tmp节点插入到cur2节点之后
//						tmp->_next = cur2->_next;
//						cur2->_next = tmp;
//				        //将tmp之后的节点赋给tmp，并在链表中删除；
//						tmp = tmp->_next;
//						cur2->_next->_next = cur2->_next->_next->_next;
//					}
//					else
//					{
//						tmp
//					}
//				}
//			}
//			cur1 = cur1->_next;
//		}
//	}
//}
pLinkNode Find_LinkList(pLinkList plist,int value)//查找链表的特定元素；
{
	assert(plist);
	pLinkNode cur = plist->_phead;
	if(plist->_phead == NULL)
	{cout<<"此链表为空链表！！！"<<endl;}
	else
	{
		while(cur != NULL)
		{
			if(cur->_value == value)
				return cur;
			else
				cur = cur->_next;
		}
	}
	return NULL;
}
void Pop_Front_LinkList(pLinkList plist)   //前删
{
	assert(plist);
	if(plist->_phead == NULL)
	{
		cout<<"此链表为空链表"<<endl;
	}
	if(plist->_phead->_next == NULL)
	{
		free(plist->_phead);
		plist->_phead = NULL;
	}
	else
	{
		pLinkNode del = plist->_phead;
		plist->_phead = plist->_phead->_next;
		free(del);
		del = NULL;
	}
}

void Pop_Back_LinkList(pLinkList plist)   //后删
{
	assert(plist);
	pLinkNode cur = plist->_phead;
	pLinkNode pre = plist->_phead;
	if(cur == NULL)
	{
		cout<<"此链表为空链表！！！"<<endl;
	}
	if(cur->_next == NULL)
	{
		free(cur);
		cur = NULL;
	}
	else
	{
		while(cur->_next != NULL)
		{
			pre = cur;
			cur = cur->_next;
		}
		pre->_next = NULL;
		free(cur);
		cur = NULL;
	}
}
void Push_Front_LinkList(pLinkList plist,int value)
{
	pLinkNode NewNode = CreatNode_LinkList(value);
	if(plist->_phead == NULL)
	{
		plist->_phead = NewNode;
		NewNode->_next = NULL;
	}
	else
	{
		NewNode->_next = plist->_phead;
		plist->_phead = NewNode;
	}
}

void Push_Back_LinkList(pLinkList plist,int value)
{
	pLinkNode cur = NULL;
	pLinkNode NewNode = NULL;
	NewNode = CreatNode_LinkList(value);
	cur = plist->_phead ;
	if(cur == NULL)   //进行尾插的链表为空链表
	{
		plist->_phead = NewNode;
		NewNode->_next = NULL;
	}
	else             //进行尾插的链表不为空；
	{
		while(cur->_next != NULL)
		{
			cur = cur->_next ;
		}
		cur->_next = NewNode;
		NewNode->_next = NULL;
	}
}

void Display_LinkList(pLinkList plink)
{
	if(plink->_phead == NULL)
	{
		cout<<"此链表为空链表！"<<endl;
	}
	else
	{
		pLinkNode cur = plink->_phead ;
		while(cur)
		{
			cout<<cur->_value <<"->";
			cur = cur->_next ;
		}
		cout<<"NULL"<<endl;
	}
}

void Test1()
{
	LinkList list ;
	LinkList list1;
	Init_LinkList(&list);
	Init_LinkList(&list1);
	Push_Back_LinkList(&list,1);
	Push_Back_LinkList(&list,2);
	Push_Back_LinkList(&list,3);
	Push_Back_LinkList(&list,4);
	Push_Front_LinkList(&list,0);
	Pop_Back_LinkList(&list);
	Pop_Front_LinkList(&list);
	Display_LinkList(&list);          //1-3
	Push_Back_LinkList(&list1,5);
	Push_Back_LinkList(&list1,6);
	Push_Front_LinkList(&list1,4);
	Push_Front_LinkList(&list1,3);
	Push_Front_LinkList(&list1,2);
	Push_Front_LinkList(&list1,1);
	Push_Front_LinkList(&list1,0);
	Pop_Back_LinkList(&list1);
	Pop_Front_LinkList(&list1);       
	Display_LinkList(&list1);      //1-5
}

void Test2()
{
	LinkList list;
	Init_LinkList(&list);
	Push_Back_LinkList(&list,1);
	//Push_Back_LinkList(&list,2);
    Push_Back_LinkList(&list,3);
   // Push_Back_LinkList(&list,4);
	Push_Back_LinkList(&list,5);
	Push_Back_LinkList(&list,6);
	Display_LinkList(&list);
	pLinkNode find = Find_LinkList(&list,3);
	Insert_Index_Front_LinkList(&list,find,2);
	Insert_Index_Back_LinkList(&list,find,4);
	Display_LinkList(&list);
}

void Test3()
{
	LinkList list;
	Init_LinkList(&list);
	Push_Back_LinkList(&list,0);
	Push_Back_LinkList(&list,1);
	Push_Back_LinkList(&list,2);
	Push_Back_LinkList(&list,3);
	Push_Back_LinkList(&list,3);
	Push_Back_LinkList(&list,4);
	Push_Back_LinkList(&list,5);
	Push_Back_LinkList(&list,4);
	Push_Back_LinkList(&list,6);
	Remove_LinkList(&list,3);
	Display_LinkList(&list);//0 1 2 3 4 4 5 6
	RemoveAll_LinkList(&list,4);
	Display_LinkList(&list);//0 1 2 3 5 6
}