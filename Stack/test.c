#include "Stack.h"

void TestStack()
{
	Stack st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	printf("%d\n", StackSize(&st));

	for (int i = 0; i < 3; ++i)
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d ", StackTop(&st));
	//	StackPop(&st);
	//}
	//printf("\n");

	StackDestroy(&st);

}

int main()
{
	TestStack();
	return 0;
}