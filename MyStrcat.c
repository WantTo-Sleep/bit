#include <stdio.h>
#include <assert.h>

char* MyStrcat(char* destination, const char* source)
{
	assert(destination && source);
	char* temp = destination;
	while (*destination)
	{
		destination++;
	}
	while (*destination++ = *source++);

	return temp;
}

int main()
{
	char str1[20] = "abcdefg";
	printf("str1:%s\n", str1);

	char str2[20] = "higklmn";
	printf("str2:%s\n", str2);

	char* p = MyStrcat(str1, str2);
	printf("p:%s\n", p);
	printf("str1:%s\n", str1);

	return 0;
}