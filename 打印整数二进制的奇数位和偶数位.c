#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("�Ը�λΪ����λ\n");
	int i = 0;
	printf("%d�Ķ���������λ��", a);
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}
	printf("\n%d�Ķ�����ż��λ��", a);
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}
	return 0;
}
