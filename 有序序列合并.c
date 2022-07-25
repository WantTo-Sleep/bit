#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int* pn = (int*)malloc(n * sizeof(int));
	int* pm = (int*)malloc(m * sizeof(int));
	int* p = (int*)malloc((m + n) * sizeof(int));

	if (pn == NULL || pm == NULL || p == NULL)
	{
		return 1;
	}
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", pn + i);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", pm + i);
	}
	int j, k;
	for (i = 0, j = 0, k = 0; k < m + n; k++)
	{
		if (i == n)
		{
			for (; j < m; j++, k++)
			{
				*(p + k) = *(pm + j);
			}
			break;
		}
		else if (j == m)
		{
			for (; i < n; i++, k++)
			{
				*(p + k) = *(pn + i);
			}
			break;
		}
		if (*(pn + i) < *(pm + j))
		{
			*(p + k) = *(pn + i);
			i++;
		}
		else
		{
			*(p + k) = *(pm + j);
			j++;
		}
	}
	free(pn);
	free(pm);
	pn = NULL;
	pm = NULL;
	for (i = 0; i < m + n; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;
	return 0;
}