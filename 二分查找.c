#include <stdio.h>
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int num = 0;
	printf("��������Ҫ���ҵ����֣�");
	scanf("%d", &num);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (num > arr[mid])
		{
			left = mid + 1;
		}
		else if (num < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			printf("�ҵ��ˣ��±���%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("�Ҳ���\n");
	return 0;
}