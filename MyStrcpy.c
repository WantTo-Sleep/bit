#include <stdio.h>
#include <assert.h>

char* MyStrcpy(char* dest, const char* sour)
{
	char* temp = dest;
	assert(dest != NULL);
	assert(sour != NULL);

	while (*sour)
	{
		*dest = *sour;
		dest++;
		sour++;
	}
	*dest = *sour;
	return temp;
}

int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "Hello World!";

	char* p = MyStrcpy(arr1, arr2);
	
	printf("%s\n", arr1);
	printf("%s\n", p);

	return 0;
}