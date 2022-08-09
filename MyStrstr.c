#include <stdio.h>
#include <assert.h>
const char* MyStrstr(const char* str1, const char* str2)
{
	assert(str1 && str2);

	//如果str1找到了末尾，就结束循环
	while (*str1)
	{   //找到第一对匹配的字符
		while (*str1 != *str2 && *str1 != '\0')
			str1++;
		
		int i = 0;
		//这时候出现了第一对相等的字符，继续往下匹配
		while (*(str1 + i))
		{
			//因为第一对字符已经匹配过相等，所以i可以先++
			i++;
			//匹配过程中如果str2遇到了'\0'，证明str1中有str2的内容
			if (*(str2 + i) == '\0')
				return str1;
			//如果在'\0'之前匹配到不相等的，就进行下一次的匹配
			if (*(str1 + i) != *(str2 + i))
				break;
		}
		//如果str1 + i 是'\0'，意味着str1中已经不可能包含str2了
		if (*(str1 + i))
			str1++;
		else
			return NULL;
	}
	if (*str2 == '\0')
		return str1;
	else
		return NULL;
}
int main()
{
	char* arr1[] = { "zhangsan","lisssiaaa","\0","wang","wangwu" };
	char* arr2[] = { "gsa","si","\0","wang","www" };
	int i = 0;
	while (i < 5)
	{
		char* ret = MyStrstr(arr1[i], arr2[i]);
		if (ret == NULL)
			printf("%s 中找不到 %s\n", arr1[i], arr2[i]);
		else
			printf("%s\n", ret);
		i++;
	}
	return 0;
}