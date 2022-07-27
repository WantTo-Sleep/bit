#include <stdio.h>
int main()
{
    int n = 0;
    while(scanf("%d", &n) != EOF)
    {
        int i = 0;
        int j = 0;
        int k = 0;

        for(k = 0; k < n; k++)
        {
            for(i = 0; i + 1 < n - k; i++)
                printf("  ");

            for(j = 0; j + i < n; j++)
                printf("* ");

            printf("\n");
        }
    }

    return 0;
}
 