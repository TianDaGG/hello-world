/*================================================================
*   Copyright (C) 2019 * Ltd. All rights reserved.
*
*   File name   : singal_list.c
*   Author      : mabu
*   QQ          : 1105403369
*   Created date: 2019-10-27 20:01:43
*   Description : 实现简单的单链表
*
*===============================================================*/

#include<iostream>
#include<string.h>
using std::cout;
using std::cin;
using std::endl;

typedef struct node
{
	int data;
	struct node* pNext;
}*pNode, Node;

bool headIsNull = true;

pNode InitNode();
void InsertNode(pNode head, int data);
void FindNode(pNode head, int data);
void ModifyNode(pNode head, int oldData, int newData);
void DeleteNode(pNode head, int delData);
void SortNode(pNode head);
void FreeNode(pNode head);
void PrintNode(pNode head);
int main(int argc, char *argv[])
{
	pNode head = InitNode();
	//插入
	int listSize;
	cout << "请输入链表大小：" << endl;
	cin >> listSize;
	for (int i = 0; i<listSize; ++i)
	{
		int num;
		cout << "请输入要插入的数据：" << endl;
		cin >> num;
		InsertNode(head, num);
	}
	PrintNode(head);
	//查找
	int findNum;
	cout << "请输入你要查找的数据：" << endl;
	cin >> findNum;
	FindNode(head, findNum);
	PrintNode(head);
	//修改
	int newData, oldData;
	cout << "请输入你要修改的数字和修改后的数据：" << endl;
	cin >> oldData >> newData;
	ModifyNode(head, oldData, newData);
	PrintNode(head);
	//删除
	int delData;
	cout << "请输入要删除的数：" << endl;
	cin >> delData;
	DeleteNode(head, delData);
	PrintNode(head);
	//排序
	SortNode(head);
	PrintNode(head);
	//释放所有内存
	FreeNode(head);
	return 0;
}
pNode InitNode()
{
	pNode tmp = new Node;
	tmp->pNext = NULL;
	return tmp;
}
void InsertNode(pNode head, int data)
{
	if (headIsNull == true)
	{
		head->data = data;
		headIsNull = false;
	}
	else
	{
		pNode p = head;
		while (p->pNext != NULL)
			p = p->pNext;

		pNode temp = new node;
		temp->data = data;
		temp->pNext = NULL;
		p->pNext = temp;
	}
}

void FindNode(pNode head, int data)
{
	pNode p = head;
	while (p->pNext)
	{
		if (p->data == data)
		{
			cout << "数据查找到了:" << p->data << endl;
			return;
		}
		else
			p = p->pNext;
	}
	if (p->data == data)
	{
		cout << "数据查找到了:" << p->data << endl;
		return;
	}
	cout << "抱歉，没有你要查找的数据!" << endl;
}

void ModifyNode(pNode head, int oldData, int newData)
{
	pNode p = head;
	while (p->pNext)
	{
		if (p->data == oldData)
		{
			p->data = newData;
			cout << "数据修改成功!" << endl;
			return;
		}
		else
			p = p->pNext;
	}
	if (p->data == oldData)
	{
		p->data = newData;
		cout << "数据修改成功!" << endl;
		return;
	}
	cout << "抱歉，没有找到你要修改的数据！" << endl;
}

void DeleteNode(pNode head, int delData)
{
	pNode p = head;
	if (delData == p->data)
	{
		head = p->pNext;
		delete p;
		p = NULL;
		cout << "删除数据成功！" << endl;
		return;
	}
	while (p->pNext)
	{
		if (p->pNext->data == delData)
		{
			pNode tmp = p->pNext;
			p->pNext = tmp->pNext;
			delete tmp;
			tmp = NULL;
			cout << "数据删除成功！" << endl;
			return;
		}
		else
			p = p->pNext;
	}
	cout << "抱歉，没有找到你要删除的数据！" << endl;
}

void SortNode(pNode head)
{
	pNode p = head;
	int position = 0;
	while (p->pNext)
	{
		++position;
		p = p->pNext;
	}
	++position;
	p = head;
	
	for (int i = 0; i<position - 1; ++i)
	{
		pNode tmp = p->pNext;
		for (int j = i + 1; j<position; ++j)
		{
			if (p->data>tmp->data)
			{
				pNode q = new Node;
				q->data = p->data;
				p->data = tmp->data;
				tmp->data = q->data;
			}
			tmp = tmp->pNext;
		}
		p = p->pNext;
	}
}

void FreeNode(pNode head)
{
	pNode p=head;
	while(p)
	{
		pNode temp=p->pNext;
		delete p;
		p=temp;
	}
}
void PrintNode(pNode head)
{
	pNode p = head;
	while (p->pNext)
	{
		cout << p->data << "->";
		p = p->pNext;
	}
	cout << p->data << endl;
}