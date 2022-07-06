#include <stdio.h>

void Triangle(int a, int b, int c)
{
    if (a + b <= c)
    {
        printf("Not a triangle!\n");
    }
    else if (a == b && a == c)
    {
        printf("Equilateral triangle!\n");
    }
    else if (a == b || a == c || b == c)
    {
        printf("Isosceles triangle!\n");
    }
    else
    {
        printf("Ordinary triangle!\n");
    }
}

int main()
{
    int a = 0, b = 0, c = 0;
    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        int temp = a;
        if (a > b)
        {
            a = b;
            b = temp;
        }
        if (a > c)
        {
            temp = a;
            a = c;
            c = temp;
        }
        if (b > c)
        {
            temp = b;
            b = c;
            c = temp;
        }
        Triangle(a, b, c);
        getchar();
    }
    return 0;
}
