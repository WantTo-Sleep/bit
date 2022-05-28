#include <stdio.h>
int main()
{
    int chinese = 0;
    int math = 0;
    int english = 0;
    scanf("%d%d%d", &chinese, &math, &english);
    if(chinese < math)
        chinese = math;
    if(chinese < english)
        chinese = english;
    printf("%d\n", chinese);
    return 0;
}
