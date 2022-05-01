#include <stdio.h>
int StrlenRec(char* p)
{
	if (*p == '\0')
		return 0;
	else
		return 1 + StrlenRec(p + 1);
}
int StrlenNonRec(char* p)
{
	int i = 0;
	while (1)
	{
		if (*p == '\0')
			break;
		i++;
		p++;
	}
	return i;
}
int main()
{
	char arr[20] = { 0 };
	gets(arr);
	int len_rec = StrlenRec(arr);
	int len_non_rec = StrlenNonRec(arr);
	printf("%d %d", len_rec, len_non_rec);
	return 0;
}