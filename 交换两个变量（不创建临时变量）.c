#include <stdio.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("����ǰ��a = %d, b = %d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("������a = %d, b = %d\n", a, b);
}
