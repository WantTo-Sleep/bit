#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	while (i < 10)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	int max = arr[0];
	for (i = 0; i < 10; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d", max);
	return 0;
}