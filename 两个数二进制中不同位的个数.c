#include <stdio.h>
int main()
{
    int m, n, i;
    scanf("%d%d",&m,&n);
    int count = 0;
    for(i = 0; i < 32; ++i)
    {
        if(((m >> i) & 1) != ((n >> i) & 1))
            count++;
    }
    printf("%d",count);
    return 0;
}
