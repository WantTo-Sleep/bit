#include <stdio.h>

int a = 10;
int main()
{
	int a = 1;
	//局部变量优先于全局变量，但是这种代码很垃圾
	printf("a = %d", a);
	return 0;
}