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
		cout<<"�����ڴ�ʧ�ܣ�����"<<endl;
	}
	
	NewNode->_value = value;
	NewNode->_next = NULL;
	return NewNode;
	
}
void Insert_Index_Back_LinkList(pLinkList plist,pLinkNode pos,int value)//�ض�λ�ú���룻
{
	//���ڿ�������в���
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
void Insert_Index_Front_LinkList(pLinkList plist,pLinkNode pos,int value)//�ض�λ�ú���룻
{
	//1.��������룻
	//2.�ǿ�������룻
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
void Remove_LinkList(pLinkList plist,int value)  //ɾ���ض�Ԫ�ص��׸��ڵ㣻
{
	assert(plist);
	pLinkNode del = plist->_phead;
	pLinkNode cur = plist->_phead;
	if(plist->_phead == NULL)          //������Ϊ������
	{
		cout<<"������Ϊ����������"<<endl;
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
void RemoveAll_LinkList(pLinkList plist,int value)//ɾ���ض�Ԫ�ص����нڵ㣻
{
	//1.������������Ϊ������
	//2.
	assert(plist);
	pLinkNode del = plist->_phead;
	pLinkNode cur = plist->_phead;
	if(plist->_phead == NULL)
	{
		cout<<"�˲���������Ϊ����������"<<endl;
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
//void Sort_LinkList(pLinkList plist)//��������Ľڵ�Ԫ�ؽ�����������
//{
//	assert(plist);
//	pLinkNode cur1 = plist->_phead;
//	pLinkNode cur2 = plist->_phead;
//	pLinkNode tmp = plist->_phead;
//    if(plist->_phead == NULL)
//	{cout<<"������Ϊ�գ�����"<<endl;}
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
//						plist->_phead = plist->_phead->_next ;   //����ͷ���
//						//��tmp�ڵ���뵽cur2�ڵ�֮��
//						tmp->_next = cur2->_next;
//						cur2->_next = tmp;
//				        //��tmp֮��Ľڵ㸳��tmp������������ɾ����
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
pLinkNode Find_LinkList(pLinkList plist,int value)//����������ض�Ԫ�أ�
{
	assert(plist);
	pLinkNode cur = plist->_phead;
	if(plist->_phead == NULL)
	{cout<<"������Ϊ����������"<<endl;}
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
void Pop_Front_LinkList(pLinkList plist)   //ǰɾ
{
	assert(plist);
	if(plist->_phead == NULL)
	{
		cout<<"������Ϊ������"<<endl;
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

void Pop_Back_LinkList(pLinkList plist)   //��ɾ
{
	assert(plist);
	pLinkNode cur = plist->_phead;
	pLinkNode pre = plist->_phead;
	if(cur == NULL)
	{
		cout<<"������Ϊ����������"<<endl;
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
	if(cur == NULL)   //����β�������Ϊ������
	{
		plist->_phead = NewNode;
		NewNode->_next = NULL;
	}
	else             //����β�������Ϊ�գ�
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
		cout<<"������Ϊ������"<<endl;
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