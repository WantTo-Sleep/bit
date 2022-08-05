#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N = 0;
    scanf("%d", &N);
    int* p = (int*)malloc(N * sizeof(int));
    if (p == NULL)
        return 1;
    int i = 0;
    for (i = 0; i < N; i++)
        scanf("%d", p + i);
    int flag = 2;
    for (i = 0; i + 1 < N; i++)
    {
        if (*(p + i) > *(p + i + 1))
        {
            flag--;
            break;
        }
    }
    for (i = 0; i + 1 < N; i++)
    {
        if (*(p + i) < *(p + i + 1))
        {
            flag--;
            break;
        }
    }
    if (flag == 0)
        printf("unsorted\n");
    else
        printf("sorted\n");
	free(p);
	p = NULL;
    return 0;
}
