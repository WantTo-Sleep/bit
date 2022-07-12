#include <stdio.h>
int main()
{
    int a = 0;
    while (scanf("%d", &a) != EOF)
    {
        char arr[20][20] = { 0 };
        int i = 0;
        int j = 0;
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                arr[i][j] = ' ';
            }
        }
        for (i = 0, j = 0; i < a; i++, j++)
        {
            arr[i][j] = '*';
        }
        for (i = 0, j = a - 1; i < a; i++, j--)
        {
            arr[i][j] = '*';
        }
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < a; j++)
            {
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
