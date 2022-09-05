#include "SList.h"

// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* temp = (SListNode*)malloc(sizeof(SListNode));
	assert(temp);
	temp->data = x;
	temp->next = NULL;
	return temp;
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* temp = BuySListNode(x);
	temp->next = *pplist;
	*pplist = temp;
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	if (*pplist == NULL)
	{
		*pplist = BuySListNode(x);
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuySListNode(x);
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist && *pplist);

	SListNode* temp = (*pplist)->next;
	free(*pplist);
	*pplist = temp;

}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist && *pplist);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* temp = *pplist;
		while (temp->next->next)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);

	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);

	SListNode* temp = BuySListNode(x);
	temp->next = pos->next;
	pos->next = temp;
}

// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode* temp = pos->next;
	if (temp == NULL)
		return;
	pos->next = temp->next;
	free(temp);
}

// 单链表的销毁
void SListDestroy(SListNode* plist)
{
	assert(plist);
	SListNode* cur = plist->next;
	while (cur)
	{
		free(plist);
		plist = cur;
		cur = cur->next;
	}
	free(plist);
}