#include <stdio.h>

int main()
{
    int n = 0;
    char arr[20][20] = { 0 };
    while (EOF != scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 || j == 0 || i == (n - 1) || j == (n - 1))
                    arr[i][j] = '*';
                else
                    arr[i][j] = ' ';
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                printf("%c ", arr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}