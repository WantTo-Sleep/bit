#include <stdio.h>
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("����ǰ��a = %d��b = %d\n", a, b);
	Swap(&a, &b);
	printf("������a = %d��b = %d\n", a, b);
	return 0;
}