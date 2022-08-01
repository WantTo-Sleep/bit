#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define INITIAL_CAP 3
#define INCREASE_CAP 2

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

typedef struct Person
{
	char name[20];
	char sex[5];
	int age;
	char tele[12];
	char address[30];
}Person;

typedef struct AddressBook
{
	Person *per;
	int count;
	int capacity;
}AddressBook;

//��ʼ��ͨѶ¼
void InitializeAddressBook(AddressBook* pbook);
//�����ϵ����Ϣ
void AddPerson(AddressBook* pbook);
//�������������
void CheckCapacity(AddressBook* pbook);
//����ָ����ϵ����Ϣ
void SearchPerson(AddressBook* pbook);
//��ʾĳһ���˵���Ϣ
void ShowOne(AddressBook* pbook, int i);
//ɾ��ָ����ϵ����Ϣ
void DeletByName(AddressBook* pbook);
//��ʾ������ϵ����Ϣ
void ShowAll(AddressBook* pbook);
//�޸�ָ����ϵ����Ϣ
void ReviseOne(AddressBook* pbook);
//���������ϵ��
void DeletAll(AddressBook* pbook);
//����������������ϵ��
void SortByName(AddressBook* pbook);
int CompareByName(const void* str1, const void* str2);