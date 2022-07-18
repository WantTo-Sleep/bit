#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int temp = 0;
    int count = 0, sum = 0;
    double ave = 0;
    int i = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if(temp < 0)
            count++;
        else if(temp > 0)
        {
            sum += temp;
            ave++;
        }
    }
    if(ave != 0)
        ave = sum / ave;
    printf("%d %.1lf", count, ave);
    return 0;
}
