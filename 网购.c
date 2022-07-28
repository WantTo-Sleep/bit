#include <stdio.h>
int main()
{
    double price = 0;
    int month, day, flag;
    scanf("%lf %d %d %d", &price, &month, &day, &flag);
	
    double money = price;
    if(month == 11 && day == 11)
        money *= 0.7;
    else if(month == 12 && day == 12)
        money *= 0.8;
    money -= flag * 50;
	
    if(money < 0)
        money = 0;
    printf("%.2lf", money);
    return 0;
}

