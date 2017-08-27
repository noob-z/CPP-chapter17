/*list.c 支持链表操作的函数*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*局部函数原型*/
static void CopyToNode(Item item, List pnode);

/*接口函数*/
/*把链表设置为空*/
void InitializeList(List *plist)
{
	*plist = NULL;
}

/*如果链表为空，返回true*/
bool ListIsEmpty(List *plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

/*如果链表已满，返回true*/
bool ListIsFull(List *plist)
{
	Node * pt;
	bool full;
	pt = (Node *)malloc(sizeof(Node));
	if (pt = NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

/*返回节点的数量*/
unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node * pnode = *plist; /*设置链表的开始*/

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

/*创建存储项的节点，并将其添加至由plist指向的链表末尾*/
bool AddItem(Item item, List *plist)
{
	Node * pnew;
	Node * scan = *plist;
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;/*失败时退出函数*/
	CopyToNode(item, pnew);
	pnew->next = NULL;
	
	if (scan == NULL)/*空链表*/
		*plist = pnew;/*pnew放在链表开头*/
	else
	{
		while (scan->next != NULL)
			scan = scan->next;/*找到链表末尾*/
		scan->next = pnew;/*把pnew添加到链表末尾*/
	}
	return true;
}

/*访问每个节点并执行pfun指向的函数*/
void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node * pnode = *plist;

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/*释放由malloc()分配的内存*/
/*设置链表指针为NULL*/
void EmptyTheList(List *plist)
{
	Node * psave;

	while (*plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

/*局部函数定义*/
/*把一个项目拷贝到节点中*/
static void CopyToNode(Item item, List pnode)
{
	pnode->item = item;
}