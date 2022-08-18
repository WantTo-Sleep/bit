#include <stdio.h>
int main()
{
	do
	{
        int num, sum = 0, max = 0, min = 100;
		for (int i = 0; i < 7; i++)
		{
			scanf("%d", &num);
			sum += num;
			if (num > max)
				max = num;
			if (num < min)
				min = num;
		}
		double ave = (sum - max - min) / 5.0;
		printf("%.2lf\n", ave);
        getchar();
	} while (getchar() != EOF);

	return 0;
}
