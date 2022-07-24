#include <stdio.h>
#include <assert.h>

size_t MyStrlen(const char* str)
{
	assert(str);
	int len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return len;
}

int main()
{
	char str[10] = "abcdef";
	int len = MyStrlen(str);
	printf("%d\n", len);
	return 0;
}