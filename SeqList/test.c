#include "SeqList.h"

testSeqList1()
{
	SeqList seq;
	SeqListInit(&seq);

	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 4);
	SeqListPrint(&seq);
	SeqListPushFront(&seq, 5);
	SeqListPushFront(&seq, 6);
	SeqListPushFront(&seq, 7);
	SeqListPushFront(&seq, 8);
	SeqListPrint(&seq);
	SeqListInsert(&seq, SeqListFind(&seq, 4), 10);
	SeqListInsert(&seq, SeqListFind(&seq, 8), 9);
	SeqListInsert(&seq, SeqListFind(&seq, 1), 0);
	SeqListPrint(&seq);
	SeqListErase(&seq, 10);
	SeqListErase(&seq, 4);
	SeqListErase(&seq, 1);
	SeqListPrint(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPrint(&seq);

	SeqListDestroy(&seq);
}

int main()
{
	testSeqList1();
	return 0;
}