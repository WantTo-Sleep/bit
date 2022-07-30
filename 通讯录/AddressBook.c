#include "AddressBook.h"

void InitializeAddressBook(AddressBook* pbook)
{
	assert(pbook);
	memset(pbook, 0, sizeof(AddressBook));
}

void AddPerson(AddressBook* pbook)
{
	assert(pbook);
	if (pbook->count == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}

	//����ӹ��̽Ϸ���������һ�������õĿ�ݴ���
	char str[3] = "1";
	str[0] += pbook->count;
	strcpy((pbook->per)[pbook->count].name, str);
	strcpy((pbook->per)[pbook->count].sex, str);
	(pbook->per)[pbook->count].age = pbook->count + 1;
	strcpy((pbook->per)[pbook->count].tele, str);
	strcpy((pbook->per)[pbook->count].address, str);

	//printf("������������");
	//scanf("%s", (pbook->per)[pbook->count].name);

	//printf("�������Ա�");
	//scanf("%s", (pbook->per)[pbook->count].sex);

	//printf("���������䣺");
	//scanf("%d", &((pbook->per)[pbook->count].age));

	//printf("������绰���룺");
	//scanf("%s", (pbook->per)[pbook->count].tele);

	//printf("������סַ��");
	//scanf("%s", (pbook->per)[pbook->count].address);

	pbook->count++;
}

int FindByName(AddressBook* pbook, char* name)
{
	assert(pbook && name);
	
	for (int i = 0; i < pbook->count; i++)
	{
		if (strcmp(name, (pbook->per)[i].name) == 0)
			return i;
	}
	return -1;
}

void ShowOne(AddressBook* pbook, int i)
{
	assert(pbook);
	if (i < 0 || i >= MAX)
		printf("ͨѶ¼���޴���\n");
	else
	{
		printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	printf("������Ҫɾ�����˵����֣�");
	char str[20] = { 0 };
	scanf("%s", str);
	int i = FindByName(pbook, str);
	if (i == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	else
	{
		for (pbook->count--; i < pbook->count; i++)
		{
			memcpy(&(pbook->per)[i], &(pbook->per)[i + 1], sizeof(Person));
		}
		printf("����ϵ����ɾ��\n");
	}
}

void ShowAll(AddressBook* pbook)
{
	assert(pbook);
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	printf("������Ҫ�޸ĵ���ϵ�˵����֣�");
	char str[20] = { 0 };
	scanf("%s", str);
	int i = FindByName(pbook, str);
	if (i == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
		return;
	}
	else
	{
		ShowOne(pbook, i);
		printf("�������޸ĺ����Ϣ��\n");
		printf("������������");
		scanf("%s", (pbook->per)[i].name);

		printf("�������Ա�");
		scanf("%s", (pbook->per)[i].sex);

		printf("���������䣺");
		scanf("%d", &((pbook->per)[i].age));

		printf("������绰���룺");
		scanf("%s", (pbook->per)[i].tele);

		printf("������סַ��");
		scanf("%s", (pbook->per)[i].address);
		printf("�޸ĳɹ�\n");
	}
}

void DeletAll(AddressBook* pbook)
{
	assert(pbook);

	memset(pbook->per, 0, sizeof(Person) * pbook->count);
	pbook->count = 0;
	printf("ɾ���ɹ�\n");
}

void SortByName(AddressBook* pbook)
{
	assert(pbook);

	qsort(pbook->per, pbook->count, sizeof(Person), CompareByName);
}

int CompareByName(const void* str1, const void* str2)
{
	return strcmp((char*)str2, (char*)str1);
}