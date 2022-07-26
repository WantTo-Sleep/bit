#include <stdio.h>
int main()
{
    int input = 0;
    scanf("%d", &input);
    int output = 0;
    int a = 0;
    int b = 1;
    while (input > 0)
    {
        a = input % 10;
        output += a % 2 * b;
        b *= 10;
        input /= 10;
    }
    printf("%d", output);
    return 0;
}
