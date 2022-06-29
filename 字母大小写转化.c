#include <stdio.h>
int main()
{
    char ch = 0;
    while((ch = getchar()) != EOF)
    {
        if(ch >= 'a' && ch <= 'z')
            printf("%c\n", ch - 'a' + 'A');
        else if(ch >= 'A' && ch <= 'Z')
            printf("%c\n", ch - 'A' + 'a');
        getchar();
    }
    return 0;
}