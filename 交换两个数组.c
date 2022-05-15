#include <stdio.h>
int main()
{
	char a[6] = "01234";
	char b[6] = "56789";
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		char temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	printf("%s,%s", a, b);
	return 0;
}