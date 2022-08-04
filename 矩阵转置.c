#include <stdio.h>
//¾ØÕó×ªÖÃ
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[10][10] = { 0 };
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
	return 0;
}
