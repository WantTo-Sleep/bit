#include "SList.h"

// �������ӡ
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

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* temp = (SListNode*)malloc(sizeof(SListNode));
	assert(temp);
	temp->data = x;
	temp->next = NULL;
	return temp;
}

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* temp = BuySListNode(x);
	temp->next = *pplist;
	*pplist = temp;
}

// ������β��
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

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist && *pplist);

	SListNode* temp = (*pplist)->next;
	free(*pplist);
	*pplist = temp;

}

// �������βɾ
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

// ���������
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

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);

	SListNode* temp = BuySListNode(x);
	temp->next = pos->next;
	pos->next = temp;
}

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode* temp = pos->next;
	if (temp == NULL)
		return;
	pos->next = temp->next;
	free(temp);
}

// �����������
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