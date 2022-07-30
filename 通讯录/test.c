#include "AddressBook.h"

void menu()
{
	printf("-------------------------------\n");
	printf("-----1.add          2.delet----\n");
	printf("-----3.find         4.revise---\n");
	printf("-----5.show         6.empty----\n");
	printf("-----7.sort_by_name 0.exit-----\n");
	printf("-------------------------------\n");
}

int main()
{
	AddressBook book;
	InitializeAddressBook(&book);
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:AddPerson(&book);
			break;
		case 2:DeletByName(&book);
			break;
		case 3:
		{
			char str[20] = { 0 };
			printf("请输入要查找人的名字：");
			scanf("%s", str);
			ShowOne(&book, FindByName(&book, str));
		}
			break;
		case 4:ReviseOne(&book);
			break;
		case 5:ShowAll(&book);
			break;
		case 6:DeletAll(&book);
			break;
		case 7:SortByName(&book);
			break;
		case 0:printf("程序退出\n");
			break;
		default:printf("输入错误！\n");
			break;
		}
	} while (input);
	
	return 0;
}