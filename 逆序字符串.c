#include <stdio.h>
void reverse_string(char* string)
{
	if (*(string + 1) != '\0')
	{
		int len = 0;
		while (*(string + len) != '\0')
			len++;
		char ch = *(string + len - 1);
		for (len--; len > 0; len--)
			*(string + len) = *(string + len - 1);
		*string = ch;
		reverse_string(string + 1);
	}
}
int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	printf("%s", arr);
	return 0;
}