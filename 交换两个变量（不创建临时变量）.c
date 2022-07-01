#include <stdio.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("交换前：a = %d, b = %d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("交换后：a = %d, b = %d\n", a, b);
}
