#include <stdio.h>
int LilyNumber(int i)
{
    if (i >= 0 && i <= 9)
        return 1;
    int n = 1;
    int sum = 0;
    while (i >= 10 * n)
    {
        sum += (i % (n * 10)) * (i / (n * 10));
        n *= 10;
    }
    if (sum == i)
        return 1;
    else
        return 0;
}
int main()
{
    int n = 100000;
    int i = 0;
    for (i = 10000; i < n; i++)
    {
        if (LilyNumber(i) == 1)
            printf("%d ", i);
    }
    return 0;
}