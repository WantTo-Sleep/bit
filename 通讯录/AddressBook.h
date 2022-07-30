#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 10
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

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
	Person per[MAX];
	int count;
}AddressBook;

//初始化通讯录
void InitializeAddressBook(AddressBook* pbook);
//添加联系人信息
void AddPerson(AddressBook* pbook);
//查找指定联系人信息
int FindByName(AddressBook* pbook, char* name);
//显示某一个人的信息
void ShowOne(AddressBook* pbook, int i);
//删除指定联系人信息
void DeletByName(AddressBook* pbook);
//显示所有联系人信息
void ShowAll(AddressBook* pbook);
//修改指定联系人信息
void ReviseOne(AddressBook* pbook);
//清空所有联系人
void DeletAll(AddressBook* pbook);
//以名字排序所有联系人
void SortByName(AddressBook* pbook);
int CompareByName(const void* str1, const void* str2);