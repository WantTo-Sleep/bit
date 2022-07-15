#include <stdio.h>

int DateToDay(int year, int month, int day)
{
    int sum = 0;
    switch(month)
    {
        case 12: sum += 30;
        case 11: sum += 31;
        case 10: sum += 30;
        case 9: sum += 31;
        case 8: sum += 31;
        case 7: sum += 30;
        case 6: sum += 31;
        case 5: sum += 30;
        case 4: sum += 31;
        case 3: 
            if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                sum += 29;
            else
                sum += 28;
        case 2: sum += 31;
        case 1: sum += day;
    }
    return sum;
}

int main()
{
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    
    printf("%d", DateToDay(year, month, day));
    return 0;
}
