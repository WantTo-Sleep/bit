#include <stdio.h>
#include <assert.h>

int MyStrlen(const char* const p)
{
	assert(p);
	int i = 0;
	while (*(p + i))
	{
		i++;
	}
	return i;
}

int main()
{
	char arr[] = "abcdef";

	int i = MyStrlen(arr);

	printf("%d", i);
	return 0;
}