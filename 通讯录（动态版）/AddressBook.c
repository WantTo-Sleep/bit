#include "AddressBook.h"

void InitializeAddressBook(AddressBook* pbook)
{
	assert(pbook);
	Person* temp = (Person*)calloc(INITIAL_CAP, sizeof(Person));
	if (temp == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	pbook->per = temp;
	pbook->capacity = INITIAL_CAP;
	pbook->count = 0;
}

void CheckCapacity(AddressBook* pbook)
{
	if (pbook->capacity == pbook->count)
	{
		Person* temp = (Person*)realloc(pbook->per, sizeof(Person) * (pbook->capacity + INCREASE_CAP));
		if (temp == NULL)
		{
			printf("Increase capacity: %s", strerror(errno));
			return;
		}
		else
		{
			pbook->per = temp;
			pbook->capacity += INCREASE_CAP;
			printf("扩容成功\n");
		}
	}
}

void AddPerson(AddressBook* pbook)
{
	assert(pbook);
	CheckCapacity(pbook);

	//因添加过程较繁琐，这是一个测试用的快捷代码
	char str[3] = "1";
	str[0] += pbook->count;
	strcpy((pbook->per)[pbook->count].name, str);
	strcpy((pbook->per)[pbook->count].sex, str);
	(pbook->per)[pbook->count].age = pbook->count + 1;
	strcpy((pbook->per)[pbook->count].tele, str);
	strcpy((pbook->per)[pbook->count].address, str);

	//printf("请输入姓名：");
	//scanf("%s", (pbook->per)[pbook->count].name);

	//printf("请输入性别：");
	//scanf("%s", (pbook->per)[pbook->count].sex);

	//printf("请输入年龄：");
	//scanf("%d", &((pbook->per)[pbook->count].age));

	//printf("请输入电话号码：");
	//scanf("%s", (pbook->per)[pbook->count].tele);

	//printf("请输入住址：");
	//scanf("%s", (pbook->per)[pbook->count].address);

	pbook->count++;
}

static int FindByName(AddressBook* pbook, char* name)
{
	assert(pbook && name);
	
	for (int i = 0; i < pbook->count; i++)
	{
		if (strcmp(name, (pbook->per)[i].name) == 0)
			return i;
	}
	return -1;
}

void SearchPerson(AddressBook* pbook)
{
	assert(pbook);
	char str[20] = { 0 };
	printf("请输入要查找人的名字：");
	scanf("%s", str);
	ShowOne(pbook, FindByName(pbook, str));
}

void ShowOne(AddressBook* pbook, int i)
{
	assert(pbook);
	if (i < 0 || i >= pbook->count)
		printf("通讯录中无此人\n");
	else
	{
		printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%20s\t%5s\t%5d\t%12s\t%30s\n",  (pbook->per)[i].name,
												(pbook->per)[i].sex,
												(pbook->per)[i].age,
												(pbook->per)[i].tele,
												(pbook->per)[i].address);
	}
		
}

void DeletByName(AddressBook* pbook)
{
	assert(pbook);
	printf("请输入要删除的人的名字：");
	char str[20] = { 0 };
	scanf("%s", str);
	int i = FindByName(pbook, str);
	if (i == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	else
	{
		for (pbook->count--; i < pbook->count; i++)
		{
			memcpy(&(pbook->per)[i], &(pbook->per)[i + 1], sizeof(Person));
		}
		printf("该联系人已删除\n");
	}
}

void ShowAll(AddressBook* pbook)
{
	assert(pbook);
	if (pbook->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < pbook->count; i++)
	{
		printf("%20s\t%5s\t%5d\t%12s\t%30s\n",  (pbook->per)[i].name,
												(pbook->per)[i].sex,
												(pbook->per)[i].age,
												(pbook->per)[i].tele,
												(pbook->per)[i].address);
	}
}

void ReviseOne(AddressBook* pbook)
{
	assert(pbook);
	printf("请输入要修改的联系人的名字：");
	char str[20] = { 0 };
	scanf("%s", str);
	int i = FindByName(pbook, str);
	if (i == -1)
	{
		printf("要修改的联系人不存在\n");
		return;
	}
	else
	{
		ShowOne(pbook, i);
		printf("请输入修改后的信息：\n");
		printf("请输入姓名：");
		scanf("%s", (pbook->per)[i].name);

		printf("请输入性别：");
		scanf("%s", (pbook->per)[i].sex);

		printf("请输入年龄：");
		scanf("%d", &((pbook->per)[i].age));

		printf("请输入电话号码：");
		scanf("%s", (pbook->per)[i].tele);

		printf("请输入住址：");
		scanf("%s", (pbook->per)[i].address);
		printf("修改成功\n");
	}
}

void DeletAll(AddressBook* pbook)
{
	assert(pbook);

	free(pbook->per);
	pbook->per = NULL;
	pbook->count = 0;
	printf("删除成功\n");
}

void SortByName(AddressBook* pbook)
{
	assert(pbook);

	qsort(pbook->per, pbook->count, sizeof(Person), CompareByName);
}

int CompareByName(const void* str1, const void* str2)
{
	return strcmp(((Person*)str2)->name, ((Person*)str1)->name);
}