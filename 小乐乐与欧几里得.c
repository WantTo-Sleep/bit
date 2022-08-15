#include <stdio.h>

int main()
{
	unsigned long long a, b, div, mul;
	scanf("%llu %llu", &a, &b);
	// 15 / 5 = 3 ... 0
	// 48 / 40= 1 ... 8
	// 40 / 8 = 5 ... 0
	//辗转相除法求最大公约数
	unsigned long long tempa = a, tempb = b;
	while (div = tempa % tempb)
	{
		tempa = tempb;
		tempb = div;
	}
	div = tempb;
	mul = a / div * b;
	printf("%llu", div + mul);
	return 0;
}