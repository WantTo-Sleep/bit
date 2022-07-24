#include <stdio.h>
#include <assert.h>

char* MyStrcpy(char* destination, const char* source)
{
	assert(destination && source);
	char* temp = destination;

	while (*destination++ = *source++);

	return temp;
}
int main()
{
	char str1[] = "abcdef";
	char str2[20];
	
	char*p = MyStrcpy(str2, str1);
	
	printf("%s\n%s\n", str2, p);
	return 0;
}