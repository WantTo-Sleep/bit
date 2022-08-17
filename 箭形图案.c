#include <stdio.h>
int main()
{
    int n = 0;
    while (EOF != scanf("%d", &n))
    {
        //打印上半部分 + 中间一行
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < 2 * (n - i); j++)
                printf(" ");
            for (int j = 0; j <= i; j++)
                printf("*");
            printf("\n");
        }
        //打印下半部分
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2 * (n - i); j++)
                printf(" ");
            for (int j = 0; j <= i; j++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}