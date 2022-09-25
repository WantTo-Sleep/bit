#include "Stack.h"
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		ps->capacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* temp = (STDataType*)realloc(ps->a, ps->capacity * sizeof(STDataType));
		if (temp == NULL)
		{
			perror("Increase Capacity Fail");
			exit(-1);
		}
		ps->a = temp;
	}
	ps->a[ps->top] = data;
	ps->top++;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
		return 1;
	return 0;

}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
}