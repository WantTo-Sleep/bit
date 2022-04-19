#include <stdio.h>
int main()
{
	int i = 0;
	int flg = 1;
	double num = 0;
	for (i = 1; i <= 100; i++)
	{
		num = num + flg * 1.0 / i;
		flg = -flg;
	}
	printf("%lf", num);
	return 0;
}