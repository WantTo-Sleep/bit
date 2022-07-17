#include <stdio.h>

int* Cornichers(int m)
{
    int num = m * m * m;
    int i = 0;
    int j = 1;
    int n = j;
    int sum = 0;
    static int arr[100] = { 0 };
    while(1)
    {
        for(i = 0; i < m; i++, j += 2)
        {
            arr[i] = j;
            sum += j;
        }
        if(sum == num)
            return arr;
        n += 2;
        j = n;
        sum = 0;
    }
}

int main()
{
    int m = 0;
    scanf("%d", &m);
    int* str = Cornichers(m);
    int i = 0;
    for(i = 0; i + 1 < m; i++)
    {
        printf("%d+", str[i]);
    }
    printf("%d\n", str[i]);
    return 0;
}
