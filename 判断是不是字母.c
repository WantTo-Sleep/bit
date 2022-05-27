#include <stdio.h>
int main()
{
    char ch = 'a';
    while((ch = getchar()) != EOF)
    {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            printf("%c is an alphabet.\n", ch);
        else
            printf("%c is not an alphabet.\n", ch);
        getchar();
    }
    return 0;
}