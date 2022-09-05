#include "SList.h"

void Test1()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);

	SListPushBack(&plist, 3);
	SListPushBack(&plist, 5);
	SListPrint(plist);
	SListEraseAfter(SListFind(plist, 5));
	SListPrint(plist);
	SListInsertAfter(SListFind(plist, 1),0);
	SListInsertAfter(SListFind(plist, 5), 4);
	SListInsertAfter(SListFind(plist, 4), 3);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListDestroy(plist);
}

int main()
{
	Test1();
	return 0;
}