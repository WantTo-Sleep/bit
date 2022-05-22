#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d",&n);
    int i = 0;
    int arr[3] = { 1, 2, 3 };
    for(i = 1; i < n; i++)
    {
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[0] + arr[1];
    }
    printf("%d", arr[0]);
    return 0;
}