#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("以个位为奇数位\n");
	int i = 0;
	printf("%d的二进制奇数位：", a);
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}
	printf("\n%d的二进制偶数位：", a);
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}
	return 0;
}
