#include "SeqList.h"

void DeletOne(SeqList* ps, SLDateType delet);

int main()
{
	SeqList seq;
	SeqListInit(&seq);
	for (SLDateType i = 0; i < 9; ++i)
	{
		SeqListPushBack(&seq, i);
		SeqListPushBack(&seq, 3);
	}

	SeqListPrint(&seq);
	
	printf("É¾³ý 3\n");
	
	DeletOne(&seq, 3);

	SeqListPrint(&seq);

	return 0;
}

void DeletOne(SeqList* ps, SLDateType delet)
{
	assert(ps);

	int i = SeqListFind(ps, delet);
	while (i != -1)
	{
		SeqListErase(ps, i);
		i = SeqListFind(ps, delet);
	}
}