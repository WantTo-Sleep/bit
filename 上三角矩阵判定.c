#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[10][10] = { 0 };
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int flag = 1;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i][j] != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
