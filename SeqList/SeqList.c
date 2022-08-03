#include "SeqList.h"
// 初始化
void SeqListInit(SeqList* ps)
{
	assert(ps);

	ps->size = 1;
	ps->capacity = 4;
	ps->a = (SLDateType*)calloc(ps->capacity, sizeof(SLDateType));
}
// 销毁
void SeqListDestroy(SeqList* ps)
{
	assert(ps);

	free(ps->a);
	ps->capacity = 0;
	ps->size = 0;
}
// 检查容量并扩容
static int CheckCapacity(SeqList* ps)
{
	if (ps->capacity == ps->size)
	{
		SLDateType* temp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (temp != NULL)
		{
			ps->a = temp;
			ps->capacity *= 2;
			return 1;
		}
		else
		{
			printf("容量已满，扩容失败！\n");
			return -1;
		}
	}
	return 0;
}
// 打印顺序表
void SeqListPrint(SeqList* ps)
{
	assert(ps);

	for (size_t i = 1; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
// 尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);

	if (-1 == CheckCapacity(ps))
		return;
	ps->a[ps->size++] = x;
}
// 头插
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);

	if (-1 == CheckCapacity(ps))
		return;
	for (size_t i = ps->size; i > 1; --i)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[1] = x;
	ps->size++;
}
// 尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);

	assert(ps->size != 0);
	ps->size--;
}
// 头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);

	assert(ps->size != 0);
	
	for (size_t i = 1; i + 1 < ps->size; ++i)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	
	for (size_t i = 1; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	
	CheckCapacity(ps);
	for (size_t i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);

	assert(ps->size != 0 && pos != 0);
	for (size_t i = pos; i + 1 < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}