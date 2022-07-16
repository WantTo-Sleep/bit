#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0;
    int a = 0;
    int i = 0;
    for(a = 2; i < n; i++, a += 3)
    {
        sum += a;
    }
    printf("%d", sum);
    return 0;
}
