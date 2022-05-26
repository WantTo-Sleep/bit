#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[2] = { 0 };
	if (n == 1)
	{
		scanf("%d", &arr[0]);
		printf("0");
	}
	else
	{
		scanf("%d%d", &arr[0], &arr[1]);
		int temp = 0;
		if (arr[0] > arr[1])
		{
			temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
		int i = 2;
		while (i < n)
		{
			i++;
			scanf("%d", &temp);
			if (temp < arr[0])
				arr[0] = temp;
			else if (temp > arr[1])
				arr[1] = temp;
		}
		printf("%d", arr[1] - arr[0]);
	}
	
	return 0;
}